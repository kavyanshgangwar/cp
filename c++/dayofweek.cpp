#include <bits/stdc++.h>
using namespace std;
int main(){
  int d,m,y,c;
  cin>>d>>m>>y;
  tm time_in = {0,0,0,d,m-1,y-1900};
  time_t time_temp = mktime(&time_in);
  const tm* time_out = localtime(&time_temp);
  cout<<time_out->tm_wday<<endl;
}