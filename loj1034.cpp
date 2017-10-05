
//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################
//############Created by Sazid Rahman Simanto on 3/20/17.#############
//#####Copyright © 2017 Sazid Rahman Simanto. All rights reserved.####
//####################################################################

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <math.h>
#include <vector>
#include <utility>
#include <bitset>
#include <list>
#include <algorithm>
#include <complex>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;

typedef pair<long long , ll> ii;
typedef complex<double> base;
const double PI = acos(- 1);
typedef long double ld;

template <class T> inline T bigmod(T a, T b, T M) {
        ll ret = 1;
        for(; b > 0; b >>= 1) {
                if(b & 1) ret = (ret * a) % M;
                a = (a * a) % M;
        }
        return (T)ret;
}

template <class T> inline T gcd(T a,T b){

        while (a && b)a > b ? a %= b : b %= a;
        return a + b;
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
                pii r = exEuclid(b, a%b);
                return pii(r.ss, r.ff-r.ss*(a/b));
        }
}

int modInv(int a, int m) { pii ret = exEuclid(a, m); return ((ret.ff % m) + m ) % m; }

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(int N, int pos) {return (bool) (N & (1 << pos));}

//####################################################################
//##################Template Ends Here################################
//####################################################################
int n, m, x, y, visited[10010], cc, compo[10010];
vector<int> adj[10010], radj[10010], cadj[10010];
stack<int> stk;
void dfs1(int u)
{
        visited[u] = 1;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(!visited[v]) dfs1(v);
        }
        stk.push(u);
}

void dfs2(int u)
{
        visited[u] = 2;
        compo[u] = cc;
        for(int i = 0; i < radj[u].size(); i ++){
                int v = radj[u][i];
                if(visited[v] != 2) dfs2(v);
        }
}

void dfs3(int u)
{
        visited[u] = 3;
        for(int i = 0; i < cadj[u].size(); i ++){
                int v = cadj[u][i];
                if(visited[v] != 3) dfs3(v);
        }

}


int main() {

        //read();
        //ios_base::sync_with_stdio(false); //cin.tie(NULL);cout.tie(NULL);
        //write();

        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);
                MSET(visited, 0);

                FOR(i, 1, m){
                        scanf("%d %d", &x, &y);
                        adj[x].pb(y);
                        radj[y].pb(x);
                }
                FOR(i, 1 ,n){
                        if(!visited[i]) dfs1(i);
                }
                cc = 0;
                while(!stk.empty()){
                        int v = stk.top();
                        stk.pop();

                        if(visited[v] != 2){
                                cc ++;
                                dfs2(v);
                        }
                }
                for(int i = 1;i <= n;i ++){
                        for(int j = 0; j < adj[i].size(); j ++){
                                int v = adj[i][j];
                                if(compo[i] != compo[v]){
                                        cadj[compo[i]].push_back(compo[v]);
                                }
                        }
                }
                int ans = 0;
                for(int i = 1; i <= cc;i ++){
                        if(visited[i] != 3){
                                ans ++;
                                dfs3(i);
                        }
                }

                printf("Case %d: %d\n", tt++, ans);

                FOR(i, 0, n){
                        adj[i].clear();
                        radj[i].clear();
                        cadj[i].clear();
                }
        }

        return 0;
}
