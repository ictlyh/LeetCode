class Solution {
	public:
		int hIndex(vector<int>& citations) {
			sort(citations.begin(), citations.end());
			vector<int> back;
			for (int i = citations.size() - 1; i >= 0; i--)
				back.push_back(citations[i]);
			int h = 0;
			for (int i = 0; i < back.size(); i++) {
				if (back[i] > i) h = i + 1;
				else break;
			}
			return h;
		}
};
