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
int n, arr[1001], dp[1001][2], visited[1010];

int dpfun(int i, int bo)
{
        if(i >= n) return 0;
        if(i == n - 1 && bo) return 0;

        if(dp[i][bo] != -1) return dp[i][bo];

        int ret = 0;
        int tbo = bo;
        if(i == 0) tbo = 1;
        ret = max(arr[i] + dpfun(i + 2, tbo), dpfun(i + 1, bo));

        return dp[i][bo] = ret;

}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 0; i < n; i ++){
                        scanf("%d", &arr[i]);
                }

                memset(dp, -1, sizeof dp);

                int ans = dpfun(0, 0);

                printf("Case %d: %d\n", tt ++, ans);
        }

        return 0;
}
