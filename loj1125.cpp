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

int q, m, d, n, cc, memo[201][22][12];
ll arr[201], dp[201][22][12];

ll dpfun(int i, ll sum, int to)
{
        if(i == n){
                if(sum % d == 0 && to == m) return 1;
                else return 0;
        }

        if(memo[i][sum][to] == cc) return dp[i][sum][to];

        ll ret = 0;

        if(to < m) ret += dpfun(i + 1, (((sum % d) + (arr[i] % d)) + d) % d, to + 1);
        ret += dpfun(i + 1, sum, to);

        memo[i][sum][to] = cc;
        return dp[i][sum][to] = ret;
}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &q);

                for(int i = 0; i < n; i ++){
                        scanf("%lld", &arr[i]);
                }
                printf("Case %d:\n", tt ++);
                while(q --){
                        cc ++;
                        scanf("%d %d", &d, &m);
                        ll ans = dpfun(0, 0, 0);
                        printf("%lld\n", ans);
                }
        }

        return 0;
}
