class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<string, vector<string>> mp;
			for(string s : strs){
				string copy = s;
				sort(copy.begin(), copy.end());
				if(mp.find(copy) == mp.end()){
					vector<string> anagram;
					anagram.push_back(s);
					mp[copy] = anagram;
				}else{
					mp[copy].push_back(s);
				}    
			}

			vector<vector<string>> result;
			vector<string> temp;
			unordered_map<string, vector<string>>::iterator it = mp.begin();
			for(; it != mp.end(); it++){
				vector<string>::iterator it2 = it->second.begin();
				for(;it2 != it->second.end(); it2++){
					temp.push_back(*it2);
				}
				sort(temp.begin(), temp.end());
				result.push_back(temp);
				temp.clear();
			}
			return result;   
		}
};
