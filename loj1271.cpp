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


int n, arr[50010], level[50010], pa[50010];
vector<int> adj[50010], path;


void bfs()
{
        memset(level, -1, sizeof level);
        level[arr[1]] = 0;
        queue<int> q;
        q.push(arr[1]);
        pa[arr[1]] = -1;

        while(!q.empty()){
                int u = q.front();
                q.pop();

                if(u == arr[n]) break;

                for(int i = 0; i < adj[u].size(); i ++){
                        int v = adj[u][i];
                        if(level[v] < 0){
                                level[v] = level[u] + 1;
                                pa[v] = u;
                                q.push(v);
                        }
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

                for(int i = 1; i <= n;i ++){
                        scanf("%d", &arr[i]);
                }

                for(int i = 1; i < n; i ++){
                        adj[arr[i]].push_back(arr[i + 1]);
                        adj[arr[i + 1]].push_back(arr[i]);
                }
                for(int i = 1; i < 50001; i ++){
                        sort(adj[i].begin(), adj[i].end());
                }

                bfs();
                int par = arr[n];
                while(par != -1){
                        path.push_back(par);
                        par = pa[par];
                }
                reverse(path.begin(), path.end());
                printf("Case %d:\n", tt ++);
                for(int i = 0; i < path.size(); i ++){
                        if(i == 0) printf("%d", path[i]);
                        else printf(" %d", path[i]);
                }
                printf("\n");


                for(int i = 0; i < 50001;i ++) adj[i].clear();
                path.clear();
        }

        return 0;
}

