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

vector<int> divi[maxn];
double dp[maxn];
int n;

double dpfun(int val)
{
        if(val == 1) return 0.00;

        if(dp[val] >= 0.000) return dp[val];
        //cout << val << endl;
        double ret = 0.00;
        int sz = divi[val].size();
        for(int i = 0; i < sz; i ++){
                if(divi[val][i] > 1)
                        ret += (1.00 / sz) * (dpfun(val / divi[val][i]) + 1.00);
        }
        ret += (1.00 / sz);
        ret *= sz;
        ret /= sz - 1.00;
        return dp[val] = ret;
}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);
        divi[1].push_back(1);
        divi[2].push_back(1);
        divi[2].push_back(2);


        for(int i = 3; i <= 100000; i ++){
                for(int j = 1; j * j <= i; j ++){
                        if(j * j == i) divi[i].push_back(j);
                        else if(i % j == 0){
                                divi[i].push_back(j);
                                divi[i].push_back(i / j);
                        }
                }
        }
        memset(dp, -1, sizeof dp);
        dp[1] = 0.00, dp[2] = 2.000;
        for(int i = 100000; i > 2; i --){
                dp[i] = dpfun(i);
        }
        while(t --){
                scanf("%d", &n);

                printf("Case %d: %.7f\n", tt ++, dp[n]);
        }

        return 0;
}
