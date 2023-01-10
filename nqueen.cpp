
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

    void storeans(vector<vector<string>> &ans, vector<vector<int>> &board, int size){
        vector<string> temp;
        
        for(int i=0; i<size; i++){
            string temp2 = "";
            for(int j=0; j<size; j++){
                if(board[i][j]==0)
                    temp2.append(".");
                else
                    temp2.append("Q");
            }
            temp.push_back(temp2);
        }
        ans.push_back(temp);
    }
    bool checkposition(int row, int col, vector<vector<int>> &board, int size){
        int x=row,y=col;
        while(y>=0){
            if(board[x][y] == 1)
                return false;
            y--;
        }
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y] == 1)
                return false;
            y--;
            x--;
        }
        y=col;
        x=row;
        while(x<size && y>=0){
            if(board[x][y] == 1)
                return false;
            y--;
            x++;
        }
        return true;
    }
    void solve(int col, int size, vector<vector<string>> &ans, vector<vector<int>> &board ){
        if(col == size){
            storeans(ans,board,size);
            return;
        }
        for(int row=0; row<size; row++){
            if(checkposition(row,col,board,size)){
                board[row][col] = 1;
                solve(col+1,size,ans,board);
                board[row][col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector(n,0));
        vector<vector<string>> ans;
        solve(0, n, ans, board);
        return ans;
    }


int main()
{
    int n;//no. of queens you want to place;
    cin>>n;
    vector<vector<string>> ans = solveNQueens(n);
    for(auto a: ans){
        for(auto b: a)
        cout<<b<<"\n";
        cout<<"\n";
    }
    return 0;
}