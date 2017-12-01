
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
int n, m, arr[maxn], marr[maxn], cnt[maxn];

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                memset(cnt, 0, sizeof cnt);

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                        marr[i] = (marr[i - 1] + arr[i]) % m;
                }
                cnt[0] ++;
                ll ans = 0;

                for(int i = 1; i <= n;i ++){
                        ans += cnt[marr[i]];
                        cnt[marr[i]] ++;
                }

                printf("Case %d: %lld\n", tt ++, ans);
        }

        return 0;
}
