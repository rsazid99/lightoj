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

int dp[55][4][6];
int n;
char s[55];

bool vou(char c)
{
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        else return false;
}



int dpfun(int i, int v, int c)
{
        if(v == 3 || c == 5) return 1;
        if(i == n) return 2;

        if(dp[i][v][c] != -1) return dp[i][v][c];

        int ret = 0;

        if(vou(s[i])){
                ret = dpfun(i + 1, min(v + 1, 3), 0);
        }
        else if(s[i] == '?'){
                int ret1 = dpfun(i + 1, min(v + 1, 3), 0);
                int ret2 = dpfun(i + 1, 0, min(c + 1, 5));

                if(ret1 == 2 && ret2 == 2) ret = 2;
                else if(ret1 == 1 && ret2 == 1) ret = 1;
        }
        else{
                ret = dpfun(i + 1, 0, min(c + 1, 5));
        }

        return dp[i][v][c] = ret;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){

                scanf("%s", s);

                n = strlen(s);

                memset(dp, -1, sizeof dp);

                int ans = dpfun(0, 0, 0);

                printf("Case %d: ", tt ++);

                if(ans == 0) printf("MIXED\n");
                else if(ans == 2) printf("GOOD\n");
                else printf("BAD\n");
        }

        return 0;
}
