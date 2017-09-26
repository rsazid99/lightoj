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

int n, m, x, y, q, visited[100010], cnt, tdia;
vector<int> adj[100010];
vector<ii> vec;


int dfs(int u, int from)
{
        if(!visited[u]) visited[u] = 1, cnt ++;

        int first = 0, second = 0;

        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(v == from) continue;
                int tmp = dfs(v, u) + 1;
                if(tmp > first) second = first, first = tmp;
                else if(tmp > second) second  = tmp;
        }
        if(first + second > tdia) tdia = first + second;
        return first;

}


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                memset(visited, 0, sizeof visited);


                for(int i = 1; i <= m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }
                int dia = 0, sub = 0;
                for(int i = 1; i <= n; i ++){
                        if(!visited[i]){
                                cnt = 0;
                                tdia = 0;
                                dfs(i, -1);
                                sub = max(sub, cnt);
                                dia = max(dia, tdia);
                                vec.push_back(ii(cnt, tdia));
                        }
                }
                sort(vec.begin(), vec.end());


                scanf("%d", &q);
                printf("Case %d:\n", tt ++);
                while(q --){
                        scanf("%d", &x);
                        if(x > sub) printf("impossible\n");
                        else if(x - 1 <= dia){
                                printf("%d\n", x - 1);
                        }
                        else{
                                int ans = INT_MAX;
                                int lo = lower_bound(vec.begin(), vec.end(), ii(x, INT_MIN)) - vec.begin();
                                for(int i = lo; i < vec.size(); i ++){
                                       ans = min (ans, vec[i].second + 2 * (x - vec[i].second - 1));
                                }

                                printf("%d\n", ans);
                        }

                }
                vec.clear();
                for(int i = 1; i <= n; i ++) adj[i].clear();
        }

        return 0;
}
