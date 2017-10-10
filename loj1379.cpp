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

struct node{
        int u, v, cost;
        node(int _u, int _v, int _cost){
                u = _u;
                v = _v;
                cost = _cost;
        }
};
int n, m, x, y, z, st, en, p, dist1[10010], dist2[10010];
vector<ii> adj[10010], radj[10010];
vector<node> edge;


void dijkstra1()
{
        memset(dist1, 63, sizeof dist1);
        priority_queue<ii , vector<ii>, greater<ii> > pq;
        pq.push(ii(0, st));
        dist1[st] = 0;

        while(!pq.empty()){
                ii u = pq.top();
                pq.pop();

                if(dist1[u.second] != u.first) continue;

                for(int i = 0; i < adj[u.second].size(); i ++){
                        int v = adj[u.second][i].first;
                        int co = adj[u.second][i].second;
                        if(dist1[v] > dist1[u.second] + co){
                                dist1[v] = dist1[u.second] + co;
                                pq.push(ii(dist1[v], v));
                        }
                }
        }
}

void dijkstra2()
{
        memset(dist2, 63, sizeof dist2);
        priority_queue<ii , vector<ii>, greater<ii> > pq;
        pq.push(ii(0, en));
        dist2[en] = 0;

        while(!pq.empty()){
                ii u = pq.top();
                pq.pop();

                if(dist2[u.second] != u.first) continue;

                for(int i = 0; i < radj[u.second].size(); i ++){
                        int v = radj[u.second][i].first;
                        int co = radj[u.second][i].second;
                        if(dist2[v] > dist2[u.second] + co){
                                dist2[v] = dist2[u.second] + co;
                                pq.push(ii(dist2[v], v));
                        }
                }
        }
}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d %d %d", &n, &m, &st, &en, &p);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d %d", &x, &y, &z);
                        adj[x].push_back(ii(y, z));
                        radj[y].push_back(ii(x, z));
                        edge.push_back(node(x, y, z));

                }
                dijkstra1();
                dijkstra2();
                int ans = -1;
                for(int i = 0; i < m; i ++){
                        int u = edge[i].u;
                        int v = edge[i].v;
                        int cost = edge[i].cost;
                        if(dist1[u] != inf && dist2[v] != inf && dist1[u] + dist2[v] + cost <= p){
                                ans = max(ans, cost);
                        }
                }

                printf("Case %d: %d\n", tt ++, ans);

                for(int i = 1; i <= n;i ++) adj[i].clear(), radj[i].clear();
                edge.clear();

        }


        return 0;
}


