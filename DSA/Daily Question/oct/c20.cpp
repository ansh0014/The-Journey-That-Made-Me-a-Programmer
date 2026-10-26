// now i am doing the sum of squared differences
// i have given two poistive 0-indexed integer array nums1 and nums2, both of lenght n.
// teh usm of squered difference of array nums1 and nums2 is defined as the sum of (nums1[i]-nums2[i])^2 for each 0<=i<n
// i have given two integers k1 and k2. in one operation, i can choose
// approach we used the simple greedy and loop to solve this problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diffs(n);

        for (int i = 0; i < n; i++) {
            diffs[i] = abs((long long)nums1[i] - nums2[i]);
        }

        sort(diffs.rbegin(), diffs.rend());

        long long total = accumulate(diffs.begin(), diffs.end(), 0LL);

    if(k>=total) return (k-total)%2;
    vector<long long> pre(n);
    pre[0]=diffs[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+diffs[i];
    }
for(int i=0;i<n;i++){
    long long next=(i+1<n)?diffs[i+1]:0;
    long long cost=pre[i]-(i+1ll)*next;
    if(cost>=k) {
        k-=cost;
    }
    else{
        long long r=pre[i]-k;
        long long t=r/(i+1LL);
        long long rem=r%(i+1LL);
        long long ans=0;
        for(int j=0;j<=i;j++){
          long long d =t+(j<rem?1:0);
          ans+=d*d;
        }
        for(int j=i+1;j<n;j++){
            ans+=diffs[j]*diffs[j];
        }
        return ans;
    }
}
long long ans=0;
for(long long d:diffs){
    ans+=d*d;
}
return ans;
    }
};