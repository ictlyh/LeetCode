/*
 * C[i] = C[i - 1] * A[i - 1] for i in [1, n - 1]
 * D[i] = D[i + 1] * A[i + 1] for i in [0, n - 2]
 */
class Solution {
  public:
    vector<int> multiply(const vector<int>& A) {
      int n = A.size();
      vector<int> C(n, 1);
      vector<int> D(n, 1);
      for (int i = 1; i < n; i++)
        C[i] = C[i - 1] * A[i - 1];
      for (int i = n - 2; i >= 0; i--)
        D[i] = D[i + 1] * A[i + 1];
      for (int i = 0; i < n; i++)
        C[i] = C[i] * D[i];
      return C;
    }
};
