class Solution {
private:
    bool isSafe(int newx,int newy, vector<vector<bool>>&visited,vector<vector<int>>& grid,int m,int n){
        if((newx>=0&&newx<n)&&(newy>=0&&newy<m)&&(visited[newx][newy]!=1)&&(grid[newx][newy]!=-1)){
            return true;
        }
       return false; 
    }
    void solve(int x,int y,vector<vector<int>>& grid,int &ans, vector<vector<bool>>&visited,int m,int n,int count ,int total){
        
          count++;

         if(grid[x][y]==2){
            if(count==total)
                 ans++;
            return;
         }

         visited[x][y]=1;
        // Down
         if(isSafe(x+1,y,visited,grid,m,n)){
            solve(x+1,y,grid,ans,visited,m,n,count,total);
         }

         //Left
         if(isSafe(x,y-1,visited,grid,m,n)){
            solve(x,y-1,grid,ans,visited,m,n,count,total);
         }

         //Right
         if(isSafe(x,y+1,visited,grid,m,n)){
            solve(x,y+1,grid,ans,visited,m,n,count,total);
         }

         //UP
         if(isSafe(x-1,y,visited,grid,m,n)){
            solve(x-1,y,grid,ans,visited,m,n,count,total);
         }
         visited[x][y]=0;
    }    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x=0,y=0;

        int total=0;

      for(int i = 0; i < n ; i++){
          for(int j = 0; j < m; j++){

           if(grid[i][j]!=-1){
                total++;
            }
            
           if(grid[i][j] == 1){
             x = i;
             y = j;
            }
          }
       } 

       int ans=0;
       vector<vector<bool>>visited(n,vector<bool>(m,0));
       solve(x,y,grid,ans,visited,m,n,0,total);

       return ans;
    }
};
