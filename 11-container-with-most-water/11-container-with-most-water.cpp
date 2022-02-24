class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maximumArea = 0;
        while(i < j) {
            int width = (j-i);
            int length;
            if(height[i] > height[j]) {
                length = height[j];
                j--;
            }
            else {
                length = height[i];
                i++;
            }
            maximumArea = max(maximumArea, length*width);
        }
        return maximumArea;
    }
};