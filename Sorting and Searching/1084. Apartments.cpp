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

int n, m, k, a, res;
multiset<int> applicant, apartments;

signed main(){
    opt;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        applicant.insert(a);
    }
     for(int i=0;i<m;i++){
        cin >> a;
        apartments.insert(a);
    }

    auto it = applicant.begin();
    auto it2 = apartments.begin();

    while(it != applicant.end() && it2 != apartments.end()){
        if(abs(*it - *it2) <= k){
            res++;
            it++;
            it2++;
        }
        else if(*it < *it2) it++;
        else if(*it > *it2) it2++;
    }

    cout << res << "\n";
}