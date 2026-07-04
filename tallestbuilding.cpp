#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> rods(n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> rods[i];
        sum += rods[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        int x = rods[i];

        for (int diff = 0; diff <= sum; diff++)
        {
            if (dp[i][diff] == -1)
                continue;

            // Ignore rod
            dp[i + 1][diff] =
                max(dp[i + 1][diff], dp[i][diff]);

            // Put on taller pillar
            dp[i + 1][diff + x] =
                max(dp[i + 1][diff + x], dp[i][diff]);

            // Put on shorter pillar
            int newDiff = abs(diff - x);
            int newShort = dp[i][diff] + min(diff, x);

            dp[i + 1][newDiff] =
                max(dp[i + 1][newDiff], newShort);
        }
    }

    cout << dp[n][0] << endl;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> rods;
// int n;

// int solve(int idx, int h1, int h2)
// {
//     if (idx == n)
//     {
//         if (h1 == h2)
//             return h1;
//         return -1e9;          // invalid
//     }

//     // Skip current rod
//     int ans = solve(idx + 1, h1, h2);

//     // Put on first pillar
//     ans = max(ans,
//               solve(idx + 1, h1 + rods[idx], h2));

//     // Put on second pillar
//     ans = max(ans,
//               solve(idx + 1, h1, h2 + rods[idx]));

//     return ans;
// }

// int main()
// {
//     cin >> n;

//     rods.resize(n);

//     for (int i = 0; i < n; i++)
//         cin >> rods[i];

//     int ans = solve(0, 0, 0);

//     if (ans < 0)
//         cout << 0;
//     else
//         cout << ans;
// }