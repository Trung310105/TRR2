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
const int INF = 10000;
const int mod = 1e9 + 7;

using namespace std;

int n, start;
int a[maxn][maxn], x[maxn];
bool used[maxn];
set<int> g[maxn];
vector<string> res;

void Hamilton(int id)
{
    if(id == (n + 1))
        {
            if(a[x[id - 1]][start] == 1)
            {
                string s = "";
                for(int idx = 1; idx <= n; idx++) s += to_string(x[idx]) + ' ';
                s += to_string(start);
                res.push_back(s);
            }
            return;
        }
    int u = x[id - 1];
    for(auto v : g[u])
    {
        if(!used[v])
        {
            used[v] = true;
            x[id] = v;
            Hamilton(id + 1);
            used[v] = false;
        }
    }
}

signed main()
{
    fater();
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> start;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
            {
                g[i].insert(j);
            }
        }
    }

    x[1] = start;
    used[start] = true;
    Hamilton(2);

    for(auto x : res) cout << x << '\n';
    cout << res.size() << '\n';
    return 0;
}
