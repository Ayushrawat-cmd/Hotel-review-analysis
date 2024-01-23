#include<bits/stdc++.h>
using namespace std;
void rotateBy90Degree(vector<vector<int>>&mat){
    int n = mat.size(), m = mat[0].size();
    for(int j=0; j<m; j++){
        for(int i =0; i<n/2; i++){
            swap(mat[i][j], mat[n-i-1][j]);
        }
    }
    for(int j =0; j<m; j++){
        for(int i =j ;i <n; i++){
            swap(mat[i][j], mat[j][i]);
        }
    }
}



int main(){
    int rows ,cols ;
    cin>>rows>>cols;
    vector<vector<int>>mat(rows, vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j =0; j<cols; j++){
            cin>>mat[i][j];
        }
    }
    rotateBy90Degree(mat);
    for(int i=0; i<rows; i++){
        for(int j =0; j<cols; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}