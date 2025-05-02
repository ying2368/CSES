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
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

#define nL v<<1
#define nR (v<<1) + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int arr[MAXN];
int n, q, m, a, b;

struct Node {
    int val = 0, tag = 0, len;
    int getValue(){ return val + (tag * len); }
} SEG[MAXN * 4];

void modify( int L, int R, int m, int val, int v ){
    if( R < L || m > R || m < L ) return;
    if( m == R && m == L ){
        SEG[v].val = val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, m, val, nL);
    modify(M+1, R, m, val, nR);
    SEG[v].val = min(SEG[nL].val, SEG[nR].val);
}

int query( int L, int R, int qL, int qR, int v ){
    if( R < L || qL > R || qR < L ) return 1e18;
    if( qL <= L && R <= qR) return SEG[v].val;

    int M = (L+R)/2;
    return min( query(L, M, qL, qR, nL), query(M+1, R, qL, qR, nR) );
}

void build( int L, int R, int v ){
    SEG[v].len = R - L + 1;
    if( R == L ){
        SEG[v].val = arr[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    SEG[v].val = min(SEG[nL].val, SEG[nR].val);
}

signed main(){
    opt;

    cin >> n >> q;
    mem(SEG, MEMINF);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    build(1, n, 1);
    for(int i = 0; i < q ; i++){
        cin >> m >> a >> b;
        if(m == 1) modify(1, n, a, b, 1);
        else  cout << query(1, n, a, b, 1) << "\n";
    }


    // cout << "Val | ";
    // for( int i = 1 ; i <= n*4 ; ++i ) cout << SEG[i].val << " \n"[i==9];
  
}