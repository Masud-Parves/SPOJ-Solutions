#include<iostream>
#include<string>
#include<bits/stdc++.h>

/*
        Bismillahir Rahmanir Rahim
        SPOJ NAJPF - Pattern Find
        Problem Link :
        Topics : Z- Algorithm
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/

using namespace std;
vector<int>match_point;
int f[100005];

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

}

vector<int> kmp_match(string t,string p)
{
    match_point.clear();
    kmp_failure(p);
    int lenT=t.length(),lenP=p.length();
    int j=0;
    for(int i=0 ; i<lenT ; i++)
    {
        if(t[i]==p[j])
        {
            if(j==lenP-1)
            {
                //cout<<"match point ---"<<i+1<<endl;
                match_point.push_back(i-j+1);
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
    return match_point;
}




int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string t;
        string p;

        cin>>t;
        cin>>p;

        vector<int>match;
        match.clear();
        match=kmp_match(t,p);

        if(match.size()==0)
        {
            cout<<"Not Found"<<endl<<endl;

        }
        else
        {
            cout<<match.size()<<endl;
            cout<<match[0];
            for(int i=1 ; i<match.size() ; i++)
            {

                cout<<" "<<match[i];
            }
            cout<<endl<<endl;
            match.clear();
        }

    }

    return 0;
}
