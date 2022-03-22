class Solution {
public:
    int longestMountain(vector<int>& arr) {        
        int len = arr.size();        
        if(len < 3)
        {
            return 0;
        }        
        int max_len = 0;
        int i = 1;
        while(i < len-1)
        {
            // this is a mountain peak
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            {
                int low = i-1, high = i+1;                
                while(low >= 0 && arr[low] < arr[low+1])
                {
                    low--;
                }                            
                while(high < len && arr[high] < arr[high-1])
                {
                    high++;
                }                            
                max_len = max(max_len, high-low-1);
                i = high;
            }
            else
            {
                i++;
            }                        
        }        
        return max_len;        
    }

};