import "sort"

func combinationSum2(candidates []int, target int) [][]int {
    var result [][]int
    if len(candidates) == 0 {
        return result
    }
    sort.Ints(candidates)
    temp := []int{}
    dfs(candidates, temp, &result, target, -1)
    return result
}

func dfs(candidates []int, temp []int, result *[][]int, target int, last int) {
    
    if target < 0 {
        return 
    }
    
    if target == 0 {
        r := append([]int{}, temp... )
        *result = append(*result, r)
        return 
    }
    
    for i := last+1; i<len(candidates); i++ {
        if i != last+1 && candidates[i] == candidates[i-1] {
            continue
        }
        t := append(temp, candidates[i])
        dfs(candidates, t, result, target-candidates[i], i)
    }
    
}
