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

int n, m, x, y, bcc, visited[10010], ti, dt[10010], low[10010], artp[10010], mark[10010],artcnt;
ll cnt;
vector<int> adj[10010];

void dfs(int u, int from)
{
        ti ++;
        dt[u] = ti;
        visited[u] = 1;
        low[u] = dt[u];

        int child = 0;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from) continue;
                else if(visited[v]){
                        low[u] = min(low[u], dt[v]);
                }
                else{
                        dfs(v, u);
                        low[u] = min(low[u], low[v]);
                        if(u != 0 && low[v] >= dt[u] && !artp[u]){
                                artp[u] = 1;
                        }
                        child ++;
                }
        }
        if(u == 0 && child > 1) artp[0] = 1;
}


void dfs2(int u, int from)
{
        visited[u] = 2;
        cnt ++;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from) continue;
                else if(visited[v] != 2 && !artp[v]) dfs2(v, u);
                else if(artp[v] && mark[v] != bcc){
                        mark[v] = bcc;
                        artcnt ++;
                }
        }
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
                memset(artp, 0, sizeof artp);
                memset(mark, 0, sizeof mark);
                ti = 0, bcc = 0;

                dfs(0, -1);

                unsigned long long way = 1;
                int ans = 0;
                artcnt = 0;
                for(int i = 0; i < n;i ++){
                        if(visited[i] != 2 && !artp[i]){
                                cnt = 0;
                                bcc ++;
                                artcnt = 0;
                                dfs2(i, -1);
                                if(artcnt < 2){
                                        way *= cnt;
                                        ans ++;
                                }
                        }
                }

                if(bcc == 1){
                        way = (n * (n - 1)) / 2;
                        ans = 2;
                }
                printf("Case %d: %d %llu\n", tt ++, ans, way);
                for(int i = 0; i < n;i ++) adj[i].clear();

        }

        return 0;
}

