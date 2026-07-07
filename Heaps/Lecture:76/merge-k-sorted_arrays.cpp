class Node{
    public:
      int data;
      int i;
      int j;
      
      Node(int data,int row,int col){
          this->data=data;
          i=row;
          j=col;
      }
};

class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data>b->data;
    }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        
        priority_queue<Node*,vector<Node*>,compare>pq;
        int k=mat.size();
        
        //step 1:saare arrays ke first element ko insert karo
        for(int i=0;i<k;i++){
            Node*temp=new Node(mat[i][0],i,0);
            pq.push(temp);
        }
        
        vector<int>ans;
        
        //step 2:
        while(pq.size()>0){
            Node*temp=pq.top();
            
            ans.push_back(temp->data);
            pq.pop();
            
            int i=temp->i;
            int j=temp->j;
            
            if(j+1<mat[i].size()){
                Node*next=new Node(mat[i][j+1],i,j+1);
                pq.push(next);
            }
            
        }
      return ans;
    }
};
