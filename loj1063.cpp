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

int n, m, x, y, ans, ti, dt[10010], visited[10010], low[10010];
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

void dfs2(int u, int from, int depth)
{
        visited[u] = 2;
        for(int i = 0;i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(ase[u][v] || v == from) continue;
                if(visited[v] == 2){
                        if((depth + 1) % 2 == 1 && depth > 0){
                                ans += (depth + 1);
                        }
                }
                else if(!visited[v] != 2) dfs2(v, u, depth + 1);
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

                dfs(0, -1);
                ans = 0;
                for(int i = 0; i < n;i ++){
                        if(visited[i] != 2){
                                dfs2(i, -1, 0);
                        }
                }


                printf("Case %d: %d\n", tt ++, ans);

                for(int i = 0; i < n;i ++) adj[i].clear();
                ase.clear();

        }

        return 0;
}

