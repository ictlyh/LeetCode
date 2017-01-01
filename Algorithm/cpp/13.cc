class Solution {
	public:
		int romanToInt(string s) {
			unordered_map<char, int> mymap;
			mymap['I']=1;
			mymap['V']=5;
			mymap['X']=10;
			mymap['L']=50;
			mymap['C']=100;
			mymap['D']=500;
			mymap['M']=1000;  
			char a,b;
			int val = 0;
			for (int i = 0; i < s.size(); i++){
				a = s[i];
				if (i + 1 < s.size()) b = s[i + 1];
				else b = 'I';
				if (mymap[a] >= mymap[b]) val += mymap[a];
				else val -= mymap[a];
			}
			return val;
		}
};
