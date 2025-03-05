class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max_area=0;
        while(left<right){
            int h=(height[left]<height[right])?height[left]:height[right];
            int width=right-left;
            int area=width*h;
            if(area>max_area){
                max_area=area;
            }
            if(height[left]<height[right])
            left++;
            else
            right--;
        }
        return max_area;
        
    }
};