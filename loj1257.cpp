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

int n, x, y, w, dist[30010], dist1[30010], dist2[30010];
vector<ii> adj[30010];


int dijkstra()
{
        memset(dist, 63, sizeof dist);
        dist[0] = 0;
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, 0));
        int mx = 0, ret = 0;
        while(!pq.empty()){
                ii u = pq.top();
                pq.pop();

                if(dist[u.second] != u.first) continue;
                if(u.first > mx){
                        mx = u.first;
                        ret = u.second;
                }

                for(int i = 0; i < adj[u.second].size(); i ++){
                        int v = adj[u.second][i].first;
                        int we = adj[u.second][i].second;
                        if(dist[v] > dist[u.second] + we){
                                dist[v] = dist[u.second] + we;
                                pq.push(ii(dist[v], v));
                        }

                }
        }
        return ret;
}

int dijkstra1(int src)
{
        memset(dist1, 63, sizeof dist1);
        dist1[src] = 0;
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, src));
        int mx = 0, ret = 0;
        while(!pq.empty()){
                ii u = pq.top();
                pq.pop();

                if(dist1[u.second] != u.first) continue;
                if(u.first > mx){
                        mx = u.first;
                        ret = u.second;
                }

                for(int i = 0; i < adj[u.second].size(); i ++){
                        int v = adj[u.second][i].first;
                        int we = adj[u.second][i].second;
                        if(dist1[v] > dist1[u.second] + we){
                                dist1[v] = dist1[u.second] + we;
                                pq.push(ii(dist1[v], v));
                        }

                }
        }
        return ret;
}

void dijkstra2(int src)
{
        memset(dist2, 63, sizeof dist2);
        dist2[src] = 0;
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, src));

        while(!pq.empty()){
                ii u = pq.top();
                pq.pop();

                if(dist2[u.second] != u.first) continue;

                for(int i = 0; i < adj[u.second].size(); i ++){
                        int v = adj[u.second][i].first;
                        int we = adj[u.second][i].second;
                        if(dist2[v] > dist2[u.second] + we){
                                dist2[v] = dist2[u.second] + we;
                                pq.push(ii(dist2[v], v));
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

                for(int i = 1; i < n; i ++){
                        scanf("%d %d %d", &x, &y, &w);
                        adj[x].push_back(ii(y, w));
                        adj[y].push_back(ii(x, w));
                }
                int node1 = dijkstra();
                int node2 = dijkstra1(node1);
                dijkstra2(node2);


                printf("Case %d:\n", tt ++);
                for(int i = 0; i < n; i ++){
                        printf("%d\n", max(dist1[i], dist2[i]));
                }

                for(int i = 0; i < n; i ++) adj[i].clear();
        }

        return 0;
}
