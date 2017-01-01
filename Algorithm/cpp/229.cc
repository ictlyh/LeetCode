class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> res;
      if (nums.size() == 0) return res;
      int len = nums.size() / 3;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++) {
        if (i + len < nums.size() && nums[i] == nums[i + len]) {
          res.push_back(nums[i]);
          int j = i + len + 1;
          while (j < nums.size() && nums[j] == nums[j - 1]) j++;
          i = j - 1;
        } else {
          while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
      }
      return res;
    }
};

class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
      int a, b;
      int counta = 0;
      int countb = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (counta == 0) {
          if (countb == 0 || b != nums[i]) {
            a = nums[i];
            counta = 1;
          } else countb++;
        } else if (countb == 0) {
          if (counta == 0 || a != nums[i]) {
            b = nums[i];
            countb = 1;
          } else counta++;
        } else {
          if (a == nums[i]) counta++;
          else if (b == nums[i]) countb++;
          else {
            counta--;
            countb--;
          }
        }
      }
      int require = nums.size() / 3;
      vector<int> res;
      if (counta && std::count(nums.begin(), nums.end(), a) > require) res.push_back(a);
      if (countb && std::count(nums.begin(), nums.end(), b) > require) res.push_back(b);
      return res;
    }
};

// General
vector<int> majorKEle(vector<int>& nums, int k) {
  if (k < 2 || nums.empty()) {
    return vector<int> ();
  }
  vector<int> candidate(k - 1, nums[0]);
  vector<int> count(k - 1, 0);
  count[0] = 1;
  for (auto i = 1; i < nums.size(); ++i) {
    auto pos = std::find(candidate.begin(), candidate.end(), nums[i]);
    if (pos != candidate.end()) {
      count[pos - candidate.begin()] += 1;
    } else {
      bool replace_sign = false;
      for (auto j = 0; j < count.size(); ++j) {
        if (count[j] == 0) {
          count[j] = 1;
          replace_sign = true;
          candidate[j] = nums[i];
          break;
        }
      }
      if (replace_sign == false) {
        for (auto j = 0; j < count.size(); ++j) {
          count[j] -= 1;
        }
      }
    }
  }
  int require = nums.size() / k;
  vector<int> result;
  for (auto i = 0; i < count.size(); ++i) {
    if (count[i] && std::count(nums.begin(), nums.end(), candidate[i]) > require) {
      result.push_back(candidate[i]); 
    }
  }
  return result;
}
