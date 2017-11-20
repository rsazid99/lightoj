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

string s, t;
int a, b, k, cc;
int dp[10][2][100][100];

void process()
{
        int aa = a, bb = b;
        s = "", t = "";
        if(aa){
                while(aa){
                        s += (aa % 10) + '0';
                        aa /= 10;
                }
        }
        else s += '0';
        reverse(s.begin(), s.end());
        while(bb){
                t += (bb % 10) + '0';
                bb /= 10;
        }
        reverse(t.begin(), t.end());

}

int dpfun1(int i, int sum, int num, int fn)
{
        if(i == t.size()){
                if(num % k == 0 && sum % k == 0) return 1;
                else return 0;
        }

        if(dp[i][fn][sum][num] != -1) return dp[i][fn][sum][num];

        int ret = 0, lm = 0;
        if(fn) lm = t[i] - '0';
        else lm = 9;
        for(int j = 0; j <= lm; j ++){
                ret += dpfun1(i + 1, sum + j, (num * 10 + j) % k, fn & j == lm);
        }

        return dp[i][fn][sum][num] = ret;


}


int dpfun2(int i, int sum, int num, int fn)
{
        if(i == s.size()){
                if(num % k == 0 && sum % k == 0) return 1;
                else return 0;
        }

        if(dp[i][fn][sum][num] != -1) return dp[i][fn][sum][num];

        int ret = 0, lm = 0;
        if(fn) lm = s[i] - '0';
        else lm = 9;
        for(int j = 0; j <= lm; j ++){
                ret += dpfun2(i + 1, sum + j, (num * 10 + j) % k, fn & j == lm);
        }

        return dp[i][fn][sum][num] = ret;


}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d", &a, &b, &k);
                a --;
                if(k > 90){
                        printf("Case %d: %d\n", tt ++, 0);
                }
                else{
                        process();

                        memset(dp, -1, sizeof dp);
                        int ans = dpfun1(0, 0, 0, 1);
                        memset(dp, -1, sizeof dp);
                        ans -= dpfun2(0, 0, 0, 1);

                        printf("Case %d: %d\n", tt ++, ans);
                }

        }
}
