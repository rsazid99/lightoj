//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################
//############Created by Sazid Rahman Simanto on 3/20/17.#############
//#####Copyright 2017 Sazid Rahman Simanto. All rights reserved.######
//####################################################################

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <ctime>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <bitset>
#include <list>
#include <algorithm>
#include <complex>

using namespace std;

#define MSET(a,x) memset(a,x,sizeof a)
#define FOR(i,x,y) for(int i=(x);i<=(y);i++)
#define FORR(i,x,y) for(int i=(x);i<(y);i++)
#define ROF(i,x,y) for(int i=(y);i>=(x);i--)
#define SQ(x) ((x)*(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define ff first
#define ss second
#define pb push_back
#define inf             1061109567
#define maxn            100010
#define esp             1e-8
#define mod             1000000007
#define ll              long long
#define ull             unsigned long long
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define read()          freopen("input.txt", "r", stdin)
#define write()         freopen("output.txt", "w", stdout)

typedef vector<vector<ll> > matrix;
const int K = 2;
typedef pair<int, int> ii;
typedef complex<double> base;
const double PI = acos(- 1);

template <class T> inline T bigmod(T a, T b,T M) {
        ll ret = 1;
        for(; b > 0; b >>= 1) {
                if(b & 1) ret = (ret * a) % M;
                a = (a * a) % M;
        }
        return ret;
}

template <class T> inline T gcd ( T a, T b ) {

        while (b) {
                a = a % b;
                swap ( a, b );
        }
        return a;
}


template <class T> inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }

template <class T> inline T poww(T a, T b) {
        ll ret = 1;
        for(; b > 0; b >>= 1) {
                if(b & 1) ret = ret * a;
                a = a * a;
        }
        return (T)ret;
}

pii exEuclid(int a, int b) {
        if(b == 0) return pii(1, 0);
        else {
                pii r = exEuclid(b, a % b);
                return pii(r.ss, r.ff - r.ss * (a / b));
        }
}

int modInv(int a, int m) { pii ret = exEuclid(a, m); return ((ret.ff % m) + m ) % m; }



int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(int N, int pos) {return (bool) (N & (1 << pos));}

//####################################################################
//##################Template Ends Here################################
//####################################################################
int r, c, dp[9][(1 << 8) + 10][(1 << 8) + 10], memo[9][(1 << 8) + 10][(1 << 8) + 10], mat[9], cc;
char ch[10];

int dpfun(int ro, int cr, int pre)
{
        if(ro == r){
                if(pre == (1 << c) - 1) return 0;
                else return inf;
        }

        if(memo[ro][cr][pre] == cc) return dp[ro][cr][pre];

        int ret = inf;

        for(int i = 0; i < (1 << c); i ++){
                int tmp[3] = {pre, cr, mat[ro + 1]};
                int cnt = 0;
                for(int j = 0; j < c; j ++){
                        if(!(i & (1 << j))) continue;
                        cnt ++;
                        for(int k = 0; k < 3; k ++) tmp[k] ^= (1 << j);
                        if(j + 1 < c) for(int k = 0; k < 3; k ++) tmp[k] ^= (1 << (j + 1));
                        if(j - 1 >= 0) for(int k = 0; k < 3; k ++) tmp[k] ^= (1 << (j - 1));
                }
                if(ro == 0) ret = min(ret, cnt + dpfun(ro + 1, tmp[2], tmp[1]));
                else if(tmp[0] == (1 << c) - 1) ret = min(ret, cnt + dpfun(ro + 1, tmp[2], tmp[1]));
        }

        memo[ro][cr][pre] = cc;
        return dp[ro][cr][pre] = ret;
}


int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &r, &c);

                for(int i = 0; i < r; i ++){
                        scanf("%s", ch);
                        mat[i] = 0;
                        for(int j = 0; j < c; j ++){
                                if(ch[j] == '*') mat[i] |= (1 << j);
                        }
                }
                mat[r] = 0;
                cc ++;
                int ans = dpfun(0, mat[0], 0);

                if(ans == inf) printf("Case %d: impossible\n", tt ++);
                else printf("Case %d: %d\n", tt ++, ans);
        }

        return 0;
}
