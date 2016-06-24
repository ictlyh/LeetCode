class Solution {
	public:
		int trap(vector<int>& height) {
			int sz = height.size(), highest=0, water=0;
			//from left to right, only consider the trap's left elevation
			for(int i = 0; i < sz; i++){
				if(height[i] < highest) water += highest - height[i];
				highest = max(highest, height[i]);
			}

			int prehighest=highest;
			highest = 0;
			//from right to left, only consider the trap's right elevation, subtract the surplus water
			for(int i = sz - 1; i >= 0; i--){
				highest = max(height[i], highest);
				if(highest < prehighest) water -= prehighest - highest;
        else break;
			}
			return water;
		}
};
