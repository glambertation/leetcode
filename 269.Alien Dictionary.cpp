https://www.cnblogs.com/grandyang/p/5250200.html

这些就是有向图的边，对于有向图中的每个结点，计算其入度，然后从入度为0的结点开始BFS遍历这个有向图，然后将遍历路径保存下来返回即可。下面来看具体的做法：

根据之前讲解，需用TreeSet来保存这些pair，我们还需要一个HashSet来保存所有出现过的字母，需要一个一维数组in来保存每个字母的入度，另外还要一个queue来辅助拓扑遍历，我们先遍历单词集，把所有字母先存入HashSet，然后我们每两个相邻的单词比较，找出顺序pair，然后我们根据这些pair来赋度，我们把HashSet中入度为0的字母都排入queue中，然后开始遍历，如果字母在TreeSet中存在，则将其pair中对应的字母的入度减1，若此时入度减为0了，则将对应的字母排入queue中并且加入结果res中，直到遍历完成，我们看结果res和ch中的元素个数是否相同，若不相同则说明可能有环存在，返回空字符串，参见代码如下：

string alienOrder(vector<string> &words) {
    unordered_map<char, unordered_set<char>> mp;
    unordered_map<char, int> idx;
    unordered_set<char> st;
    queue<char> q;
    
    string ans = "";
    
    for(auto word : words){
        // 字符串自己与自己比较
        st.insert(word.begin(), word.end())
    }
    
    for(int i=0; i<words.size()-1; ++i){
        // 比较两个字符串首字母
        int j=0, end=min(words[i].size(), words[i+1].size());
        for(; j<end; ++j){
            if(words[i][j] == words[i+1][j]) continue;
            mp[words[i][j]].insert(words[i+1][j]);
            break;
        }
        
        // 回路返回空字符串
        if(j==end && words[i].size()>words[i+1].size())
            return ans;
    }
    
    // key = mp 里每个字母后 跟着的字符串，idx++
    for(auto m: mp){
        for(auto s : m.second){
            idx[s]++;
        }
    }
    
    // 每个word 如果idx里面没有 放到queue里面，ans上拼接
    for(auto s :st){
        if(!idx.count(s)){
            q.push(s);
            ans += s;
        }
        
    }
    
    // queue 先进先出
    while(!q.empty()){
        char c = q.front();
        p.pop();
        // next 是mp里面c后面拼接的字母
        auto next = mp[c];
        for(auto s: next){
            if(--idx[s] == 0){
                q.push(s);
                ans += s;
            }
        }
        
    }
    
    return ans.size() == st.size() ? ans : "";
    
}
