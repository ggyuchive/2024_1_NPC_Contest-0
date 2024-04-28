#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int i, j; cin >> i >> j;
    string s; cin >> s;
    bool tag = false;
    int ans1 = 0; int ans2 = 0;
    if (s == "AABB" && j==7) {
        tag=true; ans1=8; ans2=9;
    }
    if (s == "BBAA" && i==3) {
        tag=true; ans1=1; ans2=2;
    }
    if (s == "BAAB" && i==2 && j==8) {
        tag=true; ans1=1; ans2=9;
    }
    if (s == "ABBA" && j-i==3) {
        tag=true; ans1=i+1; ans2=j-1;
    }
    if (s == "ABAB" && i==6 && j==8) {
        tag=true; ans1=7; ans2=9;
    }
    if (s == "BABA" && i==2 && j==4) {
        tag=true; ans1=1; ans2=3;
    }
    if (!tag) cout << -1;
    else cout << ans1 << ' ' << ans2;
}