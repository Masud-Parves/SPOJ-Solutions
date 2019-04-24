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
#define TEST_CASE(t) for(int zz=1 ; zz<=t ; zz++)
#define PRINT_CASE printf("Case %d: ",zz)
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
const int maxn = (int)3000+10;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

//int arr[maxn];
char s[maxn];
int r,l;
int odd[maxn], even[maxn]; // P[0][i] -> even length palindrome centered at i
                // P[1][i] ->  odd length palindrome centered at i

int cnt[maxn];
int manacer(string s){
    int n = (int) s.length();
    // Odd case
	int l = 0, r = -1;
	for (int i = 0; i < n; i++) {
        int cur = 1;
		if (i < r)
			cur = min(r - i + 1, odd[l + r - i]);
		while (i + cur < n && i - cur >= 0 && s[i - cur] == s[i + cur])
			cur++;
		odd[i] = cur;
		if (i + cur - 1 > r) {
			l = i - cur + 1;
			r = i + cur - 1;
		}
	}

	// Even case
	l = r = -1;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		if (i < r)
			cur = min(r - i + 1, even[l + r - i + 1]);
		while (i + cur < n && i - 1 - cur >= 0 && s[i - 1 - cur] == s[i + cur])
			cur++;
		even[i] = cur;
		if (i + cur - 1 > r) {
			l = i - cur;
			r = i + cur - 1;
		}
	}

    int res=0;
    f0(i,n){
        even[i]=(even[i]*2);
        cnt[even[i]]++;
        res = max(res , even[i]);
    }

    f0(i,n){
        odd[i]=(odd[i]*2-1);
        cnt[odd[i]]++;
        res = max(res , odd[i]);
    }


    return res;
}

void clr(){
    memset(cnt, 0 , sizeof(cnt));
    memset(even, 0 , sizeof(even));
    memset(odd, 0 , sizeof(odd));
}

int main() {
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    while(t--){
        clr();
        string str,t;

        scanf("%s", s);

        str = s;
        int ans=manacer(str);

       printf("%d %d\n",ans, cnt[ans]);

    }
    return 0;
}

