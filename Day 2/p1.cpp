#include <bits/stdc++.h>
using namespace std;
vector<int> withoutSort(vector<int> &values) 
{ // T.C = O(n), S.C=O(INT_MAX) space complexity heavy
    vector<int> memo(INT_MAX, 0);
    vector<int> ans;
    for (int i : values)
    {
        if (memo[i] == 1)
        {
            continue;
        }
        memo[i]++;
        ans.push_back(i);
    }
    return ans;
}
static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
static bool comp1(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
vector<int> usingSort(vector<int> &values) 
{ // T.C =O(nlogn), S.C =O(n) using sort technique
    int n = values.size();
    vector<int> ans;
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp.push_back({values[i], i});
    }
    sort(tmp.begin(), tmp.end(), comp);
    vector<pair<int, int>> tmp1;
    for (int i = 0; i < n;)
    {
        int val = tmp[i].first;
        tmp1.push_back(tmp[i]);
        for (; i < n && tmp[i].first == val;)
        {
            i++;
        }
    }
    sort(tmp1.begin(), tmp1.end(), comp1);
    for (pair<int, int> i : tmp1)
    {
        ans.push_back(i.first);
    }
    return ans;
}
vector<int> removeDuplicates(vector<int> &values)
{ // using unordered_set T.C=O(n) S.C = O(n)
    unordered_set<int> st;
    vector<int> ans;
    for (int i : values)
    {
        if (st.find(i) == st.end())
        {
            ans.push_back(i);
        }
        st.insert(i);
    }
    return ans;
}
int main()
{
    int val;
    vector<int> values;
    while (cin >> val)
    {
        values.push_back(val);
    }
    vector<int> ans = removeDuplicates(values);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    vector<int> ans1 = usingSort(values);
    for (int i : ans1)
    {
        cout << i << " ";
    }
    cout << "\n";
    vector<int> ans2 = usingSort(values);
    for (int i : ans2)
    {
        cout << i << " ";
    }
    cout << "\n";
}