// now i am doing the stripe , token y increase the power of the token by an integer from 0 to ai inclusive
// the two players
// i understand the question there is stripe of n+1 cells , numbered from 1 to n+1
// intially there is token with power 1 on cell number 1, and the numbers a1,a2,....,an are written on cells 1,2,...,n
// recpectively 
// two players play the game. On each move, the player performs the following actions in order
// suppose the token is on cell number i
// the player may increase the power of the token by any integer from 0 to ai inclusive
// then the player moves the token formward by any possitive integer not exceeding the token's power, such that after this action the token does not leave the stripe
// the player after whose move the token lands on cell n+1 wins
// who wins with the optimal play from both players
// input each test contatins multiple test cases. the first contatins the number of test caswes t(1<t<=10^4).
// The first line of each test case contains one integer n
//  (1≤n≤105
// ) — the number of written numbers.

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (0≤ai≤109
// ) — the numbers written on the cells.

// It is guaranteed that the sum of n
//  over all test cases does not exceed  105
// Output
// For each test case, output one integer, 1
//  or 2
//  — the number of the player who wins with optimal play. (Player 1
//  makes the first move.)
// approach we used the grid form of dp 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

struct BlockContainer {
    set<pair<int,int>> segs;
    set<pair<int,int>> lens;

    void add(int x) {
        auto it = segs.lower_bound({x + 1, -1});

        int L = x;
        int R = x;

        if (it != segs.begin()) {
            auto prv = prev(it);

            if (prv->second + 1 == x) {
                L = prv->first;
                lens.erase({prv->second - prv->first + 1, prv->first});
                segs.erase(prv);
            }
        }

        if (it != segs.end() && it->first - 1 == x) {
            R = it->second;
            lens.erase({it->second - it->first + 1, it->first});
            segs.erase(it);
        }

        segs.insert({L,R});
        lens.insert({R-L+1,L});
    }

    int longest() {
        if (lens.empty()) return 0;
        return lens.rbegin()->first;
    }

    int removeSmallestFromLongest() {
        auto it = prev(lens.end());

        int len = it->first;
        int start = it->second;

        lens.erase(it);

        auto segIt = segs.find({start,start+len-1});

        int L = segIt->first;
        int R = segIt->second;

        segs.erase(segIt);

        int ans = L;

        if (L + 1 <= R) {
            segs.insert({L+1,R});
            lens.insert({R-(L+1)+1,L+1});
        }

        return ans;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for(int i=1;i<=n;i++)
        cin >> a[i];

    vector<vector<int>> events(n + 2);

    BlockContainer bc;

    for(int k=0;k<=n;k++) {
        int pos = max(0, n + 1 - k - 1);

        if(pos >= 1)
            events[pos].push_back(k);
    }

    bool startLose = false;

    for(int i=n;i>=1;i--) {

        for(int x : events[i])
            bc.add(x);

        vector<int> losingHere;

        while(bc.longest() > a[i]) {

            int k = bc.removeSmallestFromLongest();

            losingHere.push_back(k);

            if(i == 1 && k == 1)
                startLose = true;
        }

        for(int k : losingHere) {

            int pos = i - k - 1;

            if(pos >= 1)
                events[pos].push_back(k);
        }
    }

    cout << (startLose ? 2 : 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--)
        solve();

    return 0;
}