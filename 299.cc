class Solution {
	public:
		map<int, char>::iterator position(map<int, char>& mymap, char value) {
			map<int, char>::iterator ite = mymap.begin();
			while (ite != mymap.end()) {
				if (ite->second == value) return ite;
				ite++;
			}
			return ite;
		}

		string getHint(string secret, string guess) {
			map<int, char> mymap;
			int bull = 0;
			int cow = 0;
			for (int i = 0; i < secret.length(); i++) {
				if (secret[i] == guess[i]) bull++;
				else {
					mymap.insert(pair<int, char>(i, secret[i]));
				}
			}
			for (int i = 0; i < guess.length(); i++) {
				map<int, char>::iterator ite = mymap.find(i);
				if ( ite != mymap.end()) {
					ite = position(mymap, guess[i]);
					if (ite != mymap.end()) {
						cow++;
						ite->second = '*';
					}
				}
			}
			stringstream res;
			res << bull << "A";
			res << cow << "B";
			return res.str();
		}
};
