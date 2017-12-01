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

ll dp[12][30][2][2];
ll a, b;
string s;

ll dpfun(int i, int zero, int en, int st)
{
        if(i == s.size()){
                if(st) return zero;
                else return 0;
        }

        if(dp[i][zero][en][st] != -1) return dp[i][zero][en][st];

        int ln = 9;
        if(en) ln = s[i] - '0';

        ll ret = 0;
        for(int j = 0; j <= ln; j ++){
                if(j == 0){
                        if(st) ret += dpfun(i + 1, zero + 1, en && j == ln, st);
                        else ret += dpfun(i + 1, zero, en && j == ln, st);
                }
                else ret += dpfun(i + 1, zero, en && j == ln, 1);
        }
        return dp[i][zero][en][st] = ret;
}



ll solve(ll n)
{
        if(n < 0) return 0;
        s.clear();
        while(n){
              s += n % 10 + '0';
              n /= 10;
        }
        reverse(s.begin(), s.end());
        memset(dp, -1, sizeof dp);
        ll ans = dpfun(0, 0, 1, 0);
        return ans + 1;
}

int main()
{
        //freopen("out.txt", "w", stdout);
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){

                scanf("%lld %lld", &a, &b);
                printf("Case %d: %lld\n", tt ++, solve(b) - solve(a - 1));
        }

        return 0;
}
