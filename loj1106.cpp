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
int n, h;
int f[30], d[30], ti[30], cc;
int dp[30][200], memo[30][200], nxt[30][200];


int dpfun(int idx, int hr)
{
        if(idx == n || hr <= 0) return 0;

        if(memo[idx][hr] == cc) return dp[idx][hr];

        int ret = 0;
        ret = max(ret, dpfun(idx + 1, hr - ti[idx]));
        nxt[idx][hr] = 0;
        int sum = 0, komse = 0;
        for(int i = 1; i <= hr; i ++){
                sum += max(f[idx] - komse, 0);
                int tmp = dpfun(idx + 1, hr - i - ti[idx]) + sum;

                if(tmp >= ret){
                        nxt[idx][hr] = i;
                        ret = tmp;
                }
                komse += d[idx];
        }
        memo[idx][hr] = cc;
        return dp[idx][hr] = ret;
}
void print(int idx, int hr)
{
        if(idx == n){
                printf("\n");
                return;
        }

        if(idx) printf(", ");
        if(hr <= 0){
                printf("%d", 0);
                print(idx + 1, 0);
                return;
        }
        printf("%d", nxt[idx][hr] * 5);
        print(idx + 1, hr - nxt[idx][hr] - ti[idx]);
}


int main()
{
        //write();
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &h);

                for(int i = 0; i < n; i ++) scanf("%d", &f[i]);
                for(int i = 0; i < n; i ++) scanf("%d", &d[i]);
                for(int i = 0; i < n - 1; i ++) scanf("%d", &ti[i]);
                ti[n - 1] = 0;
                cc ++;

                int ans = dpfun(0, h * 12);
                printf("Case %d:\n", tt ++);
                print(0, h * 12);
                printf("Number of fish expected: %d\n", ans);
        }

        return 0;
}
