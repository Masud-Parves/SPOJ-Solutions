#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


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

vector< ll > graph[110];
bool visited[110];
stack < int > ans;

void dfs_modification(ll src)
{
    visited[src]=true;

    for(ll i=0; i<graph[src].size() ; i++)
    {
        ll v=graph[src][i];
        if(!visited[v])
        {
            dfs_modification(v);
        }
    }
    ans.push(src);
}


int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n,m;
    cin>>n>>m;

    for(ll i=1 ; i<=m ; i++)
    {
        int a,k;
        cin>>a>>k;
        for(ll ii=1 ; ii<=k ; ii++)
        {
            ll b;
            cin>>b;
            graph[b].pb(a);
        }
    }

    for(ll i=1; i<=n ; i++)
    {
        sort(allr(graph[i]));
    }
    memset(visited, false , sizeof(visited));

    for(ll i=n ; i>0 ; i--)
    {
        if(!visited[i])
            dfs_modification(i);
    }

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}


