#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
#define maxn 30010
const double PI = acos(-1);

int r, c, q, x, y;
char g[201];
vector<ii> adj[401][401];
double own[401][401];
bool border[401][401];
int visited[401][401];
double ans[40010];

double dfs(int rr, int cc, int reg)
{

        visited[rr][cc] = reg;
        double ret = own[rr][cc];
        for(int i = 0; i < adj[rr][cc].size(); i ++){
                int nr = adj[rr][cc][i].first;
                int nc = adj[rr][cc][i].second;
                if(!visited[nr][nc]){
                        ret += dfs(nr, nc, reg);
                }
        }
        return ret;

}

int main()
{

        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d\n", &r, &c);

                memset(own, 0, sizeof own);
                memset(border, 0, sizeof border);
                memset(visited, 0, sizeof visited);
                memset(ans, 0, sizeof ans);

                for(int i = 1; i < 2 * r; i += 2){
                        scanf("%s", g);

                        int st = 0;

                        for(int j = 1; j < 2 * c; j += 2){
                                if(g[st] == '1'){
                                       adj[i][j].push_back(ii(i - 1, j - 1));
                                       adj[i - 1][j - 1].push_back(ii(i, j));
                                       adj[i][j].push_back(ii(i + 1, j + 1));
                                       adj[i + 1][j + 1].push_back(ii(i, j));
                                       own[i - 1][j + 1] += (PI / 4.00);
                                       own[i + 1][j - 1] += (PI / 4.00);
                                       own[i + 1][j + 1] += 1.00;
                                       own[i - 1][j - 1] += 1.00;
                                }
                                else{
                                        adj[i][j].push_back(ii(i - 1, j + 1));
                                        adj[i - 1][j + 1].push_back(ii(i, j));
                                        adj[i][j].push_back(ii(i + 1, j - 1));
                                        adj[i + 1][j - 1].push_back(ii(i, j));
                                        own[i + 1][j + 1] += (PI / 4.00);
                                        own[i - 1][j - 1] += (PI / 4.00);
                                        own[i - 1][j + 1] += 1.00;
                                        own[i + 1][j - 1] += 1.00;

                                }
                                double area = 1 - (PI / 4.00);
                                own[i][j] += (2.00 * area);
                                border[i - 1][j] = 1;
                                border[i + 1][j] = 1;
                                border[i][j - 1] = 1;
                                border[i][j + 1] = 1;
                                st ++;
                                if( st == c) break;
                        }

                }

                int reg = 0;
                for(int i = 0; i <= r * 2; i ++){
                        for(int j = 0; j <= c * 2; j ++){
                                if(!visited[i][j] && !border[i][j]){
                                        reg ++;
                                        ans[reg] = dfs(i, j, reg);
                                }
                        }
                }
                scanf("%d", &q);
                printf("Case %d:\n", tt ++);
                while(q --){
                        scanf("%d %d", &x, &y);
                        if(border[x][y]) printf("0\n");
                        else printf("%.8f\n", ans[visited[x][y]]);
                }

                for(int i = 0; i <= 2 * r; i ++){
                        for(int j = 0; j <= 2 * c; j ++) adj[i][j].clear();
                }

        }


        return 0;
}

