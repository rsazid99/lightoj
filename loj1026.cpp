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

int n, x, y, l, d[10010], low[10010], visited[10010], ti;
vector<int> adj[10010];
vector<ii> edge;

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
                                if(u < v) edge.push_back(ii(u, v));
                                else edge.push_back(ii(v, u));
                        }
                        low[u] = min(low[u], low[v]);
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

                scanf("%d", &n);

                for(int i = 0; i < n;i ++){
                        scanf("%d", &x);
                        getchar();
                        getchar();
                        scanf("%d", &l);
                        getchar();
                        getchar();
                        for(int j = 0; j < l; j ++){
                                scanf("%d", &y);
                                adj[x].push_back(y);
                                adj[y].push_back(x);
                        }
                }


                ti = 0;
                memset(visited, 0, sizeof visited);
                for(int i = 0; i < n;i ++){
                        if(!visited[i]){
                                dfs(i, -1);
                        }
                }

                sort(edge.begin(), edge.end());

                printf("Case %d:\n", tt++);
                printf("%d critical links\n", edge.size());
                for(int i = 0; i < edge.size(); i ++){
                        printf("%d - %d\n", edge[i].first, edge[i].second);
                }

                edge.clear();

                for(int i = 0; i < n;i ++){
                        adj[i].clear();
                }
        }

        return 0;
}

