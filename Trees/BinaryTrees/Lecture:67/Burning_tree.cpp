class Solution {
private:
    TreeNode*create_mapping(TreeNode*root,map<TreeNode*,TreeNode*>&Nodetoparent,int start){
       queue<TreeNode*>q;
       q.push(root);
       TreeNode*startnode=NULL;

       Nodetoparent[root]=NULL;//kyunkki root ka koi parent nhi hota

       while(!q.empty()){
         TreeNode*front=q.front();
         q.pop();

         if(front->val==start){
            startnode=front;
         }

         if(front->left){
            Nodetoparent[front->left]=front;
            q.push(front->left);
         }

         if(front->right){
            Nodetoparent[front->right]=front;
            q.push(front->right);
         }
       }
      return startnode; 
    }  

    int InfectedTree(TreeNode*startnode,map<TreeNode*,TreeNode*>&Nodetoparent){

        map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        int ans=0;

        q.push(startnode);
        visited[startnode]=1;

        while(!q.empty()){
            bool is_updated=0;
            int n=q.size();

            for(int i=0;i<n;i++){
                TreeNode*front=q.front();
                q.pop();

                if(front->left&&!visited[front->left]){
                    is_updated=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }

                if(front->right&&!visited[front->right]){
                    is_updated=1;
                    q.push(front->right);
                    visited[front->right]=1;
                }

                if(Nodetoparent[front]&&!visited[Nodetoparent[front]]){
                    is_updated=1;
                    q.push(Nodetoparent[front]);
                    visited[Nodetoparent[front]]=1;
                }
            }

            if(is_updated){
                ans++;
            }
        }
        return ans;
    } 
public:
    int amountOfTime(TreeNode* root, int start) {
        //algo
        //step1:create nodetoparent mapping
        //step2:find target/start node
        //step2:burn the tree and track the time

        map<TreeNode*,TreeNode*>Nodetoparent;

        TreeNode*startnode=create_mapping(root,Nodetoparent,start);

        int ans =InfectedTree(startnode,Nodetoparent);

        return ans;
    }
};
