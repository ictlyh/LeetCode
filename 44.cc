class Solution {
  public:
    bool isMatch(string s, string p) {
      int pidx = -1, pcur = 0, sidx = 0, scur = 0;
      while (scur < s.size()) {
        if (pcur < p.size() && p[pcur] == '?' || p[pcur] == s[scur]) {
          //advancing both pointers when (both characters match) or ('?' found in pattern)
          //note that *p will not advance beyond its length
          pcur++;
          scur++;
        } else if (pcur < p.size() && p[pcur] == '*') {
          // * found in pattern, track index of *, only advancing pattern pointer 
          pidx = pcur;
          pcur++;
          sidx = scur;
        } else if (pidx != -1) {
          //current characters didn't match, last pattern pointer was *, current pattern
          //pointer is not * only advancing pattern pointer
          pcur = pidx + 1;
          scur = ++sidx;
        } else
          //current pattern pointer is not star, last patter pointer was not *
          //characters do not match
          return false;
      }
      //check for remaining characters in pattern
      while (pcur < p.size() && p[pcur] == '*') pcur++;
      return pcur == p.size();
    }
};
// TLE
class Solution {
  public:
    bool isMatchHelper(string&s, int sidx, string& p, int pidx) {
      if (pidx == p.size()) {
        if (sidx == s.size()) return true;
        else return false;
      }
      if (p[pidx] == '*') {
        for (int i = sidx; i <= s.size(); i++)
          if (isMatchHelper(s, i, p, pidx + 1)) return true;
        return false;
      }
      if (s[sidx] == p[pidx] || p[pidx] == '?')
        return isMatchHelper(s, sidx + 1, p, pidx + 1);
      return false;
    }
    bool isMatch(string s, string p) {
      return isMatchHelper(s, 0, p, 0);
    }
};
