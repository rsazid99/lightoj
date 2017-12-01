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
int arr[55], dp[2][500001], n, add = 250000;


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                }
                sort(arr + 1, arr + 1 + n);
                memset(dp, -1, sizeof dp);

                int now = 1, pre = 0;
                dp[0][add] = 0;
                for(int i = 1; i <= n;i ++){
                        for(int j = 0; j <= add; j ++){
                                if(dp[pre][add + j] != -1){
                                        if(j + arr[i] <= add) dp[now][j + arr[i] + add] = max(dp[now][j + arr[i] + add], dp[pre][j + add] + arr[i]);
                                        if(j - arr[i] >= -add) dp[now][j - arr[i] + add] = max(dp[now][j - arr[i] + add], dp[pre][j + add] + arr[i]);
                                        dp[now][j + add] = max(dp[now][j + add], dp[pre][j + add]);

                                        j *= -1;
                                        if(j + arr[i] <= add) dp[now][j + arr[i] + add] = max(dp[now][j + arr[i] + add], dp[pre][j + add] + arr[i]);
                                        if(j - arr[i] >= -add) dp[now][j - arr[i] + add] = max(dp[now][j - arr[i] + add], dp[pre][j + add] + arr[i]);
                                        dp[now][j + add] = max(dp[now][j + add], dp[pre][j + add]);

                                        j *= -1;
                                }
                        }
                        swap(pre, now);
                }
                int ans = -1;
                if(dp[n % 2][add] > 0) ans = dp[n % 2][add] / 2;

                if(ans == -1) printf("Case %d: impossible\n", tt ++);
                else printf("Case %d: %d\n", tt ++, ans);

        }
        return 0;
}
