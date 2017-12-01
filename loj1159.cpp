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

int dp[55][55][55], a, b, c;
char s1[55], s2[55], s3[55];

int dpfun(int i, int j, int k)
{
        if(i == a || j == b || k == c) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ret = 0;

        if(s1[i] == s2[j] && s2[j] == s3[k]){
                ret = max(ret, 1 + dpfun(i + 1, j + 1, k + 1));
        }
        else if(s1[i] == s2[j]){
                ret = max(ret, dpfun(i + 1, j + 1, k));
                ret = max(ret, dpfun(i, j, k + 1));
        }
        else if(s1[i] == s3[k]){
                ret = max(ret, dpfun(i + 1, j, k + 1));
                ret = max(ret, dpfun(i, j + 1, k));
        }
        else if(s2[j] == s3[k]){
                ret = max(ret, dpfun(i, j + 1, k + 1));
                ret = max(ret, dpfun(i + 1, j, k));
        }
        else{
                ret = max(ret, dpfun(i + 1, j, k));
                ret = max(ret, dpfun(i, j + 1, k));
                ret = max(ret, dpfun(i, j, k + 1));
        }

        return dp[i][j][k] = ret;
}


int main()
{
        int t, tt = 1;
        scanf("%d\n", &t);

        while(t --){
                scanf("\n%s\n%s\n%s", s1, s2, s3);
                a = strlen(s1);
                b = strlen(s2);
                c = strlen(s3);
                memset(dp, -1, sizeof dp);
                int ans = dpfun(0, 0, 0);
                printf("Case %d: %d\n", tt ++, ans);
        }

        return 0;
}
