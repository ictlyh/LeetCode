



// Time Limit Exceeded
class Solution {
  public:
    vector<string> findItineraryDFS(string from, unordered_map<string, vector<string>>& hashmap,
        set<pair<string, string>> visited, int ticketCount, vector<string> tmp) {
      if (visited.size() == ticketCount) return tmp;
      vector<string> tos = hashmap[from];
      for (string to : tos) {
        if (visited.find(make_pair(from, to)) != visited.end()) continue;
        tmp.push_back(to);
        visited.insert(make_pair(from, to));
        vector<string> res = findItineraryDFS(to, hashmap, visited, ticketCount, tmp);
        if (res.size() - 1 == ticketCount) return res;
        tmp.pop_back();
        visited.erase(make_pair(from, to));
      }
      return tmp;
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
      unordered_map<string, vector<string>> hashmap;
      for (pair<string, string> ticket : tickets) {
        if (hashmap.find(ticket.first) == hashmap.end())
          hashmap[ticket.first] = vector<string>(1, ticket.second);
        else
          hashmap[ticket.first].push_back(ticket.second);
      }
      for (unordered_map<string, vector<string>>::iterator ite = hashmap.begin();
          ite != hashmap.end(); ite++)
        sort(ite->second.begin(), ite->second.end());
      vector<string> tmp;
      tmp.push_back("JFK");
      set<pair<string, string>> visited;
      return findItineraryDFS("JFK", hashmap, visited, tickets.size(), tmp);
    }
};
