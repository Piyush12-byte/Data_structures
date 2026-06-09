class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>result;

        if(root==NULL) return result;

        queue<TreeNode*>q;
        q.push(root);
        bool leftToright=true;

        while(!q.empty()){
            int n=q.size();
            vector<int>temp(n);
         // ab temp me according to LR or RL elements dalo from queue
            for(int i=0;i<n;i++){
               TreeNode*front=q.front();
               q.pop();
         // ye index hi btayega value aange se traverse karke daalni ya peeche se
               int idx=leftToright?i:n-i-1;
               temp[idx]=front->val;

               if(front->left){
                  q.push(front->left);
               }

               if(front->right){
                q.push(front->right);
               }
            }
           leftToright=!leftToright;
           result.push_back(temp);
        }
       return result; 
    }
};
