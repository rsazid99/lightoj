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
vector<ii>adj[101];
int dis[101];
struct node{
    int v,w;
    node(int _v,int _w){
        v=_v;
        w=_w;
    }
};
bool operator<(node a,node b)
{
    return a.w>b.w;
}


int main()
{
    //std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("output.txt", "w", stdout);
    int t,tt=1,n,m,x,y,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        FOR(i,0,m-1){
            scanf("%d %d %d",&x,&y,&w);
            adj[x].pb(ii(y,w));
            adj[y].pb(ii(x,w));
        }
        priority_queue<node>pq;
        MSET(dis,63);
        dis[1]=0;
        pq.push(node(1,0));
        while(!pq.empty()){
            node u=pq.top();
            pq.pop();

            if(u.w>dis[u.v]) continue;

            for(int i=0;i<adj[u.v].size();i++){
                int no=adj[u.v][i].first;
                int wi=adj[u.v][i].second;
                if(dis[no]>u.w+wi){
                    dis[no]=u.w+wi;
                    pq.push(node(no,dis[no]));
                }
            }

        }
        printf("Case %d: ",tt++);
        if(dis[n]==inf) printf("Impossible\n");
        else printf("%d\n",dis[n]);

        FOR(i,0,n) adj[i].clear();
    }

    return 0;
}
