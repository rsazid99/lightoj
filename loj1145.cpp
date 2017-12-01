//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             100000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
int n, k, s;
ll dp[2][15001];

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d", &n, &k, &s);
                memset(dp, 0, sizeof dp);
                int pre = 0, now = 1;
                dp[0][0] = 1;
                for(int i = 1; i <= n; i ++){
                        dp[now][0] = 0;
                        for(int j = 1; j <= s; j ++){
                                dp[now][j] = ((dp[pre][j - 1] + dp[now][j - 1]) % mod - ((j - k - 1) >= 0 ? dp[pre][j - k - 1] : 0)) % mod;
                                if(dp[now][j] < 0) dp[now][j] += mod;
                        }
                        swap(now, pre);
                }

                printf("Case %d: %lld\n", tt ++, dp[n % 2][s]);

        }

        return 0;
}
