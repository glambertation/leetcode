/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    
    var sorted = candidates.sort((a,b) => a - b)
    var ret = []
    backtrace([], sorted, target, ret, 0)
    return ret
};

function backtrace(arr, candidates, target, ret, start){
    var arrsum = arr.reduce((total, num) => total+num, 0)
    for(var i=start; i<candidates.length; i++){
        
        var x = arrsum+candidates[i]
        if(x==target){
            ret.push(arr.concat(candidates[i]))
            
        }
        else if(x<target){
            backtrace(arr.concat(candidates[i]), candidates, target, ret, i+1)
        }
        // var j = candidates[i+1] 
        // console.log("hello")
        // console.log(j)
        // 越界会undefined
        while(candidates[i+1] == candidates[i]) {
            i++
        }
    }
}
