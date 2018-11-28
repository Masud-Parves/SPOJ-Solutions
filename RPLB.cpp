#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        SPOJ RPLB - Blueberries
        Problem Link : https://www.spoj.com/problems/RPLB/
        Topics : 0/1 Knapsack DP
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
#define mx  550
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

int DP[1009][1009];
int arr[1009];
int n,k;
int cal(int pos, int w)
{
    if(pos>n) return w;

    if(DP[pos][w]!=-1) return DP[pos][w];

    if((w+arr[pos])<=k){
        DP[pos][w]=max(cal(pos+2,w+arr[pos]), cal(pos+1, w));
    }
    else
        DP[pos][w]=cal(pos+1,w);
    return DP[pos][w];
}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin>>t;

    TEST_CASE(t)
    {
        cin>>n>>k;
        for(int i=1 ; i<=n ; i++){
            cin>>arr[i];
        }

        memset(DP , -1 , sizeof (DP));
        cout<<"Scenario #"<<z<<": "<<cal(1,0)<<endl;

    }
    return 0;
}
