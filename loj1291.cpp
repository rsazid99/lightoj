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

int n, m, x, y, bcc, ti, d[10010], visited[10010], low[10010], bcom[10010], deg[10010];
vector<int> adj[10010];
map<int, map<int, int> > ase;

void dfs(int u, int from)
{
        ti ++;
        d[u] = ti;
        visited[u] = 1;
        low[u] = d[u];

        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from) continue;
                else if(visited[v]){
                        low[u] = min(low[u], d[v]);
                }
                else{
                        dfs(v, u);
                        if(low[v] > d[u]){
                                ase[u][v] = 1;
                                ase[v][u] = 1;
                        }
                        low[u] = min(low[u], low[v]);
                }
        }
}

void dfs2(int u, int from)
{
        visited[u] = 2;
        bcom[u] = bcc;
        for(int i = 0;i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(ase[u][v]) continue;
                if(visited[v] != 2){
                        dfs2(v, u);
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

                for(int i = 0;i < m;i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }
                ti = 0;
                memset(visited, 0, sizeof visited);
                memset(deg, 0, sizeof deg);

                dfs(0, -1);
                bcc = 0;
                for(int i = 0; i < n;i ++){
                        if(visited[i] != 2){
                                bcc ++;
                                dfs2(i, -1);
                        }
                }


                for(int i = 0;i < n; i ++){
                        for(int j = 0;j < adj[i].size(); j ++){
                                int v = adj[i][j];
                                if(bcom[i] != bcom[v]){
                                        deg[bcom[i]] ++;
                                        deg[bcom[v]] ++;
                                }
                        }
                }
                int ans = 0;
                for(int i = 1; i <= bcc; i ++){
                        if(deg[i] == 2) ans ++;
                }

                printf("Case %d: %d\n", tt ++, (ans / 2) + (ans % 2 > 0));

                for(int i = 0; i <= n;i ++) adj[i].clear();
                ase.clear();

        }

        return 0;
}
