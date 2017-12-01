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

int n, m;
ll dp[51][51];

ll dpfun(int a, int b, int trm)
{


        ll ret = 0;
        if(!trm){
                if(a > 0){
                        for(int i = 1; i <= a; i ++){
                                ret += dpfun(i - 1, a - i + b);
                        }
                }
                else{
                        ret += dpfun()
                }
        }

}



int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                memset(dp, -1, sizeof dp);
                ll ans = dpfun(m - 1, n - m, 0);

                printf("Case %d: %lld\n", tt ++, ans);
        }

        return 0;
}
