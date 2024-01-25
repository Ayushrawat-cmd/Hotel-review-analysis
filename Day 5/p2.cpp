#include <bits/stdc++.h>
using namespace std;
double solve(vector<int> arr1, vector<int> arr2) // finding median after merge of 2 arrays
{
    int n = arr1.size(), m = arr2.size();
    if (n > m)
    {
        return solve(arr2, arr1);
    }
    int mid = (n + m + 1) / 2; //3
    int left = 0, right = n;
    for (; left <= right;)
    {
        int mid1 = left + (right - left) / 2; // getting middle index in arr1 
        int mid2 = mid - mid1; // rest values from arr2
        int right1 = INT_MAX, left1 = INT_MIN;
        int right2 = INT_MAX, left2 = INT_MIN;
        if (mid1 < n)
        {
            right1 = arr1[mid1];
        }
        if (mid2 < m)
        {
            right2 = arr2[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            left1 = arr1[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            left2 = arr2[mid2 - 1];
        }
        if (left1 <= right2 && left2 <= right1) // got the desired median
        {
            return (n + m) & 1 ? max(left1, left2) : ((double)max(left1, left2) + (double)min(right1, right2)) / 2.0;
        }
        else if (left1 > right2) 
        {
            right = mid1 - 1;
        }
        else
            left = mid1 + 1;
    }
    return -1;
}
int main()
{
    int arr1_size, arr2_size;
    cin >> arr1_size >> arr2_size;
    vector<int> arr1(arr1_size);
    vector<int> arr2(arr2_size);
    for (int i = 0; i < arr1_size; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < arr2_size; i++)
    {
        cin >> arr2[i];
    }
    cout << solve(arr1, arr2);
}