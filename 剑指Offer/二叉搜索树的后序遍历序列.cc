class Solution {
  public:
    bool VerifySquenceOfBST(vector<int> sequence) {
      if (sequence.size() == 0) return false;
      return VerifySequenceOfBSTHelper(sequence, 0, sequence.size() - 1);
    }
    bool VerifySequenceOfBSTHelper(vector<int>& sequence, int start, int end) {
      if (start >= end) return true;
      int i = start;
      while (i < end && sequence[i] < sequence[end]) i++;
      int j = i;
      while (j < end && sequence[j] > sequence[end]) j++;
      if (j != end) return false;
      return VerifySequenceOfBSTHelper(sequence, start, i - 1) &&
        VerifySequenceOfBSTHelper(sequence, i, end - 1);
    }
};
