/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
  int count(Node*root){
      
      if(root==NULL)
          return 0;
          
      int ans=  count(root->left)+count(root->right)+1;
      return ans;
  }
  
  bool iscbt(Node*root,int i,int nodecnt){
      
      if(root==NULL) return true;
      
      if(i>=nodecnt){
          return false;
      }
      else{
          bool left=iscbt(root->left,2*i+1,nodecnt);
          bool right=iscbt(root->right,2*i+2,nodecnt);
          return left&&right;
      }
  }
  
  bool isMaxOrder(Node*root){
      
      if(root->left==NULL&&root->right==NULL){
          return true;
      }
      
      if(root->right==NULL){
          return root->data>root->left->data;
      }
      else{
          return root->data>root->left->data 
                &&root->data>root->right->data
                &&isMaxOrder(root->left)&&isMaxOrder(root->right);
      }
  }
  public:
    bool isHeap(Node* tree) {
        int i=0;
        int nodecnt=count(tree);
      if(iscbt(tree,i,nodecnt)&&isMaxOrder(tree)){
          return true;
      }
     return false; 
    }
};
