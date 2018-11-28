#include<bits/stdc++.h>

#define CIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
/*
    Bismillahir Rahmanir Rahim
    SPOJ NAJPF - Pattern Find
    Solved by KMP Algorithm
    Coder : Masud Parves
    ZHSUST,CSE 9th Batch
    I Love Code More than Sharks Love Blood <3
*/
 
 
using namespace std;
 
 
int f[1000005];
int cntZ,cntNZ;
 
 
void kmp_failure(string p)
{
    memset(f, 0, sizeof(f));
    f[0]=0;
    int j=0;
 
    for(int i=1 ; i<p.length() ; i++)
    {
        if(p[i]==p[j])
        {
            f[i]=j+1;
            j++;
        }
        else
        {
            while(j!=0)
            {
                j=f[j-1];
                if(p[i]==p[j])
                {
                    f[i]=j+1;
                    j++;
                    break;
                }
            }
        }
    }
    //cout<<cntNZ<<endl;
}
 
int n;
 
 
int main()
{
 
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    CIN;
    int t;
    cin>>t;
    for(int j=1 ; j<=t ; j++)
    {
        cin>>n;
        string str;
        cin>>str;
        kmp_failure(str);
        cout<<"Test case #"<<j<<endl;
        bool test=0;
        for(int i=1; i<n; i++)
        {
            int length=i+1;
            int aa=f[i];
            int temp=length-aa;
            if((length)%temp==0 && length!=temp)
            {
                cout<<length<<" "<<length/temp<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}