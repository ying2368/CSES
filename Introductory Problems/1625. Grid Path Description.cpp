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

bool used[9][9];
string s;
int res;

void dfs(int x,int y, int c){
    if(used[x][y]) return;
    if(c==48) {
        if(x==7 && y==1) res++;
        return;
    }
    used[x][y] = true;

    if( ( used[x-1][y] && used[x+1][y] && !used[x][y+1] && !used[x][y-1] ) ||
        ( !used[x-1][y] && !used[x+1][y] && used[x][y+1] && used[x][y-1] ) ||
        ( used[x-1][y-1] && !used[x][y-1] && !used[x-1][y] ) ||
        ( used[x+1][y-1] && !used[x][y-1] && !used[x+1][y] ) ||
        ( used[x-1][y+1] && !used[x-1][y] && !used[x][y+1] ) ||
        ( used[x+1][y+1] && !used[x+1][y] && !used[x][y+1] ) ){
            used[x][y] = false;
            return;
    }

    if(s[c] == 'D') dfs(x+1,y,c+1);
    if(s[c] == 'U') dfs(x-1,y,c+1);
    if(s[c] == 'L') dfs(x,y-1,c+1);
    if(s[c] == 'R') dfs(x,y+1,c+1);
    if(s[c] == '?'){
        for(auto [a,b] : dir){
            int nx = x+a, ny = y+b;
            dfs(nx,ny,c+1);
        }
    }
    used[x][y] = false;
    return;
}

signed main(){
    opt;
    cin >> s;
    for( int i = 0 ; i < 9 ; i++ ){
        used[i][0] = true;
        used[8][i] = true;
        used[i][8] = true;
        used[0][i] = true;
    }

    dfs(1,1,0);
    cout << res <<" ";
}