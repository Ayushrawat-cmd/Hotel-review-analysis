#include <bits/stdc++.h>
using namespace std;
void solve(int star)
{
    int rows, symbols;
    rows = symbols = star + 2; 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < symbols; j++)
        {
            if (symbols - j - i - 1 == 0)
            {
                cout << "/";
            }
            else if (j - i == 0)
            {
                cout << "\\";
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
}
int main()
{
    int star;
    cin >> star;
    solve(star);
}