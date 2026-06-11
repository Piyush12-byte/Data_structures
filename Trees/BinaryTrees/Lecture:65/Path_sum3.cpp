class Solution {
private:
    void solve(TreeNode*root,vector<int>path,int&cnt,int k){

        if(root==NULL) return;

        path.push_back(root->val);

        solve(root->left,path,cnt,k);
        solve(root->right,path,cnt,k);

        int n=path.size();
        long long sum=0;
        for(int i=n-1;i>=0;i--){
          sum+=path[i];
          if(sum==k)cnt++;
        }
    }    
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int cnt=0;
        solve(root,path,cnt,targetSum);
        return cnt;
    }
};
