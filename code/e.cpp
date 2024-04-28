#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    string s; cin >> s;
    int ans = 0;
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]-'A']++;
        ans = max(ans, max({cnt[0],cnt[1],cnt[2]})-min({cnt[0],cnt[1],cnt[2]}));
    }
    cout << ans;
}