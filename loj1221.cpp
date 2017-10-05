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

int n, m, a, b, c, d, p, dist[110];
bool flag;

struct node{
        int u, v, cost;
        node(int _u, int _v, int _cost){
                u = _u;
                v = _v;
                cost = _cost;
        }
};
vector<node> edge;


void bellmanford()
{

        for(int i = 1; i < n;i ++){
                bool bo = false;
                for(int j = 0; j < m; j ++){
                        int u = edge[j].u;
                        int v = edge[j].v;
                        int cost = edge[j].cost;
                        if(dist[u] < inf && dist[v] > dist[u] + cost){
                                dist[v] = dist[u] + cost;
                                bo = true;
                        }
                }
                if(!bo) break;
        }

        for(int i = 0; i < m; i ++){
                int u = edge[i].u;
                int v = edge[i].v;
                int cost = edge[i].cost;
                if(dist[u] < inf && dist[v] > dist[u] + cost){
                        flag = true;
                        break;
                }
        }
}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){

                scanf("%d %d %d", &n, &m, &p);

                memset(dist, 0, sizeof dist);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d %d %d", &a, &b, &c, &d);
                        edge.push_back(node(a, b, (d * p) - c));
                }
                flag = false;
                bellmanford();

                if(flag) printf("Case %d: YES\n", tt ++);
                else printf("Case %d: NO\n", tt ++);

                edge.clear();
        }

        return 0;
}


