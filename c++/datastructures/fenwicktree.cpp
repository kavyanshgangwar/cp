#include <bits/stdc++.h>
using namespace std;
class FenwickTree{
  private:
    vector<int> ft;
  public:
    FenwickTree(int n){
      ft.assign(n+1,0);
    }
    int LSOne(int a){return (a&-a);}
    int rsq(int a){
      int ans=0;
      for(;a;a-=LSOne(a))ans+=ft[a];
      return ans;
    }
    int rsq(int a,int b){
      if(a!=1){
        return rsq(b)-rsq(a-1);
      }else{
        return rsq(b);
      }
    }
    void adjust(int k,int value){
      for(;k<ft.size();k+=LSOne(k))ft[k]+=value;
    }
};
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  FenwickTree f =FenwickTree(n);
  for(int i=0;i<n;i++){
    f.adjust(i+1,a[i]);
  }
  cout<<f.rsq(2,4)<<endl;
  f.adjust(2,10);
  cout<<f.rsq(2,4)<<endl;

  /*
  * for range update and point query adjust value to l and 
  * -value to r+1, so the point will give the correct value
  * no change in query function.
  */
  /*
  * for range update and range query two arrays are used.
  */
}