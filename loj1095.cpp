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

int n, m, k;
ll fac[1010];

ll nCr(int p, int q)
{
        ll up = fac[p];
        ll dw = (fac[q] * fac[p - q]) % mod;
        dw = modInv(dw, mod);
        return (up * dw) % mod;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        fac[0] = 1;
        for(int i = 1; i <= 1000; i ++){
                fac[i] = (fac[i - 1] * (i * 1LL)) % mod;
        }

        while(t --){
                scanf("%d %d %d", &n, &m, &k);

                ll val = (nCr(m, k) * fac[n - k]) % mod;
                for(int i = 1; i <= m - k; i ++){
                        if(i % 2 == 1){
                                val = (val - ((nCr(m, i) * nCr(m - i, k)) % mod * fac[n - k - i]) % mod) % mod;
                                if(val < 0) val += mod;
                        }
                        else val = (val + ((nCr(m, i) * nCr(m - i, k)) % mod * fac[n - k - i]) % mod) % mod;
                }
                printf("Case %d: %lld\n", tt ++, val);
        }
        return 0;
}
