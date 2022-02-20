class myCompare {
public:
     bool operator()(const vector<int>& v1,const vector<int>& v2) {
        if(v1[0] != v2[0])
            return v1[0] < v2[0];
        else
            return v1[1] > v2[1];
    }
};
class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<int> last;
        sort(intervals.begin(), intervals.end(),myCompare());

        int n = intervals.size();
        int count = n;
        for(int i = 0; i < n; i++) {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<"\n";
        }
        last = intervals[0];
        for(int i = 1; i < n; i++) {
            if(last[0] <= intervals[i][0] && last[1] >= intervals[i][1]) {
                count--;
                //last = last;
            }
            else {
                last = intervals[i];
            }
        }
        return count;
    }
};