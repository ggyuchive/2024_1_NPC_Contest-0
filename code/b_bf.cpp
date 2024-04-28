#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int p, q; cin >> p >> q;
    string s; cin >> s;
    int ans[4];
    bool ta=false; bool tb=false;
    int a, b;
    for (int i = 0; i < 4; i++) {
        if (s[i] == 'A') {
            if (!ta) ans[i] = p, ta=true;
            else ans[i] = q;
        }
        else {
            if (!tb) a = i, tb=true;
            else b = i;
        }
    }
    int case_ = 0;
    int c1, c2;
    for (int i = 1; i <= 9; i++) {
        for (int j = i+1; j <= 9; j++) {
            ans[a]=i; ans[b]=j;
            bool tag = true;
            for (int k = 0; k < 3; k++) {
                if (ans[k] >= ans[k+1]) tag=false;
            }
            if (tag) {
                case_++;
                c1=i; c2=j;
            }
        }
    }
    if (case_==1) cout << c1 << ' ' << c2;
    else cout << -1;
}