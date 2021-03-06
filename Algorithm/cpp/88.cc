﻿class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      nums1.resize(m + n);
      for (--m, --n; m >= 0 && n >= 0;) {
        if (nums1[m] < nums2[n]) {
          nums1[m + n + 1] = nums2[n];
          n--;
        } else {
          nums1[m + n + 1] = nums1[m];
          m--;
        }
      }
      while (n >= 0)
        nums1[n] = nums2[n--];
    }
};


class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      vector<int>::iterator ite1 = nums1.begin();
      vector<int>::iterator ite2 = nums2.begin();
      int i = 0;
      while (ite2 != nums2.end()) {
        while (i < m && *ite1 <= *ite2) {
          ite1++;
          i++;
        }
        if (i == m) {
          nums1.insert(ite1, ite2, nums2.end());
          nums1.resize(m + n, 0);
          return;
        }
        ite1 = nums1.insert(ite1, *ite2);
        ite1++;
        ite2++;
      }
      nums1.resize(m + n, 0);
    }
};
