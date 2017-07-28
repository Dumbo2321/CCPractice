#include<bits/stdc++.h>
using namespace std;

class Name
{
    private:
        string str;
    public:
        Name(string s){     str=s;  }

        int FindMaxR()
        {
            int len=str.length();
            int max_as_of_now=0;
            int max_over_all=0;
            int val,start,s,e,r,k,l,R,K;
            R=0;K=0;s=0;e=0;
            for(int i=0;i<len;i++)
            {
                val=(str[i]=='R')?-1:1;
                if(val==1)  K++; else R++;
                max_as_of_now+=val;
                if(max_over_all<max_as_of_now)
                {
                    max_over_all=max_as_of_now;
                    start=s;
                    e=i;
                }
                if(max_as_of_now<0){
                    max_as_of_now=0;
                    s+=1;
                }
            }
            if(K==0)    return 0;
            l=e-s+1;
            r=(int)(-(max_over_all-l)/2);
            k=(int)((max_over_all+l)/2);
            //cout<<"s e l r k R K"<<endl;
            //cout<<s<<" "<<e<<" "<<l<<" "<<r<<" "<<k<<" "<<R<<" "<<K<<endl;
            return R+k-r;
        }
};
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        Name nm(s);
        cout<<nm.FindMaxR()<<endl;
    }

}
