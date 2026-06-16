class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode*curr=root;
         TreeNode*pred=NULL;

        while(curr){
            if(curr->left){
                pred=curr->left;

                //find predecessor
                while(pred->right){
                    pred=pred->right;
                }

                pred->right=curr->right;
                curr->right=curr->left;
                //left part null karte chalo
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
