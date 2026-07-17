class Solution {
public:
  struct TrieNode{
    TrieNode*left;
    TrieNode*right;
  };
  TrieNode*getNode(){
    TrieNode*newNode=new TrieNode();
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
  }
   TrieNode*root;
  void insert(TrieNode*root,int num){
     TrieNode*crawler=root;
     for(int i=31;i>=0;i--){
        int ithbit=(num>>i)&1;
        if(ithbit==1){
            if(crawler->right==NULL){
            crawler->right=getNode();
            }
            crawler=crawler->right;
        }
        else{
            if(crawler->left==NULL){
                crawler->left=getNode();
            }
              crawler=crawler->left;
        }
     }
  }
   int  solve(TrieNode*root,int num){
     TrieNode*crawler=root;
     int maxxor=0;
     for(int i=31;i>=0;i--){
        int ithbit=(num>>i)&1;
        if(ithbit==1){
            if(crawler->left!=NULL){
                maxxor+=pow(2,i);
                crawler=crawler->left;
            }
             else crawler=crawler->right;
        }
        else{
            if(crawler->right!=NULL){
                maxxor+=pow(2,i);
                crawler=crawler->right;
            }
            else crawler=crawler->left;
        }

     }
     return maxxor;
   }

    int findMaximumXOR(vector<int>& nums) {
        root=getNode();
         int n=nums.size();
         for(int i=0;i<n;i++){
            insert(root,nums[i]);
         }
         int maxxor=0;
         for(int i=0;i<n;i++){
            maxxor=max(maxxor,solve(root,nums[i]));
         }
         return maxxor;


    }
};