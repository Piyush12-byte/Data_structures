class Solution {
  Node*solve(Node*root,int &k,int n){
      
      if(root==NULL) return NULL;
      
      if(root->data==n) return root;
      
      Node*leftAns=solve(root->left,k,n);
      Node*rightAns=solve(root->right,k,n);
      
      if(leftAns!=NULL&&rightAns==NULL) {
           k--;
           if(k<=0){
               k=INT_MAX;
               return root; 
           }
           return leftAns;
      }
      
      
         if(leftAns==NULL&&rightAns!=NULL) {
           k--;
           if(k<=0){
               k=INT_MAX;
               return root; 
           }
           return rightAns;
      }
      
      return NULL;
      
  }    
  public:
    int kthAncestor(Node *root, int k, int node) {
        
        Node*ans=solve(root,k,node);
        if(ans==NULL||ans->data==node)
           return -1;
        else
           return ans->data;
    }
};
