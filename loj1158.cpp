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

typedef pair<ll, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
char s[11];
int dp[1024][1002], cnt[10], d, n, fac[11];

int dpfun(int mask, int num)
{
        if(mask == (1 << n) - 1){
                if(num % d == 0) return 1;
                else return 0;
        }

        if(dp[mask][num] != -1) return dp[mask][num];

        int ret = 0;

        for(int i = 0; i < n; i ++){
                if(!(mask & (1 << i))){
                        ret += dpfun(mask | (1 << i), ((num * 10) % d + (s[i] - '0')) % d);
                }
        }

        return dp[mask][num] = ret;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);
        fac[0] = 1, fac[1] = 1;
        for(int i = 2; i <= 10; i ++){
                fac[i] = fac[i - 1] * i;
        }

        while(t --){
                scanf("%s %d", s, &d);
                n = strlen(s);
                memset(dp, -1, sizeof dp);
                memset(cnt, 0, sizeof cnt);
                for(int i = 0; i < n; i ++){
                        cnt[s[i] - '0'] ++;
                }
                int ans = dpfun(0, 0);

                int div = 1;
                for(int i = 0; i <= 9; i ++){
                        if(cnt[i] > 1){
                                div *= fac[cnt[i]];
                        }
                }

                printf("Case %d: %d\n", tt ++, ans / div);
        }

        return 0;
}
