#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getInt(string& s, int l, int r) {
    if (l < 0) return -1;
    if (s[l] == '0' && l < r) return -1;
    int ret = 0;
    while (l <= r) {
        ret = ret * 10 + s[l++]-'0';
    }
    if (ret > 100) return -1;
    return ret;
}

// O(C * G^2)
void solve () {
    int g; string s; // g <= 25
    cin >> g >> s;
    int n = s.size(); // n <= 75
    vector<vector<int>> dp;
    dp.resize(n+1, vector<int>(g+1, -1));
    dp[0][0] = 0;
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < g+1; j++) {
            for (int k = 1; k <= 3; k++) {
                int b1 = getInt(s, i-k, i-1);
                if (b1 >= 0 && dp[i-k][j-1] > -1) dp[i][j] = max(dp[i][j], dp[i-k][j-1] + b1);
            }
        }
    }
    //int ans = dp[n][g]/g;
    //int rem = dp[n][g]%g;
    //if (g%2 == 1 && rem > g/2) ans++;
    //if (g%2 == 0 && rem >= g/2) ans++;
    double ans = round(double(dp[n][g])/double(g));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}