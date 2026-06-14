class Solution {
private:
    void create_mapping(vector<int> inorder,unordered_map<int,int>&mp,int n){
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
    }

    TreeNode*solve(vector<int>preorder,vector<int>inorder,unordered_map<int,int>&Nodetoidx,int &pidx,int in_startidx,int in_endidx,int n){

        // base case
        if(pidx>=n||in_startidx>in_endidx){
            return NULL;
        }

        int element=preorder[pidx++];
        TreeNode*root=new TreeNode(element);
        int pos=Nodetoidx[element];

        // calls for left and right construction

        root->left=solve(preorder,inorder,Nodetoidx,pidx,in_startidx,pos-1,n);
        root->right=solve(preorder,inorder,Nodetoidx,pidx,pos+1,in_endidx,n);

        return root;

    }    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int pidx=0;
        unordered_map<int,int>Nodetoidx;

        create_mapping(inorder,Nodetoidx,n);
        TreeNode*ans=solve(preorder,inorder,Nodetoidx,pidx,0,n-1,n);

        return ans;
        
    }
};
