#include<bits/stdc++.h>
using namespace std;

int k, n, m, arr[1010], x, y, visited[1010], cnt[1010];
vector<int> adj[1010];

void dfs(int u, int no)
{
        visited[u] = 1;
        cnt[u] += no;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(visited[v]) continue;
                dfs(v, no);
        }
}

int main()
{

        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                memset(arr, 0, sizeof arr);
                memset(cnt, 0, sizeof cnt);

                scanf("%d %d %d", &k, &n, &m);

                for(int i = 1; i <= k; i ++){
                        scanf("%d", &x);
                        arr[x] += 1;
                }

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                }
                for(int i = 1; i <= n; i ++){
                        if(arr[i] > 0){
                                memset(visited, 0, sizeof visited);
                                dfs(i, arr[i]);
                        }
                }

                int ans = 0;
                for(int i = 1; i <= n; i ++) if(cnt[i] == k) ans ++;

                printf("Case %d: %d\n", tt++, ans);

                for(int i = 1; i <= n;i ++) adj[i].clear();

        }

        return 0;
}
