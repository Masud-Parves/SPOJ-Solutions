#include<bits/stdc++.h>
 
using namespace std;
 
/*
 
        Bismillahir Rahmanir Rahim
        SPOJ EPALIN - Extend to Palindrome
        Problem Link :
        Topics : Z- Algorithm
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/
 
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a)  a.begin(), a.end()
 
 
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
 
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
 
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define SIZE 200005
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define NOT_VISITED 0
#define IS_VISITED 1
 
 
 
int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};
 
 
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
 
 
 
int z[SIZE];
int z_function(string s, int x)
{
    memset(z, 0, sizeof z);
 
    int n = (int) s.length(),maxNum=0;
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        else
            z[i] = 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    vector< int > store;
 
    for(int i=x+1; i<n ; i++)
    { 
        if(z[i]+i==n)
        {
            store.pb(z[i]);
        }
    }
    int re=0;
    for(int i=0 ; i<store.size() ; i++)
    {
        re=max(re,store[i]);
    }
 
    return re;
}
 
string palindromeFinder(string s)
{
    string orginal=s;
    string rev=string(s.rbegin(), s.rend());
    int n = (int) s.length();
    int number=orginal.length()-z_function(rev + "#" +orginal,n);
 
    for(int i=number-1 ; i>=0 ; i--)
    {
        orginal.append(1,orginal[i]);
    }
    return orginal;
 
}
 
 
int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    string s;
    while(cin>>s)
    {
        cout<<palindromeFinder(s)<<endl;
    }
    return 0;
}