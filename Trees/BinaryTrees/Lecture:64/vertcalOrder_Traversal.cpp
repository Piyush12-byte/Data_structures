class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //create a maaping for hd and levelwise mapping

        map<int,map<int,vector<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        vector<vector<int>>ans;

        if(root==NULL) return ans;

        while(!q.empty()){
           pair<TreeNode*,pair<int,int>>temp=q.front();
           q.pop();

           TreeNode*frontNode=temp.first;
           int hd =temp.second.first;
           int lvl=temp.second.second;

           nodes[hd][lvl].push_back(frontNode->val);

           // left side jaoge to horizantal distance kam hogi par level to badhega hi dono side
            if(frontNode->left)
               q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));

            if(frontNode->right)
               q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));   
        }

        vector<int>temp;

        for(auto i:nodes){
           temp.clear();
           for(auto j:i.second){
            sort(j.second.begin(),j.second.end());
             for(auto k:j.second){
                temp.push_back(k);
             }
           } 
          ans.push_back(temp); 
        }
     return ans;
    }
};
