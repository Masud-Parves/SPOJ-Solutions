#include<bits/stdc++.h>

using namespace std;

/*
        Bismillahir Rahmanir Rahim
        PFDEP - Project File Dependencies
        Topics : Topological Sort (Kahn's Algorithm)
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
const int maxm = (int)105;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

vector < int >inDegree;
vector < int > graph[maxm],ans;
int n,m;

void kahnAlgo()
{
    priority_queue<int , vector<int> , greater<int>>q;


    for(int i=1 ; i<=n ; i++){
        if(!inDegree[i]){
                q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.top();
        q.pop();
        ans.pb(u);

        for(int i=0 ; i<graph[u].size() ; i++){
            int v=graph[u][i];

            if(--inDegree[v]==0){
                q.push(v);
            }
        }

    }

}

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    cin>>n>>m;

    for(int i=1 ; i<=m ; i++)
    {
        int a,k;
        cin>>a>>k;
        while(k--)
        {
            int b;
            cin>>b;
            graph[b].pb(a);
        }
    }

    //inDegree calculate
    inDegree.resize(n+1,0);
	for(int i=1; i<=n; i++) /// every j depend on i
	{
		for(int j=0; j<graph[i].size(); j++)
			inDegree[graph[i][j]]++;
	}

    kahnAlgo();

    cout<<ans[0];
    for(int i=1 ; i<ans.size() ; i++)
    {
        cout<<" "<<ans[i];
    }
    cout<<endl;
    return 0;
}


