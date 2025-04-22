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

int n, k;
int arr[200005];
multiset<int> small, large;

signed main(){
    opt;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if (large.size() + small.size() == 0) large.insert(arr[i]); 
        else {
            if (large.size() > 0 && arr[i] >= *large.begin()) large.insert(arr[i]);
            else if (small.size() == 0 ) large.insert(arr[i]);
            else small.insert(arr[i]);        
        }  

        while (small.size() > large.size()) {
            auto it = small.end();
            it--;
            large.insert(*it);
            small.erase(it);
        } 
        while (large.size() > small.size()) {
            auto it = large.begin();
            small.insert(*it);
            large.erase(it);
        }

        if( i >= k-1) {
            // cout << "small: ";
            // for(auto it = small.begin(); it != small.end(); it++) cout << *it << " ";
            // cout << endl << "large: ";
            // for(auto it = large.begin(); it != large.end(); it++) cout << *it << " ";
            // cout << endl;

            cout << *small.rbegin() << " ";
            if(small.find(arr[i-k+1]) != small.end()) small.erase(small.find(arr[i-k+1]));
            else large.erase(large.find(arr[i-k+1]));

        }  
    }
    cout << "\n";
}