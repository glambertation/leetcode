class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        dfs(candidates, 0, res, path, target);
        return res;
        
    }
    
    void dfs(int[] cans, int cur, List<List<Integer>> res, List<Integer> path, int target){
        if(target == 0){
            res.add(new ArrayList(path));
            return ;
        }
        if(target <0) return ;
        for(int i=cur; i<cans.length; i++){
            if(i>cur && cans[i]==cans[i-1] ) continue;
            path.add(path.size(), cans[i]);
            dfs(cans, i+1, res, path, target-cans[i] );
            path.remove(path.size()-1);
        }
    }
}
