class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        int len = pushed.size();
     
    // an empty stack
    stack <int> st;
    for(int i = 0; i < len; i++){
        st.push(pushed[i]);
         
        // check if appended value is next to be popped out
        while (!st.empty() && j < len && st.top() == popped[j]){
            st.pop();
            j++;
        }
    }
     
    return j == len; 
    }
};