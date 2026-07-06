/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  private:
   void solve(Node*root,vector<int>&inorder){
       
       if(root==NULL) return;
       
       solve(root->left,inorder);
       inorder.push_back(root->data);
       solve(root->right,inorder);
   }
   
   void insert(Node*root,vector<int>&inorder,int& i){
       
       if(root==NULL) return;
       
       insert(root->left,inorder,i);
       insert(root->right,inorder,i);
       root->data=inorder[i++];
       
   }
  public:
    void convertToMaxHeapUtil(Node* root) {
        vector<int>inorder;
        solve(root,inorder);
        int i=0;
        insert(root,inorder,i);
    }
};
