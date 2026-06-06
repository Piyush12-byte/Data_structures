class Solution {
    pair<bool,int> check_balanced(TreeNode*root){
        //first->is balanced?, second->height

        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        
        pair<bool,int>left=check_balanced(root->left);
        pair<bool,int>right=check_balanced(root->right);

        bool leftans =left.first;
        bool rightans=right.first;

        bool diff=abs(left.second-right.second)<=1;

       pair<bool,int>ans;
        if(leftans&&rightans&&diff){
            ans.first=true;
        }else{
            ans.first=false;
        }
       ans.second=max(left.second,right.second)+1;

       return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        // A tree is balanced if h(l)-h(r)<=1;
        pair< bool,int> ans =check_balanced(root);
       return ans.first;
    }
};
