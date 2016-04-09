class Solution {
	public:
		int maximalRectangle(vector<vector<char>>& matrix) {
			int m = matrix.size();
			if (m == 0) return 0;
			int n = matrix[0].size();
			if (n == 0) return 0;

			int result=0;
			vector<int> height(n, 0);
			vector<int> left(n, 0);
			vector<int> right(n, n - 1);
			int currentLeft, currentRight;
			int i, j;
			for (i = 0; i < m; i++) {
				currentLeft = 0;
				currentRight = n - 1;

				for (j = 0; j < n; j++) {
					if (matrix[i][j] == '1') height[j]++;
					else height[j] = 0;
				}

				for (j = 0; j < n; j++) {
					if (matrix[i][j] == '1') left[j] = max(left[j], currentLeft);
					else {
						left[j] = 0;
						currentLeft = j + 1;
					}
				}

				for (j = n - 1; j >= 0; j--) {
					if (matrix[i][j] == '1') right[j] = min(right[j], currentRight);
					else {
						right[j] = n - 1;
						currentRight = j - 1;
					}
				}
				for (j = 0; j< n; j++)
					result = max(result, (right[j] - left[j] + 1) * height[j]);
			}

			return result;
		}
};
