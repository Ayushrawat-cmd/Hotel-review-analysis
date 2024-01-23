#include<bits/stdc++.h>
using namespace std;
bool validSudoku(vector<string>&mat){
    vector<vector<int>>row_memo(9, vector<int>(10,0));
    vector<vector<int>>col_memo(9, vector<int>(10,0));
    for(int i =0; i<9; i++){ // checking for each row and column that there is no duplicate value
        for(int j=0; j<9; j++){
            if(mat[i][j]!='.'){
                if(row_memo[i][mat[i][j]-'0'] || col_memo[j][mat[i][j]-'0'])
                    return false;
                row_memo[i][mat[i][j]-'0']++;
                col_memo[j][mat[i][j]-'0']++;
            }
        }
    }
    for(int i =0; i<9; i+=3){ // loop for checking each squares 3X3 that there is no duplicate value
        for(int j=0; j<9;j+=3 ){
            vector<int>tmp(9,0);
            for(int k=i; k<i+3; k++){
                for(int l=j; l<j+3; l++){
                    if(mat[k][l]!='.'){
                        if(tmp[mat[k][l]-'0'])
                            return false;
                        tmp[mat[k][l]-'0']++;
                    }
                }   
            }
        }
    }
    return true;
}
int main(){
    // vector<string>mat = {
    //     "53..7....",
    //     "6..195...",
    //     ".98....6.",
    //     "8...6...3",
    //     "4..8.3..1",
    //     "7...2...6",
    //     ".6....28.",
    //     "...419..5",
    //     "....8..79"
    // };
    vector<string>mat = {
        "53..7..3.",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419.35",
        "....8.379"
    };
    // for(auto i: mat)
    //     cout<<i;
    if(validSudoku(mat))
        cout<<"Valid sudoku";
    else
        cout<<"Not valid";
}