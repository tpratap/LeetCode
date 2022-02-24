class Solution {
public:
    long long merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        int start1 = left;
        int start2 = mid;
        int end1 = mid-1;
        int end2 = right;
        int start = left; //for the result
        long long inv_count = 0;
        
        while(start1 <= end1 && start2 <= end2) {
            if(nums[start1] <= nums[start2]) {
                temp[start] = nums[start1];
                start++;
                start1++;
            }
            else {
                temp[start] = nums[start2];
                start++;
                start2++;
                inv_count += (mid-start1);
            }
        }
        
        while(start1 <= end1) {
            temp[start] = nums[start1];
            start++;
            start1++;
        }
        
        while(start2 <= end2) {
            temp[start] = nums[start2];
            start++;
            start2++;
        }
        
        for(int i = left; i <= right; i++)  {
            nums[i] = temp[i];
        }
        
        return inv_count;
    }
    
    long long mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        long long inv_count = 0;
        if(left < right) {
            int mid = (left+right)/2;
            inv_count += mergeSort(nums, temp, left, mid);
            inv_count += mergeSort(nums, temp, mid+1, right);
            inv_count += merge(nums, temp, left, mid+1, right);
        }
        return inv_count;
    }
    
    
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        
        long long local_inv = 0;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
               
                local_inv++;
            }
        }
        
        vector<int> temp(n);
        long long global_inv = mergeSort(nums, temp, 0, n-1);
        
        
        
        //cout<<local_inv<<" "<<global_inv<<"\n";
        
        return local_inv == global_inv;
    }
};