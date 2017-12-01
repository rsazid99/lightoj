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
int cost[2][1001], dp[1001][2], arr[2][1001];
int n;

int dpfun(int i, int bi)
{
        if(i == n) return 0;

        if(dp[i][bi] != -1) return dp[i][bi];

        int ret = inf;

        ret = min(ret, arr[bi][i] + dpfun(i + 1, bi));
        ret = min(ret, arr[bi][i] + cost[bi][i] + dpfun(i + 1, 1 - bi));

        return dp[i][bi]= ret;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 0; i < n; i ++){
                        scanf("%d", &arr[0][i]);
                }

                for(int i = 0; i < n; i ++){
                        scanf("%d", &arr[1][i]);
                }

                for(int i = 0; i < n - 1; i ++){
                        scanf("%d", &cost[0][i]);
                }

                for(int i = 0; i < n - 1; i ++){
                        scanf("%d", &cost[1][i]);
                }
                memset(dp, -1, sizeof dp);
                int ans = min(dpfun(0, 0), dpfun(0, 1));

                printf("Case %d: %d\n", tt ++ , ans);
        }

        return 0;
}
