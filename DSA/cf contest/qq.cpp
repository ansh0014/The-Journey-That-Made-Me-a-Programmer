// today i am giving the educationl codeforce div 2
// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int k;
//     cin>>k;
//     int cnt2 = 0;

//     for(int i = 0; i < k; i++){
//         long long x;
//         cin >> x;

//         if(x >= 3){
//             cout << "YES\n";

//             for(int j = i + 1; j < k; j++){
//                 cin >> x;
//             }
//             return;
//         }

//         if(x >= 2)
//             cnt2++;
//     }

//     if(cnt2 >= 2)
//         cout << "YES\n";
//     else
//         cout << "NO\n";
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while(t--){
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> pref1(n + 1, 0), pref2(n + 1, 0), pref3(n + 1, 0);

//     for (int i = 1; i <= n; i++)
//     {
//         int x;
//         cin >> x;

//         pref1[i] = pref1[i - 1];
//         pref2[i] = pref2[i - 1];
//         pref3[i] = pref3[i - 1];

//         if (x == 1)
//             pref1[i]++;
//         else if (x == 2)
//             pref2[i]++;
//         else
//             pref3[i]++;
//     }

//     vector<int> val(n + 1);

//     for (int i = 0; i <= n; i++)
//     {
//         val[i] = pref1[i] + pref2[i] - pref3[i];
//     }

//     vector<int> sufMax(n + 2, INT_MIN);

//     sufMax[n - 1] = val[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         sufMax[i] = max(sufMax[i + 1], val[i]);
//     }

//     for (int i = 1; i <= n - 2; i++)
//     {
//         int leftScore = pref1[i] - pref2[i] - pref3[i];

//         if (leftScore >= 0 && sufMax[i + 1] >= val[i])
//         {
//             cout << "YES\n";
//             return;
//         }
//     }

//     cout << "NO\n";
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(n);

//     for(int i = 0; i < n; i++)
//         cin >> a[i];

//     vector<int> freq;

//     int cnt = 1;
//     for(int i = 1; i < n; i++){
//         if(a[i] == a[i - 1]){
//             cnt++;
//         }
//         else{
//             freq.push_back(cnt);
//             cnt = 1;
//         }
//     }
//     freq.push_back(cnt);

//     sort(freq.begin(), freq.end());

//     int m = freq.size();

//     vector<long long> suf(m + 1, 0);

//     for(int i = m - 1; i >= 0; i--){
//         suf[i] = suf[i + 1] + freq[i];
//     }

//     int ans = 0;

    
//     {
//         long long sum = suf[0];
//         int blocks = m;
//         int mn = freq[0];

//         long long rem = 1LL * k - sum;

//         if(rem % blocks == 0){
//             long long d = rem / blocks;
//             if(mn + d >= 1)
//                 ans++;
//         }
//     }


//     int i = 0;

//     while(i < m){
//         int cur = freq[i];

//         while(i < m && freq[i] == cur)
//             i++;

//         if(i == m)
//             break;

//         long long sum = suf[i];
//         int blocks = m - i;
//         int mn = freq[i];

//         long long rem = 1LL * k - sum;

//         if(rem % blocks == 0){
//             long long d = rem / blocks;
//             if(mn + d >= 1)
//                 ans++;
//         }
//     }

//     cout << ans << "\n";
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while(t--){
//         solve();
//     }

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
