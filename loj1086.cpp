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

typedef pair<int, double> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
int n, m, mat[17][17], x, y, z, dp[65536], deg[17], sum;

int dpfun(int mask)
{
        if(mask == (1 << n) - 1) return 0;

        if(dp[mask] != -1) return dp[mask];

        int ret = inf;

        for(int i = 0;i < n; i ++){
                if(!(mask & (1 << i))){
                        for(int j = 0; j < n; j ++){
                                if(i != j && !(mask & (1 << j)) && mat[i][j] != inf){
                                        int tmask = mask;
                                        tmask |= (1 << i);
                                        tmask |= (1 << j);
                                        ret = min(ret, mat[i][j] + dpfun(tmask));

                                }
                        }
                }
        }
        return dp[mask] = ret;
}


int main()
{
        //freopen("out.txt", "w", stdout);
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                memset(mat, 63, sizeof mat);
                memset(deg, 0, sizeof deg);
                sum = 0;
                for(int i = 1; i <= m; i ++){
                        scanf("%d %d %d", &x, &y, &z);
                        x --, y --;
                        deg[x] ++;
                        deg[y] ++;
                        mat[x][y] = min(mat[x][y], z);
                        mat[y][x] = min(mat[y][x], z);
                        sum += z;
                }

                for(int k = 0; k < n; k ++){
                        for(int i = 0; i < n; i ++){
                                for(int j = 0; j < n; j ++){
                                        if(mat[i][j] > mat[i][k] + mat[k][j]) mat[i][j] = mat[i][k] + mat[k][j];
                                }
                        }
                }
                memset(dp, -1, sizeof dp);

                int mask = 0;
                for(int i = 0; i < n; i ++){
                        if(deg[i] % 2 == 0) mask |= (1 << i);
                }

                int ans = dpfun(mask);

                printf("Case %d: %d\n", tt ++, ans + sum);

        }
        return 0;
}
