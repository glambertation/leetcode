```
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
```


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> chs;
        vector<vector<int>> result;
        if(target == 0) return result;
        sort(candidates.begin(), candidates.end());
        int used[candidates.size()] = {0};
        DFS(0,-1,target,chs,candidates,used,result);
        return result;
    }
    
    void DFS(int now, int p, int target, vector<int> chs, vector<int>& cans, int* used, vector<vector<int>>& result){
        if(now == target){
            result.push_back(chs);
            return ;
        } 
        for(int i=p+1; i<cans.size(); i++){
            if(now+cans[i]>target) return;
        if(i && cans[i]==cans[i-1] && !used[i-1]) continue;
        used[i] = 1;
        chs.push_back(cans[i]);
        DFS(now+cans[i], i, target, chs, cans, used, result);
        used[i]=0;
        chs.pop_back();
        }
        
    }
};
