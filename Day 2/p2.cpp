// T.C = O(n)^2
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(int target_sum, vector<int> &nums) // using 2 pointer approach 
{
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < len; i++)
    {
        int sum = nums[i];
        for (int j = i + 1, k = len - 1; j < k;)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target_sum)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (sum < target_sum)
                j++;
            else
                k--;
        }
    }

    return ans;
}
int main()
{
    vector<int> nums;
    int target_sum;
    cin >> target_sum;
    int val;
    while (cin >> val)
    {
        nums.push_back(val);
    }
    vector<vector<int>> ans = solve(target_sum, nums);
    for (vector<int> vec : ans)
    {
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}