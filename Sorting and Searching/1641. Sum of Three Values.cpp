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

int n,x,a;
vector<pii> v;

bool valid(int k, int t){
    if(k>=n) return true;
    if(v[k].F > t) return true;
    else return false;
}

bool find(){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i].F + v[j].F >= x) continue;
            int t = x - v[i].F - v[j].F;
            int res = j+1, step = 5000;

            // cout << v[i].F << " " << v[j].F << ", t: " << t << "\n";
            while(step > 0){
                if(valid(res+step, t)) step /= 2;
                else res += step; 
            }
           
            // cout << v[res].F <<"\n";
            if(v[res].F == t){
                // cout << i << " " << j << " " << res << "\n";
                cout << v[i].S << " " << v[j].S << " " << v[res].S << "\n";
                return true;
            }
        }
    }

    return false;
}


signed main(){
    opt;
    cin >> n >> x;

    for(int i=1;i<=n;i++){
        cin >> a;
        v.pb({a,i});
    }

    sort(v.begin(),v.end());

    // for(int i=0;i<n;i++) cout << v[i].F << "";
    // cout <<"\n";

    if(!find()) cout << "IMPOSSIBLE\n";

}