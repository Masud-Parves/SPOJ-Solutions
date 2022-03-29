#include<bits/stdc++.h>
#define SIZE 200005
#define CIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
/*
       Bismillahir Rahmanir Rahim
        SPOJ EPALIN - Extend to Palindrome
        Problem Link :
        Topics : Z- Algorithm
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/
 
 
using namespace std;
 
 
int f[SIZE];
int cntZ,cntNZ;
 
 
int kmp_failure(string p)
{
    memset(f, 0, sizeof(f));
    int len=p.length();
    f[0]=0;
    int j=0;
 
    for(int i=1 ; i<len ; i++)
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
    return f[len-1];
}
 
string palindromeFinder(string s)
{
    ///S is original string put into original
    string original=s;
 
    ///reverse of s
    string rev=string(s.rbegin(),s.rend());
 
    int number=original.length()-kmp_failure(rev + "#" +original);
 
    for(int i=number-1 ; i>=0 ; i--)
    {
        original.append(1,original[i]);
    }
    return original;
 
}
 
int n;
 
int main()
{
 
    CIN;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    string str;
 
    while(cin>>str)
    {
        cout<<palindromeFinder(str)<<endl;
    }
 
    return 0;
}