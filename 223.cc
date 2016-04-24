class Solution {
	public:
		int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int res = (C - A) * (D - B) + (G - E) * (H - F);
			if (F >= D || E >= C || B >= H || G <= A) return res;
			vector<int> horizon;
			vector<int> vertical;
			horizon.push_back(A);
			horizon.push_back(C);
			horizon.push_back(E);
			horizon.push_back(G);
			vertical.push_back(B);
			vertical.push_back(D);
			vertical.push_back(F);
			vertical.push_back(H);
			sort(horizon.begin(), horizon.end());
			sort(vertical.begin(), vertical.end());
			return res - abs((horizon[1] - horizon[2]) * (vertical[1] - vertical[2]));
		}
};
