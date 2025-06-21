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
    bool friend operator < (Edge a, Edge b)
    {
        if(a.w != b.w) return a.w < b.w;
        if(a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    }
};

int n, m;
vector<Edge> edges, mst;
int total;
int par[maxn], sz[maxn];

int find(int v)
{
    if(par[v] == v) return v;
    return par[v] = find(par[v]);
}

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

void Kruskal()
{
    total = 0;
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    for(int id = 0; id < m; id++)
    {
        if(mst.size() == (n - 1)) break;
        if(Union(edges[id].u, edges[id].v))
        {
            total += edges[id].w;
            mst.push_back(edges[id]);
        }
    }

    if(mst.size() == (n - 1))
    {
        cout << total << '\n';
        for(auto x : mst)
        {
            cout << min(x.u,x.v) << ' ' << max(x.u,x.v) << ' ' << x.w << '\n';
        }
    }
    else cout << "0\n";
}

signed main()
{
    fater();
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back(Edge(x,y,z));
    }
    sort(edges.begin(), edges.end());
    Kruskal();
    return 0;
}
//Đức Trung - B23DCCN853