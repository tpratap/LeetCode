class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st (wordList.begin(),wordList.end());
        unordered_set<string> visited;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr_path = q.front();
                q.pop();
                string last = curr_path.back();
                for(int i = 0 ; i < last.size() ; ++i){
                    auto temp = last;
                    for(char ch = 'a' ; ch <= 'z' ; ++ch){
                        temp[i] = ch;
                        if(st.find(temp) != st.end()){
                            auto new_path = curr_path;
                            new_path.push_back(temp);
                            visited.insert(temp);
                            if(temp == endWord)
                                ans.push_back(new_path);
                            else
                                q.push(new_path);
                        }
                    }
                }
            }
            for(auto& str : visited)
                    st.erase(str);
        }
        return ans;
    }
};