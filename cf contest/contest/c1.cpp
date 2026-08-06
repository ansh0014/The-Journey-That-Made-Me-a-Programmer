#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int blocks = n - k;

    vector<int> len(blocks, 1);

    int zeroBlocks = (blocks + 1) / 2;
    int oneBlocks = blocks / 2;

    int zeros = (n + 1) / 2;
    int ones = n / 2;

    int extra0 = zeros - zeroBlocks;
    int extra1 = ones - oneBlocks;

    if (blocks > 0)
        len[0] += extra0;

    if (blocks > 1)
        len[1] += extra1;
    else if (extra1 > 0) {
        cout << -1 << '\n';
        return;
    }

    string ans;

    char cur = '0';
    for (int i = 0; i < blocks; i++) {
        ans.append(len[i], cur);
        cur = (cur == '0') ? '1' : '0';
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}