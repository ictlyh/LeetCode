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

string getHint(string secret, string guess)
{
  size_t num_bulls = 0, num_cows = 0;
  vector<int> hash(10, 0);
  size_t len = secret.size();
  for(int i = 0; i < len; ++i)
  {
    if(secret[i] == guess[i])
    {
      ++num_bulls; 
      guess[i] = 'A'; // bull, so ignore on next pass
    }
    else
    {
      int digit = secret[i] - '0';
      ++hash[digit];
    }
  }

  for(int i = 0; i < len; ++i)
  {
    if(guess[i] != 'A')
    {
      int digit = guess[i] - '0';
      if(hash[digit] > 0)
      {
        ++num_cows;
        --hash[digit];
      }
    }
  }
  string hint = std::to_string(num_bulls) + "A" + std::to_string(num_cows) + "B";
  return hint;   
}
class Solution {
  public:
    string getHint(string secret, string guess) {
      vector<int>tb_guess(10),tb_secret(10);
      int A=0,B=0;
      for (int i=0;i<secret.size();++i){
        if (secret[i]==guess[i]) A++;
        else {
          tb_guess[guess[i]-'0']++;
          tb_secret[secret[i]-'0']++;
        }
      }
      for (int i=0;i<10;++i){
        B=B+ min(tb_guess[i],tb_secret[i]);
      }
      return to_string(A)+'A'+to_string(B)+'B';
    }
};
