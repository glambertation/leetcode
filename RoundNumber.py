```
Total price = base price + service fee + cleaning fee + …

input : array of decimals ~ X
output : array of int ~ Y
But they need to satisfy the condition:

    sum(Y) = round(sum(x))
    minmize (|y1-x1| + |y2-x2| + ... + |yn-xn|)
    Example1:
        input = 30.3, 2.4, 3.5
        output = 30 2 4

    Example2:
        input = 30.9, 2.4, 3.9
        output = 31 2 4
        先将所有floor(x)加起来统计出如果所有都floor的话还差多少，按照ceil以后需要加的价格排序，贪心取最小的补齐即可。
```


import math
def roundNum( input):
    output = map(lambda x: math.floor(x), input)
    remain = int(round(sum(input) - sum(output)))
    # enumerate同时列出数据和数据下标
    # ig it = [(0, 30.3), (1, 2.4), (2, 3.5)] 
    it = sorted(enumerate(input), key=lambda x:x[1] - math.floor(x[1]))
    for _ in xrange(remain):
        output[it.pop()[0]] += 1
    return output

if __name__ == '__main__':
    input = [30.3, 2.4, 3.5]
    a = roundNum(input)
