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
const int MAXN = 5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int arr[MAXN] = {0, 4, 3, 1, 3, 2};
int n = 5;

struct Node {
    int val = 0, tag = 0, len;
    int getValue(){ return val + (tag * len); }
} SEG[MAXN * 4];


int query( int L, int R, int qL, int qR, int v ){

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
    SEG[v].val = max(SEG[nL].val, SEG[nR].val);
}

signed main(){
    opt;

    build(1, n, 1);

    cout << "Idx | ";
    for( int i = 1 ; i <= 9 ; ++i ) cout << i << " \n"[i==9];
    cout << "Val | ";
    for( int i = 1 ; i <= 9 ; ++i ) cout << SEG[i].val << " \n"[i==9];

    for( int i = 1 ; i <= 5 ; ++i ){
        for( int j = i ; j <= 5 ; ++j ) cout << "query(" << i << ", " << j << ") = " << query(1, n, i, j, 1) << "\n";
    }
}