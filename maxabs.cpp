#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N,K;
ll a[200005];
ll L[200005],R[200005];
#define INF 1e16
int main() {
  cin >> N >> K;
  for(int i=1;i<=N;i++) cin >> a[i];
  for(int i=1;i<=N;i++) L[i] += L[i-1] + a[i];
  for(int i=N;i>=1;i--) R[i] += R[i+1] + a[i];
  vector<pair<ll,int> > A(N+1),B(N+1);
  for(int i=1;i<=N;i++) {
    if(i-K < 0) A[i] = make_pair(-INF,i);
    else {
       pair<ll,int> pa;
       ll s = L[i] - L[i-K];
       if(i-1>=1 && s <= A[i-1].first) {
         pa.first = A[i-1].first;
         pa.second = min(A[i-1].second,i-K+1);
       }
       else {
         pa.first = s;
         pa.second = i-K+1;
       }
       A[i] = pa;
    }
  }
  //for(int i=1;i<=N;i++) cout << A[i].first << " " << A[i].second << endl;
  //cout << endl;
  for(int i=N;i>=1;i--) {
    if(i+K-1 > N) B[i] = make_pair(-INF,i);
    else {
        pair<ll,int> pa;
        ll s = R[i] - R[i+K];
        if(i+1<=N && s < B[i+1].first) {
            pa.first = B[i+1].first;
            pa.second = max(B[i+1].second,i);
        }
        else {
            pa.first = s;
            pa.second = i;
        }
        B[i] = pa;
    }
  }
  //for(int i=1;i<=N;i++) cout << B[i].first << " " << B[i].second << endl;
  ll maxS=-INF,maxSLInd=-1,maxSRInd=-1;
  for(int i=1;i<=N-1;i++) {
    ll sum = A[i].first + B[i+1].first;
    //cout<<sum<<" "<<maxS<<" "<<maxSLInd<<" "<<maxSRInd<<endl;
    if(maxS<sum) {
        maxS=sum;
        maxSLInd = A[i].second;
        maxSRInd = B[i+1].second;
    }
  }
  cout<<maxSLInd<<" "<<maxSRInd<<endl;
  return 0;
}
