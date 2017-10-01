//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second

typedef pair<ll, int> ii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n, m, x, y, visited[10010], ti, dt[10010], low[10010], dep[10010], cnt, ans;
vector<int> adj[10010];
map<int, map<int, int> > ase;

void dfs(int u, int from)
{
        ti ++;
        dt[u] = ti;
        visited[u] = 1;
        low[u] = dt[u];

        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from) continue;
                else if(visited[v]){
                        low[u] = min(low[u], dt[v]);
                }
                else{
                        dfs(v, u);
                        if(low[v] > dt[u]){
                                ase[u][v] = 1;
                                ase[v][u] = 1;
                        }
                        low[u] = min(low[u], low[v]);
                }
        }
}

int dfs2(int u, int from, int depth)
{
        dep[u] = depth;
        visited[u] = 2;
        cnt ++;
        int ret = 0;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from || ase[u][v]) continue;
                if(visited[v] == 2 && (depth + 1 - dep[v]) % 2 == 1){
                        ret |= 1;
                }
                else if(visited[v] != 2) ret |= dfs2(v, u, depth + 1);
        }
        return ret;
}


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                for(int i = 1;i <= m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }

                memset(visited, 0, sizeof visited);
                ti = 0;
                for(int i = 0; i < n;i ++){
                        if(!visited[i]) dfs(i, -1);
                }

                ans = 0;

                for(int i = 0; i < n;i ++){
                        if(visited[i] != 2){
                                cnt = 0;
                                int ret = dfs2(i, -1, 0);
                                if(ret) ans += cnt;
                        }
                }

                printf("Case %d: %d\n", tt ++, ans);
                for(int i = 0; i < n;i ++) adj[i].clear();
                ase.clear();
        }

        return 0;
}

