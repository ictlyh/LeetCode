class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {

      if(s3.length() != s1.length() + s2.length())
        return false;

      bool table[s1.length()+1][s2.length()+1];

      for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
          if(i==0 && j==0)
            table[i][j] = true;
          else if(i == 0)
            table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
          else if(j == 0)
            table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
          else
            table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }

      return table[s1.length()][s2.length()];
    }
};

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
