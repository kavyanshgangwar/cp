#include <bits/stdc++.h>
using namespace std;
int a[10];
int partition(int low,int high){
  int pivot = a[high];
  int p = low -1;
  for(int i=low;i<high;i++){
    if(pivot>a[i]){
      p++;
      int temp = a[i];
      a[i] = a[p];
      a[p] = temp;
    }
  }
  p++;
  a[high] = a[p];
  a[p] = pivot;
  return p;
}
void quicksort(int low,int high){
  if(low<high){
    int p = partition(low,high);
    quicksort(low,p-1);
    quicksort(p+1,high);
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  quicksort(0,n-1);
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}