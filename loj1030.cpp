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
double G[101];
double dp[101];
int n;

double dpfun(int x)
{
        if(x == n) return G[n];

        if(dp[x] > 0.0000) return dp[x];

        double ret = 0.00;

        int cnt = 0;
        for(int i = 1; i <= 6; i ++){
                if(x + i <= n){
                        ret += (1.00 / 6.00) * (dpfun(x + i) + G[x]);
                        cnt ++;
                }
        }

        ret *= 6.00;
        ret /= cnt;
        return dp[x] = ret;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%lf", &G[i]);
                }
                memset(dp, 0, sizeof dp);
                double ans = dpfun(1);

                printf("Case %d: %.8f\n", tt ++, ans);
        }

        return 0;
}
