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

int main(){
    string a,b;
    cin>>a>>b;
    if(a.length()>b.length()){
        cout<<"GREATER";
    }
    else if(a.length()<b.length()){
        cout<<"LESS";
    }
    else{
        int i;
        for(i=0;i<a.length();i++){
            if(a[i]>b[i]){
                cout<<"GREATER";
                break;
            }
            else if(a[i]<b[i]){
                cout<<"LESS";
                break;
            }
        }
        if(i>=a.length()){
            cout<<"EQUAL";
        }
    }
}
