class Solution {
private:
    void solve(TreeNode*root,vector<int>&inorder){
        
        if(root==NULL) return;

        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    } 

    TreeNode*get_balanced(int s,int e,vector<int>inorder){

       if(s>e){
         return NULL;
       }

       int mid=s+(e-s)/2;

       TreeNode*root=new TreeNode(inorder[mid]);

       root->left=get_balanced(s,mid-1,inorder);
       root->right=get_balanced(mid+1,e,inorder);

       return root;
    }    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        solve(root,inorder);
        int s=0,e=inorder.size()-1;
        TreeNode*ans=get_balanced(s,e,inorder);

        return ans; 
    }
};
