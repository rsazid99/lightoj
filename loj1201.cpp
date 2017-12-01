//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second

typedef pair<ll, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n, m, x, y, cnt, deg[1001], kil[1001], noti[1001];
vector<int> adj[1001];

int main()
{
        int t, tt = 1;
        scanf("%d", &t);


        while(t --){
                scanf("%d %d", &n, &m);

                memset(deg, 0, sizeof deg);
                memset(kil, 0, sizeof kil);
                memset(noti, 0, sizeof noti);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                        deg[x] ++;
                        deg[y] ++;
                }

                cnt = 0;

                queue<int> q;
                for(int i = 1; i <= n; i ++){
                        if(!deg[i]) cnt ++;
                        if(deg[i] == 1) q.push(i);
                }

                while(!q.empty()){
                        int u = q.front();
                        q.pop();

                        bool flag = false;
                        if(!noti[u]) cnt ++, flag = true, kil[u] = 1;
                        deg[u] --;

                        for(int i = 0;i < adj[u].size(); i ++){
                                int v = adj[u][i];
                                deg[v] --;
                                if(flag && !kil[v]){
                                        noti[v] = 1;
                                }
                                if(deg[v] == 1 && !kil[v]) q.push(v);
                        }
                }

                printf("Case %d: %d\n", tt ++, cnt);

                for(int i = 0; i <= n; i ++) adj[i].clear();
        }

        return 0;
}
