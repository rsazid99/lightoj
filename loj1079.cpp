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
double P, p[101];
int n, w, mi[101], memo[101][10010];
double dp[101][10100];

double dpfun(int i, int we)
{
        //cout << i <<" " << we << endl;
        if(i == n + 1){
                if(we >= w) return 0.00;
                else return 1.00;
        }

        if(memo[i][we] == 1) return dp[i][we];

        double ret = 1.00;
        double ret1 = dpfun(i + 1, we + mi[i]);
        ret = min(ret, ret1 + (1.00 - ret1) * p[i]);
        double ret2 = dpfun(i + 1, we);
        ret = min(ret, ret2);
        memo[i][we] = 1;
        return dp[i][we] = ret;
}

bool solve(int val)
{
        w = val;
        memset(memo, -1, sizeof memo);
        double ret = dpfun(1, 0);
        return ret < P;

}


int main()
{
        //freopen("out.txt", "w", stdout);
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%lf %d", &P, &n);
                int sum = 0;
                for(int i = 1; i <= n; i ++){
                        scanf("%d %lf", &mi[i], &p[i]);
                        sum += mi[i];
                }

                int lo = 0, hi = sum, mid = 0, ans = 0;

                while(lo <= hi){
                        mid = (lo + hi) / 2;
                        if(solve(mid)){
                                ans = mid;
                                lo = mid + 1;
                        }
                        else hi = mid - 1;
                }
                printf("Case %d: %d\n", tt ++, ans);

        }

        return 0;
}
