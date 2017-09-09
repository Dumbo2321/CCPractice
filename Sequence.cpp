#include <bits/stdc++.h>
#define ll             long long
#define Max(a,b)       ((a)>(b)?(a):(b))
#define Min(a,b)       ((a)<(b)?(a):(b))
#define si(a)          scanf("%d",&a)
#define pii            pair <int, int>
#define mp             make_pair
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define mem(a,v)       memset(a,v,sizeof(a))
#define MAX 2007
#define MOD 100000007
#define LG  16
using namespace std;
ll a[100005];
ll pos[100005];
ll neg[100005];
int main(){
    int n;
    ll sp,sn,addp,addn;
    sp=0;sn=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pos[i]=pos[max(i-1,0)] + a[i];
        neg[i]=neg[max(i-1,0)] + a[i];
        if(i%2==0){

            if(pos[i]<=0){
                sp+=abs(pos[i])+1;
                pos[i]=1;
            }
            if(neg[i]>=0){
                sn+=abs(neg[i])+1;
                neg[i]=-1;
            }
        }
        else{

            if(pos[i]>=0){
                sp+=abs(pos[i])+1;
                pos[i]=-1;
            }
            if(neg[i]<=0){
                sn+=abs(neg[i])+1;
                neg[i]=1;
            }
        }
    }
    cout<<min(sn,sp);
}
