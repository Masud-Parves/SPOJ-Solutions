#include<bits/stdc++.h>

using namespace std;
const int maxn = (int)2e5+5;
typedef long long ll;

int sp[maxn],NOD=1;
bool isPrime[maxn];
int a[maxn];
vector<pair < int , int > > factor;
void sieve() {
    memset(isPrime, 1, sizeof (isPrime));
    for(int i=2; i<maxn ; i+=2) {
        isPrime[i]=0;
        sp[i]=2;
    }

    for(int i=3 ; i<maxn ; i+=2) {
        if(isPrime[i]) {
            sp[i]=i;
            for(ll j=(i*1LL*i) ; j<maxn ; j+=(2*i)) {
                isPrime[j]=0;
                if(!sp[j]) {
                    sp[j]=i;
                }
            }
        }
    }
}

void factorization(int n)
{

    while(n>1){
        int pwr=0,p=sp[n];
        while(n%p==0){
            pwr++;
            n/=p;
        }
        a[p]=a[p]+pwr;
    }
}

int main() {
    sieve();
    int n;
    cin>>n;

    for(int i=2 ; i<=n ; i++)
    {
        int nn=i;
        factorization(i);
    }
    int b=0;
    for(int i=1 ; i<maxn ; i++){
        if(a[i]!=0){
            b=i;
            break;
        }
    }
    cout<<b<<'^'<<a[b];
    for(int i=b+1 ; i<maxn ; i++){
        if(a[i]!=0){
            cout<<" * " <<i<<'^'<<a[i];
        }
    }
    cout<<endl;

    return 0;
}
