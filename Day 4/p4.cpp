#include<bits/stdc++.h>
using namespace std;
int row[4] = {0,-1, 0, 1};
int col[4] = {1,0,-1,0};
bool valid(int x, int y, int n , int m){ // if the index is valid or not
    return x>=0 && y>=0 && x<n && y<m;
}
int number_of_islands(vector<vector<int>>&island){ // using BFS to find all the possible islands
    int n =island.size(), m =island[0].size();
    queue<pair<int,int>>q;
    int ans = 0;
    for(int i=0; i<n; i++ ){
        for(int j =0; j<m; j++){
            if(island[i][j]){
                ans++;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    island[x][y] = 0;
                    for(int idx = 0; idx<4; idx++){
                        int new_x = row[idx] + x;
                        int new_y = col[idx] + y;
                        if(valid(new_x, new_y, n, m) && island[new_x][new_y]){
                            q.push({new_x, new_y});
                        } 

                    }
               }
            }
        }
    }
    return ans;
}
int main(){
    int rows ,cols ;
    cin>>rows>>cols;
    vector<vector<int>>island(rows, vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j =0; j<cols; j++){
            cin>>island[i][j];
        }
    }
    cout<<number_of_islands(island);
}