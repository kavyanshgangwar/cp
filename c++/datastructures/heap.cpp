#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
class Heap{
  public:
  vi heap;
  int n;
  Heap(vi &a){
    heap.push_back(0);
    n = a.size();
    for(int i=0;i<n;i++){
      heap.push_back(a[i]);
    }
    n++;
    for(int i=n/2;i>0;i--){
      heapify(i);
    }
  }
  void heapify(int i){
    int cur  = i;
    int left = i<<1;
    int right = (i<<1) + 1;
    if(left<n)
    if(heap[cur]<heap[left]){
      cur = left;
    }
    if(right<n)
    if(heap[cur]<heap[right]){
      cur = right;
    }
    if(cur!=i){
      int temp = heap[i];
      heap[i] = heap[cur];
      heap[cur] = temp;
      heapify(cur);
    }
  }
  void insert(int k){
    int cur = 0;
    if(heap.size()==n){
      heap.push_back(k);
      n++;
      cur = n-1;
    }else{
      heap[n] = k;
      cur=n;
    }
    int par = cur>>1;
    while(par){
      if(heap[cur]>heap[par]){
        int temp = heap[cur];
        heap[cur] = heap[par];
        heap[par] = temp;
        cur = par;
        par = par>>1;
      }else{
        break;
      }
    }
  }
  int pop(){
    if(n==1){
      return INT32_MIN;
    }
    int c = heap[1];
    heap[1] = INT32_MIN;
    heapify(1);
    n--;
    return c;
  }
};
int main(){
  int n;
  cin>>n;
  vi v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  Heap h = Heap(v);
  h.insert(10);
  for(int i=1;i<h.n;i++){
    cout<<h.heap[i]<<" ";
  }
  cout<<endl;
  cout<<h.pop()<<"\n";
  for(int i=1;i<h.n;i++){
    cout<<h.heap[i]<<" ";
  }
  cout<<endl;
}