class Solution {
private:
    void addsolution(vector<vector<int>>&board,vector<vector<string>>&ans,int n){
        vector<string>temp(n,string(n,'.'));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    temp[i][j]='Q';
                }
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int row,int col,vector<vector<int>>&board,int n){
        int x=row;
        int y=col;

        //checking for row;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }

        x=row;
        y=col;

        while(x>=0&&y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }

        x=row;
        y=col;

        while(x<n&&y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }

       return true; 
    }

    void solve(int col,vector<vector<string>>&ans,vector<vector<int>>&board,int n){

        // base case
        if(col==n){
            addsolution(board,ans,n);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,ans,board,n);
                board[row][col]=0;
            }
        }
    }    
public:
    vector<vector<string>> solveNQueens(int n) {

       vector<vector<int>>board(n,vector<int>(n,0));
       vector<vector<string>>ans;

       solve(0,ans,board,n);

       return ans;
    }
};
