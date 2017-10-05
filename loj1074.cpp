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

int n, m, q, x, y, bu[201], dist[201];
bool negcycl[201];
struct node{
        int u, v, cost;
        node(int _u, int _v, int _cost){
                u = _u;
                v = _v;
                cost = _cost;
        }
};
vector<node> edge;
vector<int> adj[201];

void dfs(int u)
{
        negcycl[u] = true;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(!negcycl[v]) dfs(v);
        }
}

void bellmanford()
{
        dist[1] = 0;

        for(int i = 1; i < n;i ++){
                bool flag = false;
                for(int j = 0; j < m; j ++){
                        int u = edge[j].u;
                        int v = edge[j].v;
                        int cost = edge[j].cost;
                        if(dist[u] < inf && dist[v] > dist[u] + cost){
                                dist[v] = dist[u] + cost;
                                flag = true;
                        }
                }
                if(!flag) break;
        }

        for(int i = 0; i < m; i ++){
                int u = edge[i].u;
                int v = edge[i].v;
                int cost = edge[i].cost;
                if(dist[u] < inf && dist[v] > dist[u] + cost){
                        dist[v] = dist[u] + cost;
                        if(!negcycl[u]) dfs(u);
                }
        }
}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){

                scanf("%d", &n);
                for(int i = 1; i <= n; i ++){
                        scanf("%d", &bu[i]);
                }
                memset(dist, 63, sizeof dist);
                memset(negcycl, 0, sizeof negcycl);
                scanf("%d", &m);

                for(int i = 1; i <= m;i ++){
                        scanf("%d %d", &x, &y);
                        int cost = bu[y] - bu[x];
                        adj[x].push_back(y);
                        edge.push_back(node(x, y, (cost * cost) * cost));
                }
                bellmanford();
                scanf("%d", &q);
                printf("Case %d:\n", tt ++);
                while(q --){
                        scanf("%d", &x);
                        int ans = dist[x];
                        if(ans < 3 || ans == inf || negcycl[x]) printf("?\n");
                        else printf("%d\n", ans);
                }
                edge.clear();
                for(int i = 0; i <= n;i ++) adj[i].clear();
        }

        return 0;
}

