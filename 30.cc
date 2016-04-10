class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			vector<int> res;
			if(words.empty()) return res;
			int wordLen = words[0].size();
			int minLen = words.size() * wordLen;
			if(s.size() < minLen) return res;
			unordered_map<string, int> table, originTable;
			for(string &word : words) ++originTable[word];
			bool approve;
			for(int i = 0; i <= s.size() - minLen; i++){
				table = originTable;
				approve = true;
				for(int j = 0; j < minLen; j += wordLen){
					string cur = s.substr(i + j, wordLen);
					if(table.find(cur) == table.end() || table[cur] == 0){
						approve = false;
						break;
					}
					else table[cur]--;
				}
				if(approve) res.push_back(i);
			}
			return res;
		}
};

// Time Limit Exceeded
class Solution {
	public:
		bool isConcat(string s, vector<string>& words) {
			string str;
			for (vector<string>::iterator ite = words.begin(); ite != words.end(); ite++)
				str.append(*ite);
			sort(str.begin(), str.end());
			sort(s.begin(), s.end());
			return str.compare(s) == 0;
		}

		vector<int> findSubstring(string s, vector<string>& words) {
			int length = words.size() * words[0].length();
			vector<int> res;
			if (s.length() < length) return res;
			for (int i = 0; i <= s.length() - length; i++)
				if (isConcat(s.substr(i, length), words)) res.push_back(i);
			return res;
		}
};
