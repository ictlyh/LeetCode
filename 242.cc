class Solution {
	public:
		map<int, char>::iterator position(map<int, char>& mymap, char value) {
			map<int, char>::iterator ite = mymap.begin();
			while (ite != mymap.end()) {
				if (ite->second == value) return ite;
				ite++;
			}
			return ite;
		}

		bool isAnagram(string s, string t) {
			if (s.length() != t.length()) return false;
			map<int, char> mymap;
			for (int i = 0; i < s.length(); i++)
				mymap.insert(pair<int, char>(i, s[i]));
			for (int i = 0; i < t.length(); i++) {
				map<int, char>::iterator ite = position(mymap, t[i]);
				if (ite == mymap.end()) return false;
				mymap.erase(ite);
			}
			return true;
		}
};
