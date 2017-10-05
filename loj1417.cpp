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

int n, x, y, cc, visited[maxn], compo[maxn], small[maxn], cnt = 0, sz[maxn], dp[maxn];
vector<int> adj[maxn], radj[maxn], cadj[maxn];
stack<int> stk;

void dfs1(int u)
{
        visited[u] = 1;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(!visited[v]) dfs1(v);
        }
        stk.push(u);
}

void dfs2(int u)
{
        visited[u] = 2;
        compo[u] = cc;
        small[cc] = min(small[cc], u);
        cnt ++;
        for(int i = 0; i < radj[u].size(); i ++){
                int v = radj[u][i];
                if(visited[v] != 2) dfs2(v);
        }
}


void dfs3(int u)
{
        visited[u] = 3;
        dp[u] += sz[u];
        for(int i = 0; i < cadj[u].size(); i ++){
                int v = cadj[u][i];
                if(visited[v] != 3) dfs3(v);
                dp[u] += dp[v];
        }
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                memset(small, 63, sizeof small);
                memset(visited, 0, sizeof visited);
                memset(dp, 0, sizeof dp);

                for(int i = 1; i <= n; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        radj[y].push_back(x);
                }

                for(int i = 1; i <= n;i ++){
                        if(!visited[i]) dfs1(i);
                }

                cc = 0;
                while(!stk.empty()){
                        int u = stk.top();
                        stk.pop();

                        if(visited[u] != 2){
                                cc ++;
                                cnt = 0;
                                dfs2(u);
                                sz[cc] = cnt;
                        }
                }

                for(int i = 1;i <= n;i ++){
                        for(int j = 0; j < adj[i].size(); j ++){
                                int v = adj[i][j];
                                if(compo[i] != compo[v]){
                                        cadj[compo[i]].push_back(compo[v]);
                                }
                        }
                }

                int mx = 0, ans = 0;
                for(int i = 1; i <= cc;i ++){
                        if(visited[i] != 3){
                                dfs3(i);
                                if(dp[i] > mx){
                                        mx = dp[i];
                                        ans = small[i];
                                }
                                else if(dp[i] == mx) ans = min(ans, small[i]);
                        }
                }

                printf("Case %d: %d\n", tt ++, ans);

                for(int i = 0; i <= n;i ++){
                        adj[i].clear();
                        radj[i].clear();
                        cadj[i].clear();
                }


        }


        return 0;
}


