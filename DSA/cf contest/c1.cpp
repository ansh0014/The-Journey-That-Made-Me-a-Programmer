// // today i am giving my first contest in codeforces
// // i am giving the contest in div 2
// // first question is course wishes
// // question discription is qwqkawaii is registering for n(n<=50).in the registrationg system he can submit a course wish for each course, which indicates his priority for taking that course.
// // course whishes are divided into k+1(k<=20) priority levels where level 1 is the highest priority and level k+1 is the lowest
// // the first k wish levels have capacity limits: for each 1<=i<=k, at most ai courses can be assigned wish level i. note that wish le
// // lets understand the question
// // i have to move all courses to whish level k+1 (lowest priority) using the most 1000 operation 
// // pick any course i , increase it wish level b i by 1
// // edge case 
// // 1) every opration ,capacity limits mus hold
// // 2) a course already at level k+1 cannot be selected
// // 3) at most 1000 operation totall
// // apprach i understand the question i have to move all courses to whish level k+1 (lowest priority) using the most 1000 operation
// // i have to pick any course i , increase it wish level b i by 1
// // this question is simple i have to do the operation until all course are at level k+1 (lowest priority) and i have to check the capacity limit after every operation if the capacity limit is not hold then i have to return -1
// // simple example 
// // 3 courses , k=2 so levels are 1,2,3

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, k;
//         cin >> n >> k;
//         vector<int> a(k+2, INT_MAX), b(n+1);
//         for(int i = 1; i <= k; i++) cin >> a[i];
//         for(int i = 1; i <= n; i++) cin >> b[i];
//         vector<int> ops;
//         for(int iter = 0; iter < 1000; iter++) {
//             bool done = true;
//             for(int i = 1; i <= n; i++) if(b[i] != k+1) { done = false; break; }
//             if(done) break;
            
//             for(int i = 1; i <= n; i++) {
//                 if(b[i] == k+1) continue;
//                 int nxt = b[i] + 1;
//                 int cnt = 0;
//                 for(int j = 1; j <= n; j++) if(b[j] == nxt) cnt++;
//                 if(nxt == k+1 || cnt < a[nxt]) {
//                     b[i]++;
//                     ops.push_back(i);
//                 }
//             }
//         }
        
//         bool ok = true;
//         for(int i = 1; i <= n; i++) if(b[i] != k+1) { ok = false; break; }
        
//         if(!ok) cout << -1 << "\n";
//         else {
//             cout << ops.size() << "\n";
//             for(int x : ops) cout << x << " ";
//             cout << "\n";
//         }
//     }
// }
// lets move to next question 
// i have give array of n integers
//  the parameters k (minimum interval length)
// A set M={p,q}(two numbers you can mod by)
// we can do this any many time as we want 
// 1) lets take example an interval [l,r] where r-1+1>=k(length at least k)
// 2) pick either p or q as you modulus m
// 3) replace each element in [l,r] with a[i]%m
// what i have to goal 
// minimize the total sum of array after all operation
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    // what does this line do
    // it syncs the cin and cout with the scanf and printf functions
    // it makes the input/output faster
    // i can use alternative
    // i can use scanf and printf instead of cin and cout
     int t;
     cin>>t;
     while(t--){
        long long n,k,p,q;
        cin>>n>>k>>p>>q;
        long long ans=0;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            ans+=min(x%p,x%q);
        }
        cout<<ans<<"\n";
     }
     return 0;
}