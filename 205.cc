class Solution {
	public:
		bool hasMapped(map<char, char>& mymap, char t) {
			map<char, char>::iterator ite = mymap.begin();
			while (ite != mymap.end()) {
				if (ite->second == t) return true;
				ite++;
			}
			return false;
		}

		bool isIsomorphic(string s, string t) {
			map<char, char> mymap;
			for (int i = 0; i < s.length(); i++) {
				map<char, char>::iterator ite = mymap.find(s[i]);
				if (ite != mymap.end()) {
					if (ite->second != t[i]) return false;
				} else if (hasMapped(mymap, t[i])) return false;
				else mymap.insert(pair<char, char>(s[i], t[i]));
			}
			return true;
		}
};
