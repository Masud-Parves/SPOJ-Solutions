#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans(ll a, ll b){
    if(b==1) return a;
    if(b==0) return 1;

    if(b%2==0){
        ll res=(ans(a,b/2))%10;
        res=(res*res)%10;
        return res;

    }
    else return (a*(ans(a,b-1)%10))%10;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;

        ll res=ans(a,b);
        cout<<res<<endl;
    }
    return 0;
}
