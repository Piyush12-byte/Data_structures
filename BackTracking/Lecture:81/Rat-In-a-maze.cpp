class Solution {
  private:
  bool isSafe(int x,int y,vector<vector<bool>>&visited,vector<vector<int>>&maze,int n){
      if((x>=0&&x<n)&&(y>=0&&y<n)&&(maze[x][y]==1)&&(visited[x][y]!=1)){
          return true;
      }
     return false; 
  }
   void solve(int x,int y,vector<vector<int>>&maze,int n,vector<string>&ans,vector<vector<bool>>&visited,string path){
       
       if(x==n-1&&y==n-1 ){
           ans.push_back(path);
           return;
       }
       
       //D,L,R,U
       //1- Down
        visited[x][y]=1;
       if(isSafe(x+1,y,visited,maze,n)){
           solve(x+1,y,maze,n,ans,visited,path+'D');
       }
       
       //2-Left
       if(isSafe(x,y-1,visited,maze,n)){
           solve(x,y-1,maze,n,ans,visited,path+'L');
       }
       
       //3-Right
       if(isSafe(x,y+1,visited,maze,n)){
           solve(x,y+1,maze,n,ans,visited,path+'R');
       }
       
       //4-UP
       if(isSafe(x-1,y,visited,maze,n)){
           solve(x-1,y,maze,n,ans,visited,path+'U');
       }
        visited[x][y]=0;
       
   }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
      
        vector<string>ans;
        int n=maze.size();
        
        if(maze[0][0]==0)
            return ans;
        
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        string path="";
        
        solve(0,0,maze,n,ans,visited,path);
        
        return ans;
    }
};
