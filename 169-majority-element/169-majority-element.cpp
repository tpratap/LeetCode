class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count=0;int majority;
        for(auto i: nums){
            if(count==0) majority=i;
            if(majority==i) count++;
            else count--;
        }
        return majority;
    }
};