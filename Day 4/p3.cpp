#include<bits/stdc++.h>
using namespace std;
bool find_value(vector<vector<int>>&mat, int target_val){
    int m = mat[0].size(), n = mat.size();
    int idx=-1 ;
    for(int i=0, j = n-1; i<=j; ){
        int mid = i+(j-i)/2;
        if(mat[mid][0]<=target_val){
            idx = mid;
            i = mid+1;
        }
        else{
            j = mid-1;
        }
    }
    if(mat[idx][0] == target_val)
        return true;
    for(int i=0, j = m-1; i<=j; ){
        int mid = i+(j-i)/2;
        if(mat[idx][mid] == target_val)
            return true;
        else if(mat[idx][mid]<target_val)
            i = mid+1;
        else
            j = mid-1;
    }
    return false;
}
int main(){
    int rows, cols;
    cin>>rows>>cols;
    vector<vector<int>>mat(rows, vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j =0; j<cols; j++){
            cin>>mat[i][j];
        }
    }
    int target_value;
    cin>>target_value;
    if(find_value(mat,target_value )){
        cout<<"Found";
    }
    else    
        cout<<"Not found";
}