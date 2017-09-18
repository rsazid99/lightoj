//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define ff  first
#define ss  second
int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(int N, int pos) {return (bool) (N & (1 << pos));}

typedef pair<int, int> ii;

int color[101][2], n, m, x, y, ans;
vector<int> adj[101];

void dfs(int u, int col)
{
        if(col != -1) color[u][col] = 1;
        else col = 0;
        int nxtcol = 1 - col;

        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(!color[v][nxtcol]){
                        dfs(v, nxtcol);
                }
        }
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){

                memset(color, 0, sizeof color);

                scanf("%d %d", &n, &m);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }
                dfs(1, -1);

                int ans = 0;

                for(int i = 0; i <= n;i ++) if(color[i][0]) ans ++;

                printf("Case %d: %d\n", tt ++, ans);

                for(int i = 1; i <= n; i ++) adj[i].clear();
        }


        return 0;
}

