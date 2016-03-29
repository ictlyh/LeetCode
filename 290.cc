class Solution {
	public:
		vector<string> split(string str) {
			vector<string> res;
			for (int i = 0; i < str.length();) {
				while (str[i] == ' ') i++;
				int j;
				for(j = i + 1; j < str.length() && str[j] != ' '; j++) ;
				res.push_back(str.substr(i, j - i));
				i = j + 1;
			}
			return res;
		}

		bool wordPattern(string pattern, string str) {
			map<char, string> mymap;
			vector<string> strs = split(str);
			if (strs.size() != pattern.size()) return false;
			for (int i = 0; i < pattern.size(); i++) {
				map<char, string>::iterator ite = mymap.find(pattern[i]);
				if (ite != mymap.end()) {
					if (ite->second.compare(strs[i]) != 0) return false;
				} else {
					map<char, string>::iterator tIte = mymap.begin();
					while (tIte != mymap.end()) {
						if (tIte->second.compare(strs[i]) == 0) return false;
						tIte++;
					}
					mymap.insert(pair<char, string>(pattern[i], strs[i]));
				}
			}
			return true;
		}
};
