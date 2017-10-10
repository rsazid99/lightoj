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

int n, m, x, y, z, prc[101], cap, s, t, q, dist[101][101];
vector<ii> adj[101];
struct node{
        int no, rimcap, cost;
        node(int _no, int _rimcap, int _cost)
        {
                no = _no;
                rimcap = _rimcap;
                cost = _cost;
        }
        bool operator < (const node oth) const{
                return cost > oth.cost;
        }
};

int dijkstra()
{
        memset(dist, 63, sizeof dist);
        priority_queue<node> pq;
        pq.push(node(s, 0, 0));
        dist[s][0] = 0;

        while(!pq.empty()){
                node u = pq.top();
                pq.pop();

                if(dist[u.no][u.rimcap] != u.cost) continue;
                if(u.no == t) return u.cost;

                for(int i = 0;i < adj[u.no].size(); i ++){
                        int v = adj[u.no][i].first;
                        int di = adj[u.no][i].second;
                        if(di > cap) continue;

                        if(u.rimcap >= di && dist[v][u.rimcap - di] > dist[u.no][u.rimcap]){
                                dist[v][u.rimcap - di] = dist[u.no][u.rimcap];
                                pq.push(node(v, u.rimcap - di, dist[v][u.rimcap - di]));
                        }
                }
                if(u.rimcap < cap){
                        dist[u.no][u.rimcap + 1] = dist[u.no][u.rimcap] + prc[u.no];
                        pq.push(node(u.no, u.rimcap + 1, dist[u.no][u.rimcap + 1]));
                }

        }
        return inf;

}

int main()
{

        int kase, tt = 1;
        scanf("%d", &kase);

        while(kase --){
                scanf("%d %d", &n, &m);

                for(int i = 1; i <= n;i ++) scanf("%d", &prc[i]);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d %d", &x, &y, &z);
                        x ++, y ++;
                        adj[x].push_back(ii(y, z));
                        adj[y].push_back(ii(x, z));
                }

                scanf("%d", &q);
                printf("Case %d:\n", tt++);
                while(q --){
                        scanf("%d %d %d", &cap, &s, &t);
                        s ++, t ++;
                        int ret = dijkstra();
                        if(ret == inf) printf("impossible\n");
                        else printf("%d\n", ret);
                }

                for(int i = 1; i <= n; i ++){
                        adj[i].clear();
                }
        }

        return 0;
}


