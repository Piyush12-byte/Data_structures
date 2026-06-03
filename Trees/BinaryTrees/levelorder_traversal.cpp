class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>temp;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode*temp1=q.front();
            q.pop();

            if(temp1==NULL){
               ans.push_back(temp);
               temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
               temp.push_back(temp1->val);

               if(temp1->left){
                q.push(temp1->left);
               }

               if(temp1->right){
                q.push(temp1->right);
               }
            }
        }
        return ans;
    }
};
