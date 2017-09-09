//#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
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
vector <pair<pair<int, int>, int> > v;
vector <int> G[5005];

int par[5005];
int len[5005];
bool sortfunc(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
    if(a.first.first == b.first.first)  return (a.first.second < b.first.second);
    return a.first.first < b.first.first;
}
void dfs(int v) {
    stack<int> st;
    st.push(v);int u;
    while(!st.empty()) {
        u=st.top();
        st.pop();
        for(int i=0;i<G[u].size();i++) {
            if((len[u] + 1) > len[G[u][i]]) {
                len[G[u][i]] = len[u] + 1;
                par[G[u][i]] = u;
                st.push(G[u][i]);
            }
        }
    }
}
void dfsRec(int u) {
    for(int i=0;i<G[u].size();i++) {
        if((len[u] + 1) > len[G[u][i]]) {
            len[G[u][i]] = len[u] + 1;
            par[G[u][i]] = u;
            //cout<< u << " -> " << G[u][i] << " " << len[u] << " " << len[G[u][i]] <<endl;
            dfs(G[u][i]);
        }
    }
}


int main() {
    int n,sum=0;
    int w, h, f, s;

    vector<int> ot;
    pii pr;
    si(n);si(w);si(h);
    v.pb(mp(mp(w, h), 0));
    for(int i=0;i<n;i++) {
        si(f);si(s);
        if(f>w && s>h) {
            pr = mp(f, s);
            v.pb(mp(pr, i+1));
            G[0].pb(i+1);
        }
    }
    //cout<<v.size()<<endl;
    if(G[0].size() == 0)
    {
        cout<<"0";
    }
    else{
        sort(v.begin()+1, v.end(), sortfunc);
        for(int i=1;i<v.size();i++) {
            for(int j = i+1;j<v.size();j++) {
                if(v[i].first.first < v[j].first.first &&
                   v[i].first.second < v[j].first.second) {
                    //cout<< v[i].second << " -> " << v[j].second <<endl;
                    G[v[i].second].pb(v[j].second);
                   }
            }
        }
        par[0]=-1;
        v.erase(v.begin(), v.end());
        dfsRec(0);
        int maxi=0;
        int pos=-1;
        for(int i=1;i<n+1;i++) {
            //cout<<len[i] <<" "<<i<<endl;
            if(maxi < len[i]){
               maxi=len[i];
               pos=i;
            }
        }
        printf("%d\n", len[pos]);
        delete [] len;
        vector<int> ans;
        while(pos > 0) {
            ans.pb(pos);
            pos = par[pos];
        }
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }
}
