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

int n, start, f_min, f;
int a[maxn][maxn], x[maxn], f_arr[maxn];
bool used[maxn];

void Hamilton(int id)
{
    int u = x[id - 1];
    for(int v = 1; v <= n; v++)
    {
        if(!used[v] && a[u][v] != INF && a[u][v] != 0)
        {
            used[v] = true;
            x[id] = v;
            f += a[u][v];

            if(id == n)
            {
                if(a[x[id]][start] != INF && a[x[id]][start] != 0)
                {
                    if((f + a[x[id]][start]) < f_min)
                    {
                        f_min = f + a[x[id]][start];
                        for(int idx = 1; idx <= n; idx++)
                        {
                            f_arr[idx] = x[idx];
                        }
                        f_arr[n + 1] = start;
                    }
                }
            }
            else if(id < n) Hamilton(id + 1);

            used[v] = false;
            f -= a[u][v];
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
    f = 0;
    f_min = LONG_LONG_MAX;
    Hamilton(2);

    if(f_min != LONG_LONG_MAX)
    {
        cout << f_min << '\n';
        for(int i = 1; i <= (n + 1); i++)
        {
            cout << f_arr[i] << ' ';
        }
    }
    else cout << "0\n";
    return 0;
}
//Đức Trung - B23DCCN853