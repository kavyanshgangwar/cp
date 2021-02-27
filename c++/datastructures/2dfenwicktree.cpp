#include <bits/stdc++.h>
using namespace std;
class FenwickTree2D{
  private:
    vector<vector<int> > ft;
  public:
    int LSOne(int a){
      return (a&-a);
    }
    FenwickTree2D(int n,int m){
      ft.assign(n+1,vector<int> (m+1,0));
    }
    void adjust(int x,int y,int value){
      for(int i=x;i<ft.size();i+=LSOne(i))
      for(int j=y;j<ft[0].size();j+=LSOne(j))
      ft[i][j]+=value;
    }
    int rsq(int x,int y){
      int ans=0;
      for(int i=x;i;i-=LSOne(i))
      for(int j=y;j;j-=LSOne(j))
      ans+=ft[i][j];
      return ans;

    }
    int rsq(int x1,int y1,int x2,int y2){
      if(x1==1){
        if(y1==1){
          return rsq(x2,y2);
        }else{
          return rsq(x2,y2)-rsq(x2,y1-1);
        }
      }else{
        if(y1==1){
          return rsq(x2,y2)-rsq(x1-1,y2);
        }else{
          return rsq(x2,y2)-rsq(x1-1,y2)-rsq(x2,y1-1)+rsq(x1-1,y1-1);
        }
      }
    }

};
int main(){
  int n,m;
  cin>>n>>m;
  int a;
  FenwickTree2D f = FenwickTree2D(n,m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a;
      f.adjust(i+1,j+1,a);
    }
  }
  cout<<f.rsq(1,1,2,2)<<endl;
  cout<<f.rsq(1,2,3,3)<<endl;
  cout<<f.rsq(2,1,2,2)<<endl;
  cout<<f.rsq(2,2,3,3)<<endl;
}