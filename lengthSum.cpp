 #include <bits/stdc++.h>
using namespace std;

int main(){
    int m, s;
    cin>>m>>s;
    if(s==0 && m==1) {
        cout<<"0 0";
        return 0;
    }
    if(9*m<s || s==0) {
        cout<<"-1 -1";
        return 0;
    }
    string mn(m, '0');
    string mx(m, '0');
    int k=s;
    int j=m-1;
    while(j>=0) {
        mn[j]=k>9?9+'0':k+'0';
        k-=9;
        k=max(k,0);
        j--;
    }
    //cout<<mn<<endl;
    if(mn[0]=='0') {
        mn[0]=1+'0';
        j=1;
        while(mn[j]=='0') j++;
        //cout<<j<<endl;
        mn[j]=mn[j]-1;
    }
    cout<<mn<<" ";
    k=s,j=0;
    while(j<m) {
        mx[j]=(k>9)?9+'0':k+'0';
        k=max(k-9,0);
        j++;
    }
    cout<<mx<<endl;
    return 0;
}
