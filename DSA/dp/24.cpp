// now i am doing the length of the longest increasing path
// i have given a 2D array of integers corrdinates of length n and an integer k, where 0<=k<n. coordinates[i]=[xi,yi] indicates the point (xi,yi) in a 2d plane.
// An increasing path of length m is defined as a list of points (x1,y1),(x2,y2),(x3,y3),...,(xm,ym) such that
// xi < xi + 1 and yi < yi + 1 for all i where 1 <= i < m.
// (xi, yi) is in the given coordinates for all i where 1 <= i <= m.
// Return the maximum length of an increasing path that contains coordinates[k].
// lets write the approach i will use dp to find the length of the longest increasing path. i will use a 2D dp array to store the length of the longest increasing path ending at each point. i will iterate through the coordinates and for each point, i will check all previous points to see if they can form an increasing path with the current point. if they can, i will update the dp value for the current point. finally, i will return the maximum value in the dp array that contains coordinates[k].
#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    
    public:
    int n;
    vector<int> tree;
SegmentTree(int s){
    n=s;
    tree.resize(4*n+5, 0);
}
int query(int node,int l,int r, int ql,int qr){
    if(ql>r || qr<l) return 0;
    if(ql<=l && r<=qr) return tree[node];
    int mid=(l+r)/2;
    return max(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
}
void update(int node,int l,int r, int idx,int val){
    if(l==r){
        tree[node]=max(tree[node], val);
        return;
    }

    int mid=(l+r)/2;
    if(idx<=mid) update(2*node, l, mid, idx, val);
    else update(2*node+1, mid+1, r, idx, val);
    tree[node]=max(tree[2*node], tree[2*node+1]);
}
};
class Solution{
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k){
        int n=coordinates.size();
        vector<array<int,3>> points;
        for(int i=0;i<n;i++){
            points.push_back({coordinates[i][0], coordinates[i][1], i});
        }
        sort(points.begin(),points.end(),[](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        // now we find the pivot poistion
        int pos=-1;
        for(int i=0;i<n;i++){
        if(points[i][2]==k){
            pos=i;
            break;
        }
    }
vector<int>y;
for(auto &p:points) y.push_back(p[1]);
sort(y.begin(),y.end());
y.erase(unique(y.begin(),y.end()),y.end());
auto getYIndex=[&](int val){
    return lower_bound(y.begin(),y.end(),val)-y.begin()+1;
};
int m=y.size();
vector<int>dp1(n);
SegmentTree seg1(m);
for(int i=0;i<n;i++){
    int yIndex=getYIndex(points[i][1]);
    int best=0;
    if(yIndex>1) best=seg1.query(1,1,m,1,yIndex-1);
    dp1[i]=best+1;
    seg1.update(1,1,m,yIndex,dp1[i]);

}
vector<int>dp2(n);
SegmentTree seg2(m);
for(int i=n-1;i>=0;i--){
    int revYIndex=getYIndex(points[i][1])+1;
    int best=0;
    if(revYIndex>1) best=seg2.query(1,1,m,1,revYIndex-1);
    dp2[i]=best+1;
    seg2.update(1,1,m,revYIndex,dp2[i]);

}
return dp1[pos]+dp2[pos]-1;

}
};