/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
  public:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> hashmap;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      if(!node) return NULL;
      if(hashmap.find(node) == hashmap.end()){
        hashmap[node] = new UndirectedGraphNode(node->label);
        for(UndirectedGraphNode* neighbor : node->neighbors){
          hashmap[node]->neighbors.push_back(cloneGraph(neighbor));
        }
      }
      return hashmap[node];
    }
};
