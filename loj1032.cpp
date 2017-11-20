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

typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
int n, en;
ii dp[34][3];

ii dpfun(int i, int last, int mask, int id)
{
        if(i == en + 1) return ii(0, 0);

        if(dp[i][last] != ii(-1, -1)) return dp[i][last];

        ii ret = ii(0, 0);
        int tmask = mask;

        tmask |= (1 << id);
        if(tmask <= n){
                ii res = dpfun(i + 1, 1, tmask, id - 1);
                if(last == 1){
                        ret.ff = 1 + (res.ss + res.ff) + ret.ff;
                        ret.ss = res.ss + 1;
                }
                else{
                        cout << i <<" " << res.ff << " " << res.ss << endl;
                        ret.ff = res.ff;
                        ret.ss = 0;
                }
        }

        ii res = dpfun(i + 1, 0, mask, id - 1);
        ret.ff += res.ff;
        ret.ss += res.ss;

        return dp[i][last] = ret;

}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);
                for(int i = 0; i < 32; i ++) if(check(n, i)) en = i;
                memset(dp, -1, sizeof dp);



                ii ans = dpfun(0, 0, 0, en);

                printf("Case %d: %lld\n", tt ++, ans.ff);
        }

        return 0;
}
