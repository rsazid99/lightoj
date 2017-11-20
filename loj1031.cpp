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
int arr[102], pfsum[102], sfsum[102], n, dp[101][101][2];

int dpfun(int i, int j, int pl)
{
        if(j < i) return 0;

        if(dp[i][j][pl] != -1) return dp[i][j][pl];

        int ret = pl ? INT_MAX : INT_MIN;

        for(int k = i; k <= j; k ++){

                if(!pl){
                        ret = max(ret, pfsum[k] - pfsum[i - 1] + dpfun(k + 1, j, 1 - pl));
                        ret = max(ret, sfsum[k] - sfsum[j + 1] + dpfun(i, k - 1, 1 - pl));
                }
                else{
                        ret = min(ret, - (pfsum[k] - pfsum[i - 1]) + dpfun(k + 1, j, 1 - pl));
                        ret = min(ret, - (sfsum[k] - sfsum[j + 1]) + dpfun(i, k - 1, 1 - pl));
                }
        }

        return dp[i][j][pl] = ret;
}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                        pfsum[i] = arr[i] + pfsum[i - 1];
                }
                sfsum[n + 1] = 0;
                for(int i = n; i > 0; i --){
                        sfsum[i] = sfsum[i + 1] + arr[i];
                }

                memset(dp, -1, sizeof dp);
                int ans = dpfun(1, n, 0);

                printf("Case %d: %d\n", tt ++, ans);
        }

        return 0;
}
