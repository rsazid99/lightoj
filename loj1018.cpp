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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
ii arr[20];
int n, fn;
int mat[17][17], dp[65536];

bool collinear(ii a, ii b, ii c)
{
        int area = a.ff * (b.ss - c.ss) + b.ff * (c.ss - a.ss) + c.ff * (a.ss - b.ss);
        if(area == 0) return true;
        else return false;
}

int dpfun(int mask)
{
        if(mask == fn) return 0;

        if(dp[mask] != -1) return dp[mask];

        int ret = inf;

        int i;
        for(i = 0; (mask >> i) & 1; i ++);

        for(int j = 0; j < n; j ++){
                if(i != j && !(mask & (1 << i))){
                        ret = min(ret, 1 + dpfun(mask | mat[i][j]));
                }
        }

        return dp[mask] = ret;
}


int main()
{

        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 0; i < n; i ++){
                        scanf("%d %d", &arr[i].first, &arr[i].second);
                }
                fn = (1 << n) - 1;
                memset(mat, 0, sizeof mat);

                for(int i = 0; i < n; i ++){
                        for(int j = 0; j < n; j ++){
                                if(i == j) continue;
                                mat[i][j] |= (1 << i);
                                mat[i][j] |= (1 << j);
                                for(int k = 0; k < n; k ++){
                                        if(k == i || k == j) continue;
                                        if(collinear(arr[i], arr[j], arr[k])) mat[i][j] |= (1 << k);
                                }

                        }
                }
                memset(dp, -1, sizeof dp);
                int ans = dpfun(0);
                if(ans == inf) ans = 1;
                printf("Case %d: %d\n", tt ++, ans);
        }

        return 0;
}
