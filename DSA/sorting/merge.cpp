// now we are doing the merge sort
#include<bits/stdc++.h>
using namespace std;
void ms(vector<int>&arr, int l, int r){
    if(l==r) return ;
    int mid=(l+r)/2;
    ms(arr,l,mid);
    ms(arr,mid+1,r);
    merge(arr,l,mid,r);
}
void merge(vector<int>&arr, int l, int mid, int r){
    vector<int>temp;
    int i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=l;k<=r;k++){
        arr[k]=temp[k-l];
    }
}