
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};


class Solution {
  public:
  
  info solve(Node*root,int&ans){
    
    if(root==NULL){
        return{INT_MIN,INT_MAX,true,0};
    }
    
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    
    info curr;
    
    curr.size=left.size+right.size+1;
    curr.maxi=max(root->data,right.maxi);
    curr.mini=min(root->data,left.mini);
    
    if(left.isBST && right.isBST && (left.maxi<root->data&&right.mini>root->data)){
        curr.isBST=true;
    }
    else{
        curr.isBST=false;
    }
    
    if(curr.isBST){
        ans=max(ans,curr.size);
    }
    return curr;
}


    int largestBst(Node *root) {
        int maxsize=0;
        info temp=solve(root,maxsize);
        return maxsize;
    }
};
