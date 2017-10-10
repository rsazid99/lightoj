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

int n, m, s, shop[20], x, y, z, dist[505][505], ase[505], cost[18][150000];
vector<ii> adj[505];
vector<int> vec;

struct node{
        int no, cost, mask;
        node(int _no, int _cost, int _mask)
        {
                no = _no;
                cost = _cost;
                mask = _mask;
        }
        bool operator < (const node oth) const{
                return cost > oth.cost;
        }
};

void dijkstra(int st)
{
        priority_queue<ii, vector<ii> , greater<ii> > pq;
        dist[st][st] = 0;
        pq.push(ii(0, st));

        while(!pq.empty()){
                ii u = pq.top();
                pq.pop();

                if(dist[st][u.second] != u.first) continue;
                if(ase[u.second] && u.second != st) continue;

                for(int i = 0;i < adj[u.second].size(); i ++){
                        int v = adj[u.second][i].first;
                        int co = adj[u.second][i].second;
                        if(dist[st][v] > dist[st][u.second] + co){
                                dist[st][v] = dist[st][u.second] + co;
                                pq.push(ii(dist[st][v], v));
                        }
                }
        }
}



ii dijkstra2()
{
        memset(cost, 63, sizeof cost);
        priority_queue<node> pq;
        cost[0][1] = 0;
        pq.push(node(0, 0, 1));

        while(!pq.empty()){
                node u = pq.top();
                pq.pop();

                if(cost[u.no][u.mask] != u.cost) continue;

                for(int i = 0; i < vec.size();i ++){
                        if(dist[vec[u.no]][vec[i]] == inf) continue;
                        int nmask = u.mask;
                        if(!check(u.mask, i)) nmask |= (1 << i);
                        if(cost[i][nmask] > cost[u.no][u.mask] + dist[vec[u.no]][vec[i]]){
                                cost[i][nmask] = cost[u.no][u.mask] + dist[vec[u.no]][vec[i]];
                                pq.push(node(i, cost[i][nmask], nmask));
                        }

                }
        }
        ii ret = ii(-1, -1);
        int last = vec.size() - 1;
        for(int i = 0; i < (1 << vec.size()); i ++){
                if(cost[last][i] < inf){
                        if(__builtin_popcount(i) > ret.first){
                                ret.first = __builtin_popcount(i);
                                ret.second = cost[last][i];
                        }
                        else if(__builtin_popcount(i) == ret.first && cost[last][i] < ret.second){
                                ret.second = cost[last][i];
                        }
                }
        }
        if(!ase[0] && ret.first != -1) ret.first --;
        if(!ase[n - 1] && ret.first != -1) ret.first --;

        return ret;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d", &n, &m, &s);

                memset(ase, 0, sizeof ase);

                vec.push_back(0);
                for(int i = 1; i <= s;i ++){
                        scanf("%d", &shop[i]);
                        ase[shop[i]] = 1;
                        if(shop[i] != 0) vec.push_back(shop[i]);
                }
                if(!ase[n - 1]) vec.push_back(n - 1);
                sort(vec.begin(), vec.end());

                for(int i = 1; i <= m;i ++){
                       scanf("%d %d %d", &x, &y, &z);
                       adj[x].push_back(ii(y, z));
                }
                memset(dist, 63, sizeof dist);
                for(int i = 0; i < vec.size(); i ++){
                        dijkstra(vec[i]);
                }

                ii ans = dijkstra2();

                if(ans == ii(-1, -1)) printf("Case %d: Impossible\n", tt ++);
                else printf("Case %d: %d %d\n", tt ++, ans.first, ans.second);
                vec.clear();
                for(int i = 0; i < n;i ++) adj[i].clear();
        }


        return 0;
}



