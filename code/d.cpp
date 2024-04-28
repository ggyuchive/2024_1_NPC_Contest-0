#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n; cin >> n;
    int pos[n];
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pos[a-1] = i;
    }
    int rev = 0;
    for (int i = 0; i < n-1; i++) {
        if (pos[i] > pos[i+1]) rev++;
    }
    int ans = 0;
    while (rev) {
        ans++;
        rev >>= 1;
    }
    cout << ans;
}