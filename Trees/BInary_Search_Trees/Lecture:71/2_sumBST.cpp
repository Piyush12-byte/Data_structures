class Solution {
private:
   void inorder(TreeNode*root,vector<int>&arr){

      if(root==NULL) return;

      //LNR
      inorder(root->left,arr);
      arr.push_back(root->val);
      inorder(root->right,arr);
   }    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);

        int l=0;
        int r=arr.size()-1;
        int sum=0;

        while(l<r){
           sum=arr[l]+arr[r];
           if(sum==k){
             return true;
           }
           else if(sum>k){
             r--;
           }
           else{
             l++;
           }
        }
     return false;
    }
};
