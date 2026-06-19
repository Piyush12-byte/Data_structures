class Solution {
private:
   bool isBST(TreeNode*root,long long min,long long max){

      // base case
      if(root==NULL){
        return true;
      }

      if(root->val>min&&root->val<max){
         bool left=isBST(root->left,min,root->val);
         bool right=isBST(root->right,root->val,max);
         return left&&right;
      }
      else{
         return false;
      }
   }    

public:
    bool isValidBST(TreeNode* root) {
        return isBST(root,LLONG_MIN,LLONG_MAX);
    }
};
