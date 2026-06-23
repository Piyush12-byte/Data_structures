class Solution {
  private:
  void solve(Node*root,vector<int>&inorder){
      
      if(root==NULL) return;
      
      // LNR
      solve(root->left,inorder);
      inorder.push_back(root->data);
      solve(root->right,inorder);
      
  }
  public:
    Node *flattenBST(Node *root) {
        vector<int>inorder;
        solve(root,inorder);
        // root
        Node*newroot=new Node(inorder[0]);
        Node*curr=newroot;
        int n=inorder.size();
        
        for(int i=1;i<n;i++){
            Node*temp=new Node(inorder[i]);
            
            curr->left=NULL;
            curr->right=temp;
            curr=temp;
        }
        
        //for last Node
        curr->left=NULL;
        curr->right=NULL;
        
        return newroot;
    }
};
