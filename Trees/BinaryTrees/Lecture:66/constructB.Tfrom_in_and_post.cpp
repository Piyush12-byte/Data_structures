/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void create_mapping(vector<int>inorder,unordered_map<int,int>&Nodetoidx,int n){
        for(int i=0;i<n;i++){
            Nodetoidx[inorder[i]]=i;
        }
    }

    TreeNode*solve(vector<int>inorder,vector<int>postorder,unordered_map<int,int>&Nodetoidx,int&pidx,int in_startidx,int in_endidx,int n){

        // base case
        if(pidx<0||in_startidx>in_endidx){
            return NULL;
        }

        int element=postorder[pidx--];
        TreeNode*root=new TreeNode(element);
        int pos=Nodetoidx[element];

        // recursive calls for construction of tree;
        root->right=solve(inorder,postorder,Nodetoidx,pidx,pos+1,in_endidx,n);
        root->left=solve(inorder,postorder,Nodetoidx,pidx,in_startidx,pos-1,n);

        return root;
    }    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int pidx=n-1;
        unordered_map<int,int>Nodetoidx;

        create_mapping(inorder,Nodetoidx,n);
        TreeNode*ans=solve(inorder,postorder,Nodetoidx,pidx,0,n-1,n);

        return ans;
    }
};
