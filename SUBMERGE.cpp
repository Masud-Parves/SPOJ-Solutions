#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics : Cut Vertex / Articulation Point
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


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
int n,m;
vector < int > g[maxn];
vector < int > ans;
bool visited[maxn],cnt[maxn];
int low_tym[maxn],dis_tym[maxn];
int timer;

void dfs(int u, int p=-1){

    visited[u]=true;
    low_tym[u]=dis_tym[u]=timer++;
    int child=0;
    for(int i=0 ; i<SZ(g[u]) ; i++){
        int v=g[u][i];
        if(v==u){
            continue;
        }

        if(visited[v]){
            low_tym[u] = min(low_tym[u], dis_tym[v]);
        }
        else {

            dfs(v,u);

            if(p!=-1 && dis_tym[u]<=low_tym[v]){
                cnt[u]=1;
            }

            low_tym[u]=min(low_tym[u], low_tym[v]);
            child++;
        }
    }

    if(p==-1 && child > 1){
        cnt[u]=1;
    }

}


void clrAll(){
    f0(i,maxn){
        g[i].clear();
    }
    timer=0;
    memset(visited, 0 , sizeof(visited));
    memset(cnt, 0 , sizeof(cnt));
}


int main() {
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while( cin >> n >> m){
        if(n==0 && m==0){
            break;
        }

        clrAll();
        int x,y;
        f1(i,m){
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        f1(i,n){
            if(!visited[i]){
                dfs(i);
            }
        }

        int ans=0;
        f1(i,n){
            if(cnt[i]) ans++;
        }
        cout << ans << endl;


    }

    return 0;
}


