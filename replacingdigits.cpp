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
string num;
string sec;
int main(){
    int n,m;
    cin>>num;
    cin>>sec;
    n=num.length();
    m=sec.length();
    sort(sec.begin(), sec.end());
    int j=0;
    for(int i=m-1;i>=0;i--){
        char current = sec[i];
        while(j<n){
            if(num[j]<current){
                num[j++]=current;
                break;
            }
            j++;
        }
        if(j>=n)
            break;
    }
    cout<<num;
}
