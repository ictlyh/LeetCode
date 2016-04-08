class Solution {
	public:
		vector<string> findRepeatedDnaSequences(string s) {
			vector<string> res;
			if (s.length() <= 10) return res;
			unordered_map<string, bool> represent;
			for (int i = 0; i <= s.length() - 10; i++) {
				string sub = s.substr(i, 10);
				unordered_map<string, bool>::iterator ite = represent.find(sub);
				if (ite == represent.end()) {
					represent[sub] = true;
				} else if (ite->second) {
					res.push_back(sub);
					represent[sub] = false;
				}
			}
			return res;
		}
};
