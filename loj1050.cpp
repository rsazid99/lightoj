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

int r, b;
double dp[505][505];

double dpfun(int R, int B)
{
        if(B == 0) return 0.00;
        if(B == 1 && R == 0) return 1.00;

        if(dp[R][B] >= 0.00) return dp[R][B];

        double ret = 0.00;
        if(R > 0) ret += ((double) R / (R + B)) * dpfun(R - 1, B - 1);
        if(B > 1) ret += ((double) B / (R + B)) * dpfun(R, B - 2);

        return dp[R][B] = ret;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);
        memset(dp, -1, sizeof dp);

        while(t --){
                scanf("%d %d", &r, &b);

                double ans = dpfun(r , b);

                printf("Case %d: %.7f\n", tt ++, ans);
        }

        return 0;
}
