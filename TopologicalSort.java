/**
 * 初始化一个int[] inDegree保存每一个结点的入度。
 * 对于图中的每一个结点的子结点，将其子结点的入度加1。
 * 选取入度为0的结点开始遍历，并将该节点加入输出。
 * 对于遍历过的每个结点，更新其子结点的入度：将子结点的入度减1。
 * 重复步骤3，直到遍历完所有的结点。
 * 如果无法遍历完所有的结点，则意味着当前的图不是有向无环图。不存在拓扑排序。
 * */

public class TopolgicalSort {
    /**
     * get topological ordering of the input directed graph
     * @param n number of nodes in the graph
     * @param adjacencyList list representation of the input directed graph
     * @return topological ordering of the graph stored in an List<Integer>
     *
     * */

    public List<Integer> topologicalSort(int n, int[][] adjacencyList) {
        List<Integer> topoRes = new ArrayList<>();
        int[] inDegree = new int[n];
        for (int[] parrent : adjancencyList) {
            for(int child:parent){
                inDegree[child]++;
            }
        }
    }

    Deque<Integer> deque = new ArrayDeque<>();
    for (int i=0; i<n; i++){
        if (inDegree[i] == 0) deque.offer(i);
    }

    while (!deque.isEmpty()) {
        int curr = deque.poll();
        topoRes.add(curr);
        for (int child : adjacencyList[curr]) {
            inDegree[child]--;
            if (inDegree[child] == 0) {
                deque.offer(child);
            }
        }
    }

    return topoRes.size() == n ？topoRes : new ArrayList<>();
}
