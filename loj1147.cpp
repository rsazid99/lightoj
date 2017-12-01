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
int n, x, sum;
vector<int> v;
ll dp[55000];

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                sum = 0;
                for(int i = 1; i <= n; i ++){
                        scanf("%d", &x);
                        v.push_back(x);
                        sum += x;
                }
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());
                memset(dp, 0, sizeof dp);

                dp[0] = 1;

                for(int i = 0; i < n; i ++){
                        for(int j = sum / 2; j >= v[i]; j --){
                                dp[j] |= (dp[j - v[i]] << 1LL);
                        }
                }

                int odd = n / 2, even = (n + 1) / 2;
                int i;
                for(i = sum /2; i >= 0; i --){
                        if(dp[i] & (1LL << odd)) break;
                        if(dp[i] & (1LL << even)) break;
                }

                printf("Case %d: %d %d\n", tt ++ , min(i, sum - i), max(i, sum - i));
                v.clear();
        }

        return 0;
}
