/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

string n,m;
int p = 48763;
int ht[1000005],t[1000005];
int c, hs;

signed main(){
    opt;
    cin >> n >> m;

    int b=1;
    for(int i = 0; i < 1000005; i++){
        t[i] = b;
        b *= p;
        b %= Mod;
    }

    hs = m[0];
    for(int i = 1; i < m.size(); i++){
        hs = (hs * p) % Mod;
        hs = (hs + m[i]) % Mod;
    }

    int ms = m.size();
    ht[0] = n[0];
    for(int i = 0; i < n.size(); i++){
        if (i == 0) ht[0] = n[0];
        else{
            ht[i] = (ht[i-1] * p) % Mod;
            ht[i] = (ht[i] + n[i]) % Mod;
        }
        if(i == ms-1){
            if( ht[i] % Mod == hs) c++;
        }
        else if(i >= ms){
            if( (ht[i] - (ht[i-ms] * t[ms]) % Mod + Mod) % Mod == hs) c++;
        }
    }

    cout << c <<"\n";
}