// now i am doing the maximum toatl subarray value 11
// this is advanced version maximum total subarray value 
// in last code we use loop 
// i create the maxvalue and min value then used loop if nums[i]>maxvalue put the value of nums[i] into maxvalue simulare to min valu nums[i]<minval
// return int64(maxvalue-minvalue)*int64(k)
// now the constraints we large
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    struct SegmentTree
    {
    int n;
    vector<int> SegMin, SegMax;
    SegmentTree(vector<int> &nums){
        n=nums.size();
        SegMin.resize(2*n);
        SegMax.resize(2*n);
    
    for(int i=0;i<n;i++){
        SegMin[n+i]=nums[i];
        SegMax[n+i]=nums[i];
    }
    for(int i=n-1;i>0;i--){
        SegMin[i]=min(SegMin[2*i],SegMin[2*i+1]);
        SegMax[i]=max(SegMax[2*i],SegMax[2*i+1]);
    }
    }
pair<int ,int>query(int l,int r){
    int minVal=INT_MAX;
    int maxVal=INT_MIN;
    l+=n;
    r+=n+1;
    while(l<r){
        if(l&1){
            minVal=min(minVal,SegMin[l]);
            maxVal=max(maxVal,SegMax[l]);
            l++;
        }
        if(r&1){
            r--;
            minVal=min(minVal,SegMin[r]);
            maxVal=max(maxVal,SegMax[r]);
        }
        l>>=1;
        r>>=1;
    }
    return {minVal,maxVal};
}
    
};
long long maxTotalValue(vector<int>nums,int k){
    int n=nums.size();
    auto[minVal,maxVal]=minmax_element(nums.begin(),nums.end());
    int globalMin=*minVal;
    int globalMax=*maxVal;
    int value=globalMax-globalMin;
    int minpos=minVal-nums.begin();
    int maxpos=maxVal-nums.begin();
    int leftpos=min(minpos,maxpos);
    int rightpos=max(minpos,maxpos);
    long long count=1ll*(leftpos+1)*(n-rightpos);
    if(count>=k){
        return 1ll*value*k;
    }
    long long ans=count*value;

    k-=count;
    SegmentTree st(nums);
priority_queue<pair<int,pair<int,int>>> pq;

for(int l=leftpos+1;l<n;l++){
    auto [mn,mx]=st.query(l,n-1);
    pq.push({mx-mn,{l,n-1}});
}

for(int l=0;l<=leftpos;l++){
    auto [mn,mx]=st.query(l,rightpos-1);
    pq.push({mx-mn,{l,rightpos-1}});
}
while(k>0 && !pq.empty()){

    auto cur = pq.top();
    pq.pop();

    int val = cur.first;
    int l   = cur.second.first;
    int r   = cur.second.second;

    if(val==0) break;

    ans += val;
    k--;

    if(l < r){

        auto [mn,mx] = st.query(l,r-1);

        pq.push({
            mx-mn,
            {l,r-1}
        });
    }
}

    return ans;

}
};
