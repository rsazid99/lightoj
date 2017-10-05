
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

int n, m, x, y, z, dist[1010];
bool negcycl[1010];

struct node{
        int u, v, cost;
        node(int _u, int _v, int _cost){
                u = _u;
                v = _v;
                cost = _cost;
        }
};

vector<node> edge;
vector<ii> adj[1010];
vector<int> ans;

void dfs(int u)
{
        negcycl[u] = 1;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i].first;
                if(!negcycl[v]) dfs(v);
        }

}

void bellmanford()
{
        dist[n] = 0;

        for(int i = 0; i < n;i ++){
                bool flag = false;
                for(int j = 0; j < edge.size(); j ++){
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

        for(int i = 0; i < edge.size(); i ++){
                int u = edge[i].u;
                int v = edge[i].v;
                int cost = edge[i].cost;
                if(dist[u] < inf && dist[v] > dist[u] + cost){
                        if(!negcycl[u]) dfs(v);
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

                for(int i = 0; i < n;i ++){
                        adj[n].push_back(ii(i, 0));
                        edge.push_back(node(n, i, 0));
                }

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d %d", &x, &y, &z);
                        edge.push_back(node(y, x, z));
                        adj[y].push_back(ii(x, z));

                }
                memset(dist, 63, sizeof dist);
                memset(negcycl, 0, sizeof negcycl);


                bellmanford();


                for(int i = 0; i < n;i ++){
                        if(negcycl[i]) ans.push_back(i);
                }
                printf("Case %d:", tt ++);
                if(ans.size() == 0) printf(" impossible\n");
                else{
                        for(int i = 0;i < ans.size(); i ++){
                                printf(" %d", ans[i]);
                        }
                        printf("\n");
                }

                edge.clear();
                ans.clear();
                for(int i = 0; i <= n;i ++) adj[i].clear();

        }

        return 0;
}
