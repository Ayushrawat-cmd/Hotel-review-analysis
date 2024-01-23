#include <bits/stdc++.h>
using namespace std;
vector<int> clockWise;
vector<int> antiClockWise;
void clockWiseDirection(vector<vector<int>> &mat, int n, int m, int i, int j, vector<vector<int>> &vis) // for performing clockwise direction of a matrix
{
    clockWise.push_back(mat[i][j]);
    vis[i][j] = 1;

    if (j + 1 < m && !vis[i][j + 1])
        clockWiseDirection(mat, n, m, i, j + 1, vis);
    else if (i + 1 < n && !vis[i + 1][j])
        clockWiseDirection(mat, n, m, i + 1, j, vis);
    else if (j - 1 >= 0 && !vis[i][j - 1])
        clockWiseDirection(mat, n, m, i, j - 1, vis);
    else if (i - 1 >= 0 && !vis[i - 1][j])
        clockWiseDirection(mat, n, m, i - 1, j, vis);
}
void antiClockWiseDirection(vector<vector<int>> &mat, int n, int m, int i, int j, vector<vector<int>> &vis) // for performing in anticlockwise direction of a matrix
{
    antiClockWise.push_back(mat[i][j]);
    vis[i][j] = 1;
    if (j - 1 >= 0 && !vis[i][j - 1])
        antiClockWiseDirection(mat, n, m, i, j - 1, vis);
    else if (i + 1 < n && !vis[i + 1][j])
        antiClockWiseDirection(mat, n, m, i + 1, j, vis);
    else if (j + 1 < m && !vis[i][j + 1])
        antiClockWiseDirection(mat, n, m, i, j + 1, vis);
    else if (i - 1 >= 0 && !vis[i - 1][j])
        antiClockWiseDirection(mat, n, m, i - 1, j, vis);
}
int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> vis(rows, vector<int>(cols, 0));
    vector<vector<int>> vis1(rows, vector<int>(cols, 0));
    clockWiseDirection(mat, rows, cols, 0, 0, vis);
    for (int i = 0; i < rows * cols; i++)
    {
        cout << clockWise[i] << " ";
    }
    cout<<"\n";
    antiClockWiseDirection(mat, rows, cols, 0, cols - 1, vis1);
    for (int i = 0; i < rows * cols; i++)
    {
        cout << antiClockWise[i] << " ";
    }
}