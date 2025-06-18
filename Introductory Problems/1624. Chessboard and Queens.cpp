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

int res=0;
int maze[8][8], visited[8][8];
string s;

bool check(int x, int y){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(visited[i][j]){
                if(abs(i-x) == abs(j-y)) return false;
                if(i==x || j==y) return false;
            }
        }
    }

    return true;
}

void dfs(int cur){
    if(cur == 8){
        // for(int i=0;i<8;i++){
        //     for(int j=0;j<8;j++){
        //         cout << visited[i][j];
        //     }
        //     cout << endl;
        // }

        res++;
        return;
    }

    for(int i=0;i<8;i++){
        if(maze[cur][i] && check(cur,i)){
            visited[cur][i] = 1;
            dfs(cur+1);
            visited[cur][i] = 0;
        }
    }
}

signed main(){
    opt;

    for(int i=0;i<8;i++) {
        cin >> s;
        for(int j=0;j<8;j++)
            if(s[j]=='.') maze[i][j]=1;
    }


    dfs(0);
    cout << res <<"\n";
}