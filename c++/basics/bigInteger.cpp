#include <bits/stdc++.h>
using namespace std;
#define int __int128
int r[100][100];
int p[100];
bool isPrime(int x){
  for(int i=2;i*i<=x;i++){
    if(x%i==0)return false;
  }
  return true;
}
int bin_exp(int a,int p,int m){
  if(p==0){
    return 1;
  }
  int k = bin_exp(a,p/2,m);
  k = (k*k)%m;
  if(p&1){
    k = (k*a)%m;
  }
  return k;
}
int modInv(int a,int m){
  return bin_exp(a,m-2,m);
}
void init(){
      int i = 0;
      for(int x=1000*1000*1000;x<1e18;x++){
        if(isPrime(x)){
          p[i]=x;
          i++;
        }
        if(i==100){
          break;
        }
      }
      for(i=0;i<100;i++){
        for(int j=0;j<100;j++){
          if(i!=j)
          r[i][j] = modInv(p[i],p[j]);
        }
      }
    }
class BigInteger{
  private:
    int base = 1000*1000*1000;
    int a[100]={0};
    int n=100;
  public:
    BigInteger(){}
    BigInteger(int k){
      for(int i=0;i<n;i++){
        a[i] = k%p[i];
      }
    }
    BigInteger add(BigInteger b){
      BigInteger c = BigInteger();
      for(int i=0;i<n;i++){
        c.a[i] = (a[i]+b.a[i])%p[i];
      }
      return c;
    }
    string getValue(){
      int val[100][100];
      memset(val,0,sizeof(val));
      int x[100]={0};
      for(int i=0;i<n;i++){
        val[i][99]=1;
        x[i]=a[i];
        for(int j=0;j<i;j++){
          x[i] = ((x[i]-x[j])*r[j][i])%p[i];
          if(x[i]<0){
            x[i] = (x[i]+p[i])%p[i];
          }
          int rem = 0;
          for(int k=99;k>=0;k--){
            val[i][k] *= p[j];
            val[i][k] +=rem;
            rem = val[i][k]/base;
            val[i][k]=val[i][k]%base;
          }
        }
        int rem=0;
        for(int k=99;k>=0;k--){
            val[i][k] *= x[i];
            val[i][k] +=rem;
            rem = val[i][k]/base;
            val[i][k]= val[i][k]%base;
        }
      }
      for(int i=1;i<n;i++){
        int rem=0;
        for(int j=99;j>=0;j--){
          val[i][j]+=val[i-1][j];
          val[i][j]+=rem;
          rem = val[i][j]/base;
          val[i][j]=val[i][j]%base;
        }
      }
      string s="";
      int i=0;
      while(val[99][i]==0)i++;
      bool done=false;
      for(i;i<n;i++){
        string z = to_string((long)val[99][i]);
        while(z.size()<9 &&done){
          z = "0"+z;
        }
        s+=z;
        done=true;
      }
      return s;
    }
};
signed main(){
  init();
  long long n = 100;
  cin>>n;
  BigInteger b =BigInteger(n);
  for(int i=0;i<100;i++){
    b = b.add(b);
    cout<<b.getValue()<<endl;
  }
  cout<<b.getValue()<<endl;
}