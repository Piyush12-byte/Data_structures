class Solution {
private:
    void Postorder(TreeNode*root,vector<int>&ans){

        //base case
        if(root==NULL){
            return;
        }

        //The concept of postorder is LRN
         Postorder(root->left,ans);
         Postorder(root->right,ans);
         ans.push_back(root->val);
    }    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;

        Postorder(root,ans);

        return ans;
    }
};
