#include<bits/stdc++.h>
using namespace std;

int n, x, y;
int mx[30010], ans[30010], dep[30010], cost[30010];
vector<int> adj[30010];

void dfs(int u, int from, int depth, int co)
{
        dep[u] = depth;
        cost[u] = co;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from) continue;
                dfs(v, u, depth + 1);
        }
        if()
}


int main()
{

        int t , tt = 1;
        scanf("%d", &t);

        while(t --){
                memset(ans, 0, sizeof ans);
                memset(mx, 0, sizeof mx);

                scanf("%d", &n);

                for(int i = 1; i < n; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }

                for(int i = 1; i <= n;i ++) adj[i].clear();

        }

        return 0;
}
