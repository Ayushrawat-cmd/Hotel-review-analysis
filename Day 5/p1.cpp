#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void solve(string &s1, string &s2, int i, int j, string &tmp)
{ // finding all the combinations possible using both the strings
    if (i == s1.length())
    { // if reach at the last of the first string
        tmp += s2.substr(j, s2.length());
        ans.push_back(tmp);
        int val = s2.length() - j;
        while (val--)
        {
            tmp.pop_back();
        }
        return;
    }
    if (j == s2.length())
    { // reach at the last of the second string
        tmp += s1.substr(i, s1.length());
        ans.push_back(tmp);
        int val = s1.length() - i;
        while (val--)
        {
            tmp.pop_back();
        }
        return;
    }
    tmp += s1[i];
    solve(s1, s2, i + 1, j, tmp);
    tmp.pop_back();
    tmp += s2[j];
    solve(s1, s2, i, j + 1, tmp);
    tmp.pop_back();
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    string tmp;
    solve(str1, str2, 0, 0, tmp);
    for (auto i : ans)
    {
        cout << i << "\n";
    }
}