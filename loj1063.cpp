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

typedef pair<int, int> ii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n, m, x, y, cnt, ti, d[10010], visited[10010], low[10010], artp[10010];
vector<int> adj[10010];

void dfs(int u, int from)
{
        ti ++;
        d[u] = ti;
        visited[u] = 1;
        low[u] = d[u];

        int child = 0;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from) continue;
                else if(visited[v]){
                        low[u] = min(low[u], d[v]);
                }
                else{
                        dfs(v, u);
                        low[u] = min(low[u], low[v]);
                        if(u != 1 && low[v] >= d[u] && !artp[u]){
                                artp[u] = 1;
                                cnt ++;
                        }
                        child ++;
                }
        }
        if(u == 1){
                if(child > 1) cnt ++;
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

                for(int i = 0;i < m;i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }
                cnt = 0, ti = 0;
                memset(visited, 0, sizeof visited);
                memset(artp, 0, sizeof artp);

                dfs(1, -1);

                printf("Case %d: %d\n", tt ++, cnt);

                for(int i = 0; i <= n;i ++) adj[i].clear();

        }

        return 0;
}

