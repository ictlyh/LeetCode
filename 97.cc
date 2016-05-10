

// Time Limit Exceeded
class Solution {
  public:
    bool isInterleaveHelper(string& s1, string& s2, string& s3, size_t idx1, size_t idx2) {
      if (idx1 > s1.size() || idx2 > s2.size() ||
          (s1[idx1] != s3[idx1 + idx2] && s2[idx2] != s3[idx1 + idx2])) return false;
      if (idx1 == s1.size() && idx2 == s2.size()) return true;
      bool res1 = false;
      bool res2 = false;
      if (idx1 < s1.size() && s1[idx1] == s3[idx1 + idx2])
        res1 = isInterleaveHelper(s1, s2, s3, idx1 + 1, idx2);
      if (idx2 < s2.size() && s2[idx2] == s3[idx1 + idx2])
        res2 = isInterleaveHelper(s1, s2, s3, idx1, idx2 + 1);
      return res1 || res2;
    }

    bool isInterleave(string s1, string s2, string s3) {
      if (s1.size() + s2.size() != s3.size()) return false;
      return isInterleaveHelper(s1, s2, s3, 0, 0);
    }
};
