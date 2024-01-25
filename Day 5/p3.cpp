#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr, int k)// finding the maximum values in sliding window of size k for the given array 
{
    priority_queue<pair<int, int>> pq; // holding the indexes with respect to their values
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }
    vector<int> ans;
    ans.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});
        while (pq.top().second < i - k)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}
int main()
{
    int size, k;
    cin >> size >> k;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = solve(arr, k);
    for (int i : ans)
    {
        cout << i << " ";
    }
}