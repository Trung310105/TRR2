#include <bits/stdc++.h>
#define int long long
#define fater() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,a,b) for(int i = a; i >= b; i--)
#define F(i,a,b) for(int i = a; i < b; i++)
#define FD(i,a,b) for(int i = a; i > b; i--)
#define pb push_back
#define reset(name, val) memset(name, val, sizeof name)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
const int maxn = 105;
const int mod = 1e9 + 7;

using namespace std;

int n, m, deg[maxn];
set<int> g[maxn];

void sol_1()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << deg[i] << ' ';
    }
}

void sol_2()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    cout << n << '\n';
    for(int u = 1; u <= n; u++)
    {
        cout << g[u].size() << ' ';
        for(auto v : g[u]) cout << v << ' ';
        cout << '\n';
    }
}

signed main()
{
    fater();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int type; cin >> type;
    if(type == 1) sol_1();
    else sol_2();
    return 0;
}
//Đức Trung - B23DCCN853    