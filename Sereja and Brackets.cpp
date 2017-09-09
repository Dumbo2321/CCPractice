/////////AC code
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int a, open, close;
    Node(int aa, int o, int c){
        a=aa;
        open = o;
        close = c;
    }
    Node(){
        a=0;
        open=0;
        close=0;
    }
};
Node segment[2000005];
string s;
void Print(Node aa)
{
    cout<<aa.a<<" "<<aa.open<<" "<<aa.close<<endl;
}
// [l,r) and idx starts from 1
void Build(int idx, int l, int r)
{
    if(r==l)
    {
        if(s[l]=='(')
            segment[idx].open = 1;
        else
            segment[idx].close = 1;
        //cout<<idx<<" "<<l<<" "<<r<<" ";
        //Print(segment[idx]);
        return;
    }
    int mid=(l+r)/2;
    Build(idx*2, l, mid);
    Build(idx*2 + 1, mid+1, r);
    int temp = min(segment[idx*2].open, segment[idx*2 + 1].close);
    segment[idx].a = segment[idx*2].a + segment[idx*2 + 1].a + temp;
    segment[idx].open = segment[idx*2].open + segment[idx*2 + 1].open - temp;
    segment[idx].close = segment[idx*2].close + segment[idx*2 + 1].close - temp;
    //cout<<idx<<" "<<l<<" "<<r<<" ";
    //Print(segment[idx]);
}
Node query(int x, int y, int l, int r, int idx)
{
    //cout<<l<<" "<<r<<" "<<idx<<" ";
    if(x>r || y<l)
    {
        Node ret(0, 0, 0);
        return ret;
    }
    if(x<=l && y>=r)    return segment[idx];
    int mid = (l+r)/2;
    Node left = query(x, y, l, mid, idx*2);
    Node right = query(x, y, mid+1, r, idx*2+1);
    int temp = min(left.open, right.close);
    int a = left.a + right.a + temp;
    int open = left.open + right.open - temp;
    int close = left.close + right.close - temp;
    Node ret(a, open, close);
    return ret;
}
int main()
{
    int q, u, v;
    Node ans;
    cin >> s;
    Build(1, 0, s.length()-1);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>u>>v;
        ans = query(u-1, v-1, 0, s.length()-1, 1);
        cout<<ans.a*2<<endl;
    }
}
