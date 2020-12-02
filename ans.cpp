typedef long long ll;
#include<bits/stdc++.h>
using namespace std;

ll mod_exp(int x, int n){
    if (n<=0)
        return 1;
    ll val = mod_exp(x,n/2);
    ll ans = val;
    int M = 1e9 + 7;
    ans = (ans*val)%M;
    if (n%2!=0){
        ans = (ans*x)%M;
    }
    return (ans%M);
}

int ncr (int n, int r){
    vector<ll> dp(r+1);
    dp[0] = 1;
    int M = 1e9 + 7;
    for (int i=1;i<=r;i++){
        ll p = n - i + 1;
        ll q = mod_exp(i,M-2);
        ll val = (p*q)%M;
        val = (val*dp[i-1])%M;
        dp[i] = val;
    }
    return dp[r];
}

int main(){
    int n,r;
    cin >> n >> r;
    cout << ncr(n,r) << "\n";
}
