class Solution {
public:
    int maxDepth(TreeNode* root) {

      // here if we have to count number of edges the return -1;
        if(root==NULL){
            return 0;
        }

        int h1=maxDepth(root->left);
        int h2=maxDepth(root->right);

        int ans =max(h1,h2)+1;

        return ans;
    }
};
