#include<iostream>
#include<vector>
#include<sys/time.h>

using namespace std;

class Solution {
public:
    bool solved ,row[9][9], col[9][9], block[9][9];
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i == 9) { 
            solved = true;
            return;
        }
        // 如果有数字
        if (board[i][j] != '.') {
            if (j < 8) dfs(board, i, j + 1);
            else dfs(board, i + 1, 0);
        }
        else {
            int index = (i / 3) * 3 + j / 3;
            for (int k = 1;k <= 9;k++) {
                // 如果在行、列、块 中都没有使用
                if (!row[i][k - 1] && !col[j][k - 1] && !block[index][k - 1]) {
                    board[i][j] = k + '0';
                    row[i][k - 1] = col[j][k - 1] = block[index][k - 1] = true;
                    // 继续下一个
                    if (j < 8) dfs(board, i, j + 1);
                    else dfs(board, i + 1, 0);
                    // 如果没有解决 那么回溯
                    if (!solved) {
                        board[i][j] = '.';
                        row[i][k - 1] = col[j][k - 1] = block[index][k - 1] = false;
                    }
                }
            }
        }
    }
 
    void solveSudoku(vector<vector<char>>& board) {
        // 初始化为false
        solved=false;
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                row[i][j]=false;
                col[i][j]=false;
                block[i][j]=false;
            }        

        // 将使用的对应数值置为true
        for (int i = 0; i < 9; i++){
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == '.') continue;
                int index = (i / 3) * 3 + j / 3;
                int num = board[i][j] - '0';
                row[i][num - 1] = col[j][num - 1] = block[index][num - 1] = 1;
            }
        }
        dfs(board, 0, 0);
    }
 
};

//增加技巧

int main()
{
   /* vector<vector<char> > res={
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    */
    vector<vector<char> > res(9,vector<char>(9,'0'));

    cout<<"please cin your shudu[9][9]."<<endl;
    cout<<"###################"<<endl;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
                cin>>res[i][j];

    struct timeval stv;
    gettimeofday(&stv, 0);               
    Solution().solveSudoku(res);

    cout<<"this result is :"<<endl;
    cout<<"###################"<<endl;
    for( int i = 0 ; i < res.size() ; i ++ ){
        cout<<" ";
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    cout<<"###################"<<endl;

    struct timeval etv;
    gettimeofday(&etv, 0);
    cout<<"time : "<< (etv.tv_sec-stv.tv_sec)*1000000+(etv.tv_usec-stv.tv_usec)<<" ms"<<endl;
   return 0;
}
