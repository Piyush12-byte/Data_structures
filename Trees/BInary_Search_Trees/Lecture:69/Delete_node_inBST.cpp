class Solution {
private:
   int minval(TreeNode*root){
      TreeNode*temp=root;
      while(temp->left){
        temp=temp->left;
      }
     return temp->val; 
   }    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL) return NULL;

        //deletion wala case
        if(root->val==key){
            // 0 child case:
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }

            //1 child case

            //right
            if(root->left==NULL&&root->right!=NULL){
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }

            //Left

             if(root->left!=NULL&&root->right==NULL){
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }

            //2 child case(agar right se replace karoge to minm of right left se max of left)

            if(root->left!=NULL&&root->right!=NULL){
                int mini=minval(root->right);
                root->val=mini;
                //delete kardo jisse copy kiya ha usse
                root->right=deleteNode(root->right,mini);
                return root;
            }

        }
        else if(root->val>key){
            //left ki call
           root->left= deleteNode(root->left,key);
            return root;
        }
        else{
           // right ki call
           root->right= deleteNode(root->right,key);
           return root;
        }
       return root; 
    }
};
