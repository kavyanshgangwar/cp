#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the movingTiles function below.
 */
void movingTiles(int l, int s1, int s2, vector<long long> &queries,vector<double> &v) {
    /*
     * Write your code here.
     */
    
    double k = abs(s1-s2);
    k/=sqrt(2);
    double l1 = (double)l;
    for(int i=0;i<queries.size();i++){
        v[i] = ((l1-sqrt((double)queries[i]))*1.1)/(k*1.1);
    }
}
int main(){
    int l,s1,s2;
    cin>>l>>s1>>s2;
    int q;
    cin>>q;
    vector<long long> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    vector<double> v(q,0);
    movingTiles(l,s1,s2,queries,v);
    for(auto x:v){
        cout<<x<<endl;
    }
}