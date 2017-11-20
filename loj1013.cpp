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
char s1[40], s2[40];
int n, m;
ll dp1[100][100], dp2[70][35][35], ans1, ans2;

ll dpfun1(int i, int j)
{
        if(i == n && j == m) return 0;

        if(dp1[i][j] != -1) return dp1[i][j];

        ll ret = LLONG_MAX;

        if(i < n && j < m){
                if(s1[i] == s2[j]) ret = min(ret, 1 + dpfun1(i + 1, j + 1));
                else ret = min(ret, min(1 + dpfun1(i + 1, j), 1 + dpfun1(i, j + 1)));
        }
        else if(i == n){
                ret = min(ret, 1 + dpfun1(i, j + 1));
        }
        else if(j == m){
                ret = min(ret, 1 + dpfun1(i + 1, j));
        }


        return dp1[i][j] = ret;
}

ll dpfun2(int idx, int i, int j){
        if(idx == ans1 - 1) return 1;

        if(dp2[idx][i][j] != -1) return dp2[idx][i][j];

        ll ret = 0;

        if(i < n && j < m){
                if(s1[i] == s2[j] && idx + 1 + dp1[i + 1][j + 1] == ans1) ret += dpfun2(idx + 1, i + 1, j + 1);
                else{
                        if(idx + 1 + dp1[i + 1][j] == ans1) ret += dpfun2(idx + 1, i + 1, j);
                        if(idx + 1 + dp1[i][j + 1] == ans1) ret += dpfun2(idx + 1, i, j + 1);
                }
        }
        else if(i == n){
                if(idx + 1 + dp1[i][j + 1] == ans1) ret += dpfun2(idx + 1, i, j + 1);
        }
        else if(j == m){
                if(idx + 1 + dp1[i + 1][j] == ans1) ret += dpfun2(idx + 1, i + 1, j);
        }

        return dp2[idx][i][j] = ret;
}



int main()
{

        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%s %s", &s1, &s2);
                n = strlen(s1);
                m = strlen(s2);

                memset(dp1, -1, sizeof dp1);
                memset(dp2, -1, sizeof dp2);

                ans1 = dpfun1(0, 0);

                ans2 = dpfun2(0, 0, 0);

                printf("Case %d: %lld %lld\n", tt ++, ans1, ans2);
        }

        return 0;
}
