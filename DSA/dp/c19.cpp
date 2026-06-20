// now i am doning the one question
// i have given a [convex ploygon] find min cost tringulation cost of Diagonal =sin(length)
#include <bits/stdc++.h>
using namespace std;

double cost(pair<double,double> a, pair<double,double> b){
    double dx = a.first - b.first;
    double dy = a.second - b.second;

    double len = sqrt(dx * dx + dy * dy);

    return sin(len);
}

void solve(){
    int n;
    cin >> n;

    vector<pair<double,double>> p(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> p[i].first >> p[i].second;
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));

    for(int len = 3; len <= n; len++){

        for(int start = 1; start + len - 1 <= n; start++){

            int end = start + len - 1;

            if(len == 3){
                dp[start][end] = 0;
                continue;
            }

            double ans = 1e18;

            for(int k = start + 1; k < end; k++){

                double triangleCost =
                    cost(p[start], p[k]) +
                    cost(p[k], p[end]) +
                    cost(p[start], p[end]);

                ans = min(
                    ans,
                    dp[start][k] +
                    dp[k][end] +
                    triangleCost
                );
            }

            dp[start][end] = ans;
        }
    }

    cout << fixed << setprecision(10) << dp[1][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    while(t--){
        solve();
    }

    return 0;
}