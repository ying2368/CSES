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

int n, x, m, sum, c;
int s[200005];

bool valid(int a, int b){
    if(b == -1){
        if(s[a]>=x) return true;
    }else{
        if( s[a] - s[b] >= x) return true; 
        else return false;
    }

    return false;
}

signed main(){
    opt;

    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> m;
        sum += m;
        s[i] = sum; 
        
        int step = i+1, res = -1;
        while(step > 0 && res <= i){
            // cout << "res+step: " << res+step << "\n";
            if(res+step > i) step/=2;
            else if(valid(i, res+step)) res += step;
            else step /= 2;
        }

        // cout << i << " " << res << "\n";;
        if(res == -1){
            if(s[i] == x) c++;
        }        
        else {
            if(s[i]-s[res] == x) c++;
        }
    }

    cout << c << "\n";
}