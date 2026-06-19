class Solution {
    void inorder(TreeNode*root,int k,int &ans,int &i){

        if(root==NULL){
            return;
        }

        // inorder traversal
        inorder(root->left,k,ans,i);
        i++;
        if(k==i){
            ans=root->val;
        }
        inorder(root->right,k,ans,i);

    }
public:
    int kthSmallest(TreeNode* root, int k) {

        int ans=0;
        int i=0;
        inorder(root,k,ans,i);

        return ans;
    }
};
View less
