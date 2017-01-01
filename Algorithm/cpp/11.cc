class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max = 0;
        while(left < right) {
            int area = (right - left) * (height[left] < height[right] ? height[left++] : height[right--]);
            max = max > area ? max : area;
        }
        return max;
    }
};

// Time Limit Exceeded
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if (size < 2) return 0;
        int max = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                int tmp = (j - i) * min(height[i], height[j]);
                max = tmp > max ? tmp : max;
            }
        }
        return max;
    }
};