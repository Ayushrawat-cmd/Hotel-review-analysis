#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &height)
{
    int n = height.size();
    stack<int> st;
    vector<int> left(n, -1); // holding the maximum height from left to right
    left[0] = 0;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && height[left[st.top()]] < height[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            left[i] = i;
        }
        else
        {
            left[i] = left[st.top()];
        }
        st.push(i);
    }
    while (!st.empty())
    { // just clearing the stack
        st.pop();
    }
    vector<int> right(n, -1); // holding the maximum height from right to left
    st.push(n - 1);
    right[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && height[right[st.top()]] < height[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            right[i] = i;
        }
        else
        {
            right[i] = right[st.top()];
        }
        st.push(i);
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    { // getting answer
        if (left[i] == i)
        {
            ans = max(ans, height[i]);
        }
        if (right[i] == i)
            ans = max(ans, right[i]);
        ans = max(ans, max((i - left[i]) * height[i], (right[i] - i) * height[i]));
    }
    return ans;
}
int main()
{
    int size;
    cin >> size;
    vector<int> height(size);
    for (int i = 0; i < size; i++)
    {
        cin >> height[i];
    }
    int ans = solve(height);
    cout << ans;
}