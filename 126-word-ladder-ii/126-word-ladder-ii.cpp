class Solution {
    vector<string> findNeighbors(string word, unordered_set<string>& wordList)  {
        vector<string> neighbors;
        for(int i = 0; i < word.size(); ++i){
            int s = word[i];
            for(char c = 'a'; c <= 'z'; ++c){
                word[i] = c;
                if(wordList.find(word) != wordList.end())
                    neighbors.push_back(word);
            }
            word[i] = s;
        }
        return neighbors;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_list(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        
        queue<vector<string>> Q;
        Q.push({beginWord});
        bool reached_end = false;
        unordered_set<string> visited;
        
        while(!Q.empty()){
            int n = Q.size();
            for(int i = 0; i < n; ++i){ //Process all the nodes at a given level
                vector<string> path = Q.front(); // running path 
                Q.pop();
                vector<string> neighbors = findNeighbors(path.back(), word_list);
                for(int j = 0; j < neighbors.size(); ++j){
                    vector<string> new_path(path.begin(), path.end());
                    new_path.push_back(neighbors[j]);
                    visited.insert(neighbors[j]);
                    Q.push(new_path);
                    if(neighbors[j] == endWord){
                        result.push_back(new_path);
                        reached_end = true;
                    }
                }
            }
            if(reached_end) break;
            for(auto it = visited.begin(); it != visited.end(); ++it) //Remove all visied nodes, to remove cycle
                word_list.erase(*it);
            visited.clear();
        }
        return result;
    }
};
