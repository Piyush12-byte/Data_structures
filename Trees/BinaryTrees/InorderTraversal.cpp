class Solution {
private:
   void InOrderTraversal(TreeNode*root,vector<int>&ans){
    
      // base case
      if(root==NULL){
        return;
      }

      //The concept of inorder is LNR
      InOrderTraversal(root->left,ans);
      ans.push_back(root->val);
      InOrderTraversal(root->right,ans);

   }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {

       vector<int>ans; 
       InOrderTraversal(root,ans);

      return ans;  
    }
};
