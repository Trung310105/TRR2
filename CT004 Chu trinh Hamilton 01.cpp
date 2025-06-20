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

int n, start, a[maxn][maxn];
vector<string> res;
int x[maxn];
bool used[maxn];

void Hamilton(int id)
{
    int u = x[id - 1];
    for(int v = 1; v <= n; v++)
    {
        if(!used[v] && a[u][v] == 1)
        {
            used[v] = true;
            x[id] = v;
            if(id == n)
            {
                if(a[x[id]][start] == 1)
                {
                    string s = "";
                    for(int idx = 1; idx <= n; idx++)
                    {
                        s += to_string(x[idx]) + ' ';
                    }
                    s += to_string(start);
                    res.push_back(s);
                }
            }
            else if(id < n) Hamilton(id + 1);
            used[v] = false;
        }
    }
}

signed main()
{
    fater();
    cin >> n >> start;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    x[1] = start;
    used[start] = true;
    Hamilton(2);
    if(res.size())
    {
        cout << res.size() << '\n';
        for(auto x : res) cout << x << '\n';
    }
    else cout << "0\n";
    return 0;
}
//Đức Trung - B23DCCN853