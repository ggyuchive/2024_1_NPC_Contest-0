#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 1000001
ll mod = 1e9+7;
ll fac[MAX];
ll zb[32];

ll divmod(ll a, ll b) { // (a/b) % mod = (a * b^(mod-2)) % mod
    ll ret = a;
    ll z = mod-2;
    zb[1] = b;
    for (int i = 2; i < 32; i++) zb[i] = (zb[i-1]*zb[i-1]) % mod;

    int i = 1;
    while (z) {
        if (z&1) ret = (ret * zb[i]) % mod;
        z>>=1; i++;
    }
    return ret;
}

ll comb(ll a, ll b) { // a H b = (a+b-1) C b
    a = a + b - 1;
    ll x = fac[a];
    ll y = (fac[b] * fac[a-b]) % mod;
    return divmod(x, y);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n, x, y; cin >> n >> x >> y;
    fac[0] = 1; zb[0] = 1;
    for (ll i = 1; i < MAX; i++) {
        fac[i] = (fac[i-1] * i) % mod;
    }
    ll ans = 0;
    for (ll m = 1; m <= n; m++) {
        if (n-m*x>=0 && n-m*y>=0) {
            ans = (ans + (comb(m,n-m*x) * comb(m,n-m*y)) % mod) % mod;
        }
    }
    cout << ans;
}