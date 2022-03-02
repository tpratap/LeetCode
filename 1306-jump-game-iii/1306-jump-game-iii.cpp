class Solution {
public:
     bool Reach(vector<int> &arr, int start, vector<bool> &visited){
        if(start < 0 || start >= arr.size()) return false;
        if(visited[start]) return false;
        if(arr[start] == 0) return true;
        visited[start] = true;
        return Reach(arr, start - arr[start], visited ) || Reach(arr, start + arr[start], visited) ;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size() + 1, false);
        return Reach(arr, start, visited ) ;
    }
};