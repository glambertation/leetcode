# http://www.ipaddressguide.com/cidr

import math
def ipToVal(ip):
    ip = ip.split(".")
    val = 0
    for x in ip:
        val = (val << 8) + int(x)
    return val

def ValToIp(val):
    ip, i = ["0"] * 4, 3
    while val:
        ip[i] = str(val % (1<<8))
        val /= (1<<8)
        i -= 1
    return ".".join(ip)

def range2cidr(start, end):
    if not start  or not end or start.count('.') != 3 or end.count('.') != 3:
        return None
    start, end = ipToVal(start), ipToVal(end)
    if start > end:
        return None
    ans = []
    while start <= end:
        firstOne = start & (-start)
        maxMask = 32 - int(math.log(firstOne, 2))
        maxDiff = 31 - int(math.log(end - start+1 , 2))
        maxMask = max(maxMask, maxDiff)
        ip = ValToIp(start)
        ans.append(ip + "/" + str(maxMask))
        start += 2 ** (32 - maxMask)
    return ans

if __name__ == '__main__':
    start = '10.0.1.24'
    end = '10.0.1.225'
    a = range2cidr(start, end)
    print a
