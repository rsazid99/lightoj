#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n, m, x, y, q, visited[100010], sub;
vector<int> adj[100010];
vector<ii> v;

ii bfs1(int st)
{
        int visited1[100010], level[100010];
        memset(level, -1, sizeof level);
        memset(visited1, 0, sizeof visited1);

        queue<int> q;
        q.push(st);
        visited1[st] = 1;
        level[st] = 0;
        int mx = 0, ret = 0, cnt = 1;

        while(!q.empty()){
                int u = q.front();
                q.pop();

                if(level[u] > mx){
                        mx = level[u];
                        ret = u;
                }

                for(int i = 0; i < adj[u].size(); i ++){
                        int v = adj[u][i];
                        if(visited1[v] || visited[v]) continue;
                        q.push(v);
                        visited1[v] = 1;
                        level[v] = level[u] + 1;
                        cnt ++;
                }
        }

        sub = max(sub, cnt);
        return ii(ret, cnt);
}

int bfs2(int st)
{
        int level[100010];
        memset(level, 0, sizeof level);
        queue<int> q;
        q.push(st);
        visited[st] = 1;
        level[st] = 0;
        int mx = 0;

        while(!q.empty()){
                int u = q.front();
                q.pop();

                if(level[u] > mx) mx = level[u];

                for(int i = 0; i < adj[u].size(); i ++){
                        int v = adj[u][i];
                        if(!visited[v]){
                                level[v] = 1 + level[u];
                                visited[v] = 1;
                                q.push(v);
                        }

                }
        }
        return mx;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                memset(visited, 0, sizeof visited);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }
                int dia = 0;
                sub = 0;
                for(int i = 1; i <= n; i ++){
                        if(!visited[i]){
                                ii tmp = bfs1(i);
                                int tdia = bfs2(tmp.first);
                                dia  = max(dia , tdia);
                                v.push_back(ii(tmp.second, dia));
                        }
                }
                sort(v.begin(), v.end());
                scanf("%d", &q);
                printf("Case %d:\n", tt ++);
                while(q --){
                        scanf("%d", &x);
                        if(x > sub) printf("impossible\n");
                        else if(x <= dia + 1){
                                printf("%d\n", x - 1);
                        }
                        else{
                                int ans = 1e9;
                                for(int i = 0; i < v.size(); i ++){
                                        if(v[i].first >= x){
                                                int di = v[i].second;
                                                ans = min(ans, di + ((x - di - 1) * 2));

                                        }
                                }
                                printf("%d\n", ans);
                        }

                }
                v.clear();
                for(int i = 1; i <= n; i ++) adj[i].clear();
        }

        return 0;
}
