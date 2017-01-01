class Solution {
  public:
    bool isAnagram(string s, string t) {
      int counts[26]{0};
      for(int i = 0; i < s.length(); ++i) counts[s[i]-'a']++;
      for(int i = 0; i < t.length(); ++i) counts[t[i]-'a']--;
      for(int i = 0; i < 26; ++i) if(counts[i]) return false;
      return true;
    }
};

class Solution {
  public:
    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) return false;
      sort(s.begin(), s.end());
      sort(t.begin(), t.end());
      return s.compare(t) == 0;
    }
};

class Solution {
  public:
    bool isAnagram(string s, string t) {
      if (s.length() != t.length()) return false;
      map<char, int> mymap1, mymap2;
      for (int i = 0; i < s.length(); i++) {
        if (mymap1.count(s[i])) mymap1[s[i]]++;
        else mymap1[s[i]] = 1;
        if (mymap2.count(t[i])) mymap2[t[i]]++;
        else mymap2[t[i]] = 1;
      }
      map<char, int>::iterator ite1 = mymap1.begin();
      map<char, int>::iterator ite2 = mymap2.begin();
      for (; ite1 != mymap1.end() && ite2 != mymap2.end(); ite1++, ite2++)
        if (ite1->first != ite2->first || ite1->second != ite2->second) return false;
      if (ite1 == mymap1.end() && ite2 == mymap2.end()) return true;
      return false;
    }
};
