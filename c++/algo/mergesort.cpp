#include <bits/stdc++.h>
using namespace std;
int a[10];
void merge(int low,int mid,int high){
  int a1[mid-low+2];
  for(int i=low;i<=mid;i++){
    a1[i-low]=a[i];
  }
  a1[mid-low+1]=INT32_MAX;
  int a2[high-mid+1];
  for(int i=mid+1;i<=high;i++){
    a2[i-mid-1]=a[i];
  }
  a2[high-mid]=INT32_MAX;
  int k=0;
  int j=0;
  for(int i=low;i<=high;i++){
    if(a1[k]>a2[j]){
      a[i]=a2[j];
      j++;
    }else{
      a[i]=a1[k];
      k++;
    }
  }
}
void mergesort(int low, int high){
  if(low<high){
    int mid = (low+high)/2;
    mergesort(low, mid);
    mergesort(mid+1,high);
    merge(low,mid,high);
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  mergesort(0,n-1);
  for(int i=0;i<n;i++)cout<<a[i]<<" ";
  cout<<endl;
}