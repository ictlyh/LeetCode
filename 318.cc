int maxProduct(vector<string>& words) {
  vector<int> keys;
  int ret = 0, key = 0;
  for (string& str : words) {
    key = 0;
    for (char c : str) key |= (1 << (c - 'a'));
    keys.push_back(key);
  }
  for (int i = 0; i < words.size(); i++) {
    for (int j = i + 1; j < words.size(); j++) {
      if ((keys[i] & keys[j]) == 0) {
        ret = max((int)(words[i].size() * words[j].size()), ret);
      }
    }
  }
  return ret;
}

// Wrong answer, why?
class Solution {
  public:
    static int countBitsOne(int num) {
      int count = 0;
      while (num) {
        count++;
        num &= (num - 1);
      }
      return count;
    }

    static int stringToInt(string str) {
      int res = 0;
      for (int i = 0; i < str.size(); i++)
        res |= (1 << (str[i] - 'a'));
      return res;
    }

    int maxProduct(vector<string>& words) {
      vector<int> bitwords;
      for (string word : words)
        bitwords.push_back(stringToInt(word));
      vector<int> bitCounts;
      for (int bitword : bitwords)
        bitCounts.push_back(countBitsOne(bitword));
      int res = 0;
      int size = words.size();
      for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
          if ((bitwords[i] & bitwords[j]) == 0)
            if (bitCounts[i] * bitCounts[j] > res)
              res = bitCounts[i] * bitCounts[j];
        }
      }
      return res;
    }
};
