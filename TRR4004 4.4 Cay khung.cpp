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

struct Edge
{
    int u, v, w;
    Edge(int st, int en, int wt)
    {
        u = st;
        v = en;
        w = wt;
    }
};

int n, start;
int a[maxn][maxn];
int total;
int dist[maxn], par[maxn];
bool used[maxn];
vector<Edge> edges;

void prim()
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;    
    int u = start;
    for(int v = 1; v <= n; v++)
    {
        if(a[u][v] > 0 && a[u][v] <= 50)
        {
            pq.push({a[u][v], {u, v}});
        }
    }
    used[u] = true;
    total = 0;
    while(!pq.empty())
    {
        auto[w, p] = pq.top();
        pq.pop();
        auto [u, v] = p;
        if(used[v]) continue;
        used[v] = true;
        total += w;
        Edge edge(u, v, w);
        edges.push_back(edge);
        for(int en = 1; en <= n; en++)
        {
            if(!used[en] && a[v][en] > 0 && a[v][en] <= 50)
            {
                pq.push({a[v][en], {v, en}});
            }
        }
    }
}

signed main()
{
    fater();
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> start;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    prim();
    if(edges.size() == (n - 1))
    {
        cout << total << '\n';
        for(auto x : edges)
        {
            cout << min(x.u,x.v) << ' ' << max(x.u,x.v) << ' ' << x.w << '\n';
        }
    }
    else cout << "0\n";
    return 0;
}
//Đức Trung - B23DCCN853