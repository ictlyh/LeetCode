class Solution {
	public:
		string minWindow(string s, string t) {

			int hashmap[256] = {0};
			int m = s.size(), n = t.size();

			for (int i = 0; i < n; ++ i) {
				hashmap[t[i]] ++;
			}

			int minLen = -1, len = 0, validLen = 0;
			int start = 0, min_start;

			for (int i = 0; i < m; ++ i) {

				if (hashmap[s[i]] > 0) validLen ++;
				hashmap[s[i]] --;
				len ++;

				while (hashmap[s[start]] < 0) {
					hashmap[s[start]] ++;
					start ++;
					len --;
				}

				if (validLen == n && (len < minLen || minLen == -1)) {
					minLen = len;
					min_start = start;
				}
			}

			if (validLen < n) return "";

			return s.substr(min_start, minLen);
		}
};


// Time Limit Exceeded
class Solution {
	public:
		bool contain(string s, string t) {
			if (s.length() < t.length()) return false;
			unordered_map<char, int> mymap;
			for (int i = 0; i < t.length(); i++) {
				unordered_map<char, int>::iterator ite = mymap.find(t[i]);
				if (ite == mymap.end()) {
					if (s.find(t[i]) == string::npos) return false;
					else mymap[t[i]] = s.find(t[i]);
				} else {
					if (s.find(t[i], ite->second + 1) == string::npos) return false;
					else mymap[t[i]] = s.find(t[i], ite->second + 1);
				}
			}
			return true;
		}

		string minWindow(string s, string t) {
			if (!contain(s, t)) return "";
			string res = s;
			for (int i = 0; i <= s.size() - t.size(); i++) {
				for (int j = i + t.size() - 1; j < s.size(); j++) {
					int length = j - i + 1;
					if (length >= res.length()) break;
					string tmp = s.substr(i, length);
					if (contain(tmp, t)) {
						res = res.size() < length ? res : tmp;
						break;
					}
				}
			}
			return res;
		}
};
