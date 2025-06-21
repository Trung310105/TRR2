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

int n, a[maxn][maxn];
vector<vector<int>> res;
vector<int> ans;
bool used[maxn];

void dfs(int u)
{
    used[u] = true;
    ans.push_back(u);
    for(int v = 1; v <= n; v++)
    {
        if(!used[v] && a[u][v] == 1)
        {
            dfs(v);
        }
    }
}

signed main()
{
    fater();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            ans.clear();
            dfs(i);
            res.push_back(ans);
        }
    }    

    cout << res.size() << '\n';
    for(auto x : res)
    {
        sort(x.begin(), x.end());
        for(auto y : x) cout << y << ' ';
        cout << '\n';
    }
    return 0;
}
//Đức Trung - B23DCCN853