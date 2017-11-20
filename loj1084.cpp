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
int n, k, arr[maxn], dp[maxn], memo[maxn], cc;

int dpfun(int i)
{
        if(i == n) return 0;

        if(memo[i] == cc) return dp[i];

        int ret = inf;

        int lo = upper_bound(arr, arr + n, arr[i] + 2 * k) - arr;

        if(lo - i >= 3) ret = min(ret, 1 + dpfun(lo));
        if(lo - i >= 4) ret = min(ret, 1 + dpfun(lo - 1));
        if(lo - i >= 5) ret = min(ret, 1 + dpfun(lo - 2));
        memo[i] = cc;
        return dp[i] = ret;

}


int main()
{

        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &k);

                for(int i = 0; i < n; i ++){
                        scanf("%d", &arr[i]);
                }

                sort(arr, arr + n);
                cc ++;
                dpfun(0);
                int ans = dp[0];
                if(ans == inf) ans = -1;
                printf("Case %d: %d\n", tt ++, ans);
        }

}
