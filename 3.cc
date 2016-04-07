class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int l = 0, r = 0, len = 0;
			unordered_map<char, int> window;
			while (r < s.size()){
				if (window.find(s[r]) != window.end())
					l = max(l, window[s[r]] + 1);      //see explain      
				window[s[r]] = r;
				len = max(len, r - l + 1);
				r++;
			}
			return len;
		}
};
