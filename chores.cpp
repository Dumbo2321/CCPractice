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
    int ch[2005];
    int main() {
        int n,a,b,sum;
        si(n);si(a);si(b);
        for(int i=0;i<n;i++)    si(ch[i]);
        sort(ch, ch+n);
        sum = ch[b]-ch[b-1];
        cout<<sum;
    }
