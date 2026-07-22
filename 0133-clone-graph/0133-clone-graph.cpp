/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   unordered_map<Node*,Node*>mp;
   void dfs(Node*node,Node*newNode){
    for(auto it:node->neighbors){
            Node*n=new Node(it->val);
            if(mp.find(it)==mp.end()){
                mp[it]=n;
                newNode->neighbors.push_back(n);
                dfs(it,n);
            }
        else{
             newNode->neighbors.push_back(mp[it]);
        }
    }
   }
    Node* cloneGraph(Node* node) {
          if(node==NULL) return NULL;
          Node*newNode=new Node(node->val);
          mp[node]=newNode;
          dfs(node,newNode);
          return newNode;

          
    }
};