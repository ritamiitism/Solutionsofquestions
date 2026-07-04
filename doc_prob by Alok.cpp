#include <bits/stdc++.h>
using namespace std;

double rec(int step, int node,
           vector<vector<int>> &radj,
           vector<vector<double>> &dp,
           map<pair<int,int>, double> &prob) {
    if (step == 0) {
        return (node == 1 ? 1.0 : 0.0);
    }

    if (dp[node][step] != -1.0) return dp[node][step];

    double sum = 0.0;
    for (auto &x : radj[node]) {
        sum += prob[{x, node}] * rec(step - 1, x, radj, dp, prob);
    }

    return dp[node][step] = sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, e, time;
        cin >> n >> e >> time;

        int steps = time / 10;

        vector<vector<int>> adj(n + 1), radj(n + 1);
        vector<vector<double>> dp(n + 1, vector<double>(steps + 1, -1.0));
        map<pair<int,int>, double> prob;

        for (int i = 0; i < e; i++) {
            int u, v;
            double p;
            cin >> u >> v >> p;
            adj[u].push_back(v);
            radj[v].push_back(u);
            prob[{u, v}] = p;
        }

        int bestNode = 1;
        double bestProb = rec(steps, 1, radj, dp, prob); // in case only one node matters

        for (int i = 1; i <= n; i++) {
            double cur = rec(steps, i, radj, dp, prob);
            if (cur > bestProb) {
                bestProb = cur;
                bestNode = i;
            }
        }

        cout << bestNode << " " << fixed << setprecision(6) << bestProb << "\n";
    }

    return 0;
}