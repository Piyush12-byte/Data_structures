class Solution {
  public:
    vector<int> topView(Node *root) {
        
        map<int,int>topNode;
        vector<int>ans;
        queue<pair<Node*,int>>q;
        
        if(root==NULL) return ans;
        
        q.push(make_pair(root,0));// in begginig horizontal distance is 0;
        
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            
            Node*frontNode=temp.first;
            int hd=temp.second;
            
            //if one value is already mapped for a hd ,then do nothing
            if(topNode.find(hd)==topNode.end()){// is line ka matlab ha hd ke sath koi mapping present nhi ha
              topNode[hd]=frontNode->data;
            }
            
            if(frontNode->left)
               q.push(make_pair(frontNode->left,hd-1));
            
            if(frontNode->right)
               q.push(make_pair(frontNode->right,hd+1));
        }
        
        for(auto i:topNode){
            ans.push_back(i.second);
        }
      return ans;  
    }
};
