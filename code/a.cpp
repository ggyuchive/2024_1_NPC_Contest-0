#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n, q; cin >> n >> q;
    map<string,int> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s] = i;
    }
    for (int i = 0; i < q; i++) {
        string a, b; cin >> a >> b;
        int p = mp[a]; int q = mp[b];
        cout << max(p,q)-min(p,q)-1 << '\n';
    }
}