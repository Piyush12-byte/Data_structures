class Solution {
  private:
   void TraverseLeft(Node*root,vector<int>&ans){
       
       // base case and to avoid including leaf Node
       if((root==NULL)||(root->left==NULL&&root->right==NULL)){
           return;
       }
       
       ans.push_back(root->data);
       if(root->left)
          TraverseLeft(root->left,ans);
        else
          TraverseLeft(root->right,ans);
       
   }
   
   void LeafTraversal(Node*root,vector<int>&ans){
       
       if(root==NULL){
           return;
       }
       
       if((root->left==NULL)&&(root->right==NULL)){
           ans.push_back(root->data);
       }
       
       LeafTraversal(root->left,ans);
       LeafTraversal(root->right,ans);
   }
   
   void TraverseRight(Node*root,vector<int>&ans){
       
       if((root==NULL)||(root->left==NULL&&root->right==NULL)){
           return;
       }
       
       if(root->right)
          TraverseRight(root->right,ans);
       else
          TraverseRight(root->left,ans);
          
      // wapas jate time print karo
       ans.push_back(root->data);
   }
   
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        // left Traverse karo aur print karo
        TraverseLeft(root->left,ans);
        
        // for printing leaf Nodes
        //Left
        LeafTraversal(root->left,ans);
        //right
        LeafTraversal(root->right,ans);
        
        // right traverse karo aur print karo
        TraverseRight(root->right,ans);
    
      return ans;
    }
};
