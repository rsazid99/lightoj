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

int n, m, k, x, y, z, visited[1010], dist[1010];
vector<ii> adj[1010];

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d", &n, &m, &k);

                for(int i = 1;i <= m; i ++){
                        scanf("%d %d %d", &x, &y, &z);
                        adj[x].push_back(ii(y, z));
                }
                memset(visited, 0, sizeof visited);
                memset(dist, 63, sizeof dist);
                dist[k] = 0;
                priority_queue<ii, vector<ii> , greater<ii> > pq;
                pq.push(ii(0, k));
                int ans = 0;
                while(!pq.empty()){
                        ii u = pq.top();
                        pq.pop();

                        if(visited[u.second]) continue;

                        ans += u.first;
                        visited[u.second] = 1;
                        cout << " node : " << u.second << endl;

                        for(int i = 0; i < adj[u.second].size(); i  ++){
                                int v = adj[u.second][i].first;
                                int co = adj[u.second][i].second;
                                if(visited[v]) continue;
                                if(dist[v] > co){
                                        cout <<" v: " << v << endl;
                                        pq.push(ii(co, v));
                                        dist[v] = co;
                                }
                        }
                }
                if(ans == 0) printf("Case %d: impossible\n", tt ++);
                else printf("Case %d: %d\n", tt ++, ans);
                for(int i = 0;i < n; i ++) adj[i].clear();
        }

        return 0;
}


