for(int i=1;i<n;i++){
  for(int j=0;j<log(i);j++){
    cout<<j;
  }
}
// O(nlog(n))
int j=0;
for(int i=0;i<n;i+=j){
  j++;
}
/*
i=0 j=1
i=1 j=2
i=3 j=3
i=6 j=4
i=10
i = (k+1)k/2 =n => sqrt(n)
O(sqrt(n))
*/

for(int i=1;i<n;i*=2){
  cout<<i;
}
// O(log(n))

for(int k=n;k;k/=2)cout<<k;
// O(log(n))

for(int i=0;i<n;i++){
  cout<<i;
}
// O(n)

int k=n;
int i=0;
while(k){
  while(k+i<n && k+i<4){
    i+=k;
  }
  k/=2;
}
// O(log(n))

/* n = 10
k = 5
i = 5
k = 2
i = 7
i = 9
k = 1
k = 0
*/

for(int i=n;i>=0;i--){
  cout<<i;
}
// O(n)

/*
 n < 10^18 = O(log(n))
 n < 10^14 = O(sqrt(n))
 n < 10^8 = O(n)
 n < 5* 10^6 = O(nlog(n))
 n < 10^4 = O(n^2)
 n < 400 = O(n^3)
 n < 100 = O(n^4)
 n < 25 = O(2^n)
 n < 10 = O(n!)
 */
 
 // vector
 // stack
 // queue
 // map
 // set
 // pair
 // priority_queue

 // recursion
/*
base case
recursive case f(i) = f(i-1)+f(i-2)
state f(i,j) = max(f(i+1,j),f(i,j+1));
*/

/*
recursion tree
masters theorem
*/

// fib, fac
// n*2 , 2*1, find total possible ways to put tiles in array


// Quick sort

// Merge sort

// codeforce round 710 div 3