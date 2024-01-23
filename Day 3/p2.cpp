#include<bits/stdc++.h>
using namespace std;
bool isKingSafe(vector<string>&chess){ // function check is queen safe or not
    pair<int,int>king_pos = {-1,-1}; // default king pos
    for(int i =0; i<8; i++){
        for(int j =0; j<8; j++){
            if(chess[i][j] == 'K')
                king_pos = {i,j};
        }
    }   
    if(king_pos == make_pair(-1,-1)) // no king found
        return true;
    for(int i=0; i<8; i++){
        for(int j =0; j<8; j++){
            if(chess[i][j] == 'H' && ( (abs(i-king_pos.first) == 1 && abs(j-king_pos.second) == 2) ||(abs(i-king_pos.first) == 2 && abs(j-king_pos.second) == 1) ) ){ // all the moves of horse
                return false;
            }
            else if(chess[i][j] == 'C' && abs(i-king_pos.first) == abs(j-king_pos.second)){ // all the camel moves
                return false;
            }
            else if(chess[i][j] == 'Q'){
                if(abs(i-king_pos.first) == abs(j-king_pos.second) || i==king_pos.first || j == king_pos.second ) // all the queen moves
                    return false;
            }
            else if(chess[i][j] == 'E' && (i==king_pos.first || j == king_pos.second )){ // all the elephant moves
                return false;
            }
        }
    }
    return true;
}
int main(){
    // vector<string>chess ={
    //     "E.......",
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    //     "K.......",
    // };
    // vector<string>chess ={
    //     "E.......",
    //     "........",
    //     "........",
    //     ".....K..",
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    // };
    vector<string>chess ={
        "........",
        "........",
        "........",
        "...K....",
        "........",
        ".E.C....",
        "........",
        "........",
    };
    if(isKingSafe(chess)){
        cout<<"King is safe";
    }
    else
        cout<<"King is not safe";

}