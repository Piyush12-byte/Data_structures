class Solution {
  private:
  void solve(Node*root,int len,int &maxlen,int sum,int &maxsum){
      
      // base case
      if(root==NULL){
          if(len>maxlen){
              maxlen=len;
              maxsum=sum;
          }else if(len==maxlen){
              maxsum=max(sum,maxsum);
          }
          return;
      }
      
      sum+=root->data;
      solve(root->left,len+1,maxlen,sum,maxsum);
      solve(root->right,len+1,maxlen,sum,maxsum);
  }
        
  public:
    int sumOfLongRootToLeafPath(Node *root) {
       
       int len=0;
       int maxlen=0;
       
       int sum=0;
       int maxsum=INT_MIN;
       
       solve(root,len,maxlen,sum,maxsum);
       
       return maxsum;
    }
};
