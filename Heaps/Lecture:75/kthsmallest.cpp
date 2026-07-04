class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
       priority_queue<int>pq;
       
       for(int i=0;i<k;i++){
           pq.push(arr[i]);
       }
       
       //converting maxhip into a maxhip that contains minimum values
       for(int i=k;i<arr.size();i++){
           if(arr[i]<pq.top()){
               pq.pop();
               pq.push(arr[i]);
           }
       }
     return pq.top();
    }
};
