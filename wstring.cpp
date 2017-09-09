#include<bits/stdc++.h>
using namespace std;

int f[10005][26];
int Process(string s)
{
    vector<int > pos;
    memset(f,0,sizeof f);
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            f[i+1][j]=f[i][j];
        }
        if(s[i]!='#')
            f[i+1][s[i]-'a']++;
        else
            pos.push_back(i+1);
    }
    if(pos.size()<3) return 0;
    int result=0;
    for(int i=0;i<pos.size()-2;i++)
    {
        int sum1,sum2,sum3,sum4;
        sum1=-1;sum2=-1;sum3=-1;sum4=-1;
        for(int j=0;j<26;j++)
        {
            sum1=max(sum1, f[pos[i]-1][j]);
        }
        for(int j=0;j<26;j++)
        {
            sum2=max(sum2, f[pos[i+1]-1][j]-f[pos[i]-1][j]);
        }
        for(int j=0;j<26;j++)
        {
            sum3=max(sum3, f[pos[i+2]-1][j]-f[pos[i+1]-1][j]);
        }
        for(int j=0;j<26;j++)
        {
            sum4=max(sum4, f[s.length()][j]-f[pos[i+2]-1][j]);
        }
        if(sum1==0) sum1 = -10000000;
        if(sum2==0) sum2 = -10000000;
        if(sum3==0) sum3 = -10000000;
        if(sum4==0) sum4 = -10000000;
        result=max(result, sum1+sum2+sum3+sum4+3);
    }
    return max(result,0);
}

int main()
{
    int t;string s;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<Process(s)<<endl;
    }
}
