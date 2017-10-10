//################################################################
//################################################################
//####In the Name Of Allah,the Most Gracious,the Most Merciful.###
//######Created by Sazid Rahman  Simanto on 2/21/16.##############
//# Copyright © 2016 Sazid Rahman  Simanto. All rights reserved.##
//################################################################
//################################################################

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<list>
#include<algorithm>
using namespace std;
#define MSET(a,x) memset(a,x,sizeof a)
#define FOR(i,x,y) for(int i=(x);i<=(y);i++)
#define ROF(i,x,y) for(int i=(y);i>=(x);i—-)
#define SQ(x) ((x)*(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())
#define ff first
#define ss second
#define PH printf(“Hello\n”);
#define pb push_back
#define inf 1061109567
#define maxn 100001
#define esp 1e-8

typedef pair<int,int> ii;
typedef pair<long long int,long long int> lii;
typedef long long int ll;
typedef vector<ii>vii;
typedef vector<int>vi;

int gcd(int a,int b){
    while (!b) {
        a=a%b;
        swap(a,b);
    }
    return a;
}

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

//################################################################
//##    Template Ends Here……                                    ##
//################################################################
vector<ii>adj[501];
int dis[501];
struct node{
    int v,mx;
    node(int _v,int _mx){
        v=_v;
        mx=_mx;
    }
};
bool operator<(node a,node b)
{
    return a.mx>b.mx;
}


int main()
{
    //std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("output.txt", "w", stdout);
    int t,tt=1,n,m,x,y,w,h;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        FOR(i,0,m-1){
            scanf("%d %d %d",&x,&y,&w);
            adj[x].pb(ii(y,w));
            adj[y].pb(ii(x,w));
        }
        scanf("%d",&h);

        priority_queue<node>pq;
        MSET(dis,63);
        dis[h]=0;
        pq.push(node(h,0));

        while(!pq.empty()){
            node u=pq.top();
            pq.pop();

            if(u.mx>dis[u.v]) continue;

            for(int i=0;i<adj[u.v].size();i++){
                int no=adj[u.v][i].first;
                int num=adj[u.v][i].second;
                num=max(num,u.mx);
                if(dis[no]>num){
                    dis[no]=num;
                    pq.push(node(no,dis[no]));
                }

            }
        }
        printf("Case %d:\n",tt++);
        for(int i=0;i<n;i++){
            if(dis[i]==inf) printf("Impossible\n");
            else printf("%d\n",dis[i]);
        }
        FOR(i,0,n) adj[i].clear();

    }

    return 0;
}
