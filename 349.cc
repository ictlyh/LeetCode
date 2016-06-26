class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      vector<int> res;
      for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
        if (nums1[i] == nums2[j]) {
          res.push_back(nums1[i]);
          i++;
          j++;
          while (i < nums1.size() && nums1[i] == nums1[i - 1]) i++;
          while (j < nums2.size() && nums2[j] == nums2[j - 1]) j++;
        } else if (nums1[i] < nums2[j]) i++;
        else j++;
      }
      return res;
    }
};

class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      vector<int> ret;
      set<int> my_set1;
      set<int> my_set2;
      int i = 0;
      int len1 = nums1.size();
      int len2 = nums2.size();

      if (len1 == 0 || len2 == 0)
        return ret;

      for (i = 0; i < len1; i++)
        my_set1.insert(nums1[i]);
      for (i = 0; i < len2; i++)
        my_set2.insert(nums2[i]);

      set<int>::iterator s1 = my_set1.begin();
      set<int>::iterator s2 = my_set2.begin();

      while (s1 != my_set1.end() && s2 != my_set2.end())
      {
        if (*s1 == *s2)
        {
          ret.push_back(*s1);
          s1++;
          s2++;
        }
        else if (*s1 < *s2)
          s1++;
        else 
          s2++;
      }

      return ret;
    }
};
