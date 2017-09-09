#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAXN 100002
vector<pair<int,int> > v[MAXN];
struct compare {
 bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
   return a.second < b.second;
 }
};
priority_queue<pair<int,int> ,vector<pair<int,int> >,compare> pq;
int main() {
  int t;
  int N,d,D,T,S;
  scanf("%d",&t);
  while(t--) {
    scanf("%d %d",&N,&d);
    for(int i=0;i<MAXN;i++) v[i].clear();
    for(int i=0;i<N;i++) {
        scanf("%d %d %d",&D,&T,&S);
        v[D].push_back(make_pair(T,S));
    }
    for(int i=1;i<=d;i++) {
       for(int j=0;j<v[i].size();j++) {
          pair<int,int> p = v[i][j];
          pq.push(p);
       }
       if(!pq.empty()) {
           pair<int,int> pa = pq.top();
           pq.pop();
           pa.first -= 1;
           if(pa.first > 0) {
              pq.push(pa);
           }
       }
    }
    ll res = 0;
    while(!pq.empty()) {
        pair<int,int> pa = pq.top();
        pq.pop();
        res += (ll)pa.first*(ll)pa.second;
    }
    printf("%lld\n",res);
  }
  return 0;
}
