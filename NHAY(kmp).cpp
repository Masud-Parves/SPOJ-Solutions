#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAX 1000010
 
using namespace std;
    
/*
        Bismillahir Rahmanir Rahim
        SPOJ NHAY - A Needle in the Haystack 
        Problem Link :
        Topics : KMP Algorithm
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/
	
 
 
int f[MAX];
string patten,text;
vector<int>point;
 
void kmp_preprocessor(string p)/// failure table
{
    memset(f, 0, sizeof(f));
    f[0]=0;
    int j=0,lenP=p.length();
 
 
    for(int i=1 ; i<lenP ; i++)
    {
        if(p[j]==p[i])
        {
            f[i]=j+1;
            j++;
        }
        else
        {
 
            while(j!=0)
            {
                j=f[j-1];
                if(p[j]==p[i])
                {
                    f[i]=j+1;
                    j++;
                    break;
                }
            }
        }
    }
 
}
 
void match(string t, string p)
{
    kmp_preprocessor(p);
    int j=0,i,lenT=t.length(),lenP=p.length();
 
    for(i=0 ; i<lenT ;i++)
    {
        if(t[i]==p[j])
        {
            if(j==lenP-1)
            {
                cout<<i-lenP+1<<endl;
            }
            j++;
        }
        else
        {
            while(j!=0)
            {
                j=f[j-1];
                if(t[i]==p[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    cout<<endl;
}
 
 
int main()
{
    ///freopen("in.txt", "r", stdin);
    int sizeofp;
 
    while(cin>>sizeofp)
    {
        cin>>patten;
        cin>>text;
 
        match(text,patten);
 
    }
    return 0;
}