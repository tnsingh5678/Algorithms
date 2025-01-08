#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Kadane(vector<int> &nums)
    {
        int ans = INT_MIN;
        int a = 0;
        for (int num : nums)
        {
            a += num;
            ans = max(ans, a);
            a = max(a, 0);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << obj.Kadane(v) << endl;
}