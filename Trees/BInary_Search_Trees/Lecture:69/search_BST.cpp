class Solution {
    private:
    void solve(TreeNode*root,TreeNode*&ans,int val){
        if(root==NULL) return;

        if(root->val==val){
            ans=root;
            return;
        }

        if(root->val<val){
            solve(root->right,ans,val);
        }else{
            solve(root->left,ans,val);
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
 
      TreeNode*ans=NULL;
      solve(root,ans,val);

      return ans;

    }
};
 
