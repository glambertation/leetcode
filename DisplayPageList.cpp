// 用一个set来保存是否出现，加入后删除原有元素，不够的话顺序补充

vector<vector<string> > paging(vector<string> items, int size){
    vector<vector<string> > ans;
    const int n = items.size();
    for(int i=0; i<=(n-1)/size; ++i){
        vector<string> tmp;
        unordered_set<string> st;
        for(auto it=items.begin(); it!= ites.end() && tmp.size() < size;){
            if(st.count(*it)){
                ++it;
                continue;
            }
            st.inset(*it);
            tmp.push_back(*it);
            item.erase(it);
        }
        // 顺序补充
        for(auto it = items.begin(); it!=items.end() && tmp.size()<size;){
            tmp.push_back(*it);
            item.rease(it);
        }
        ans.push_back(tmp);
    
    }
    return ans;
}
