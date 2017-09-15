
//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define ff  first
#define ss  second
int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(int N, int pos) {return (bool) (N & (1 << pos));}

typedef pair<int, int> ii;


int n, ax, ay, bx, by, cx, cy;
int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};
char g[12][12];
bool visited[11][11][11][11][11][11];

struct node{
        int x1, y1, x2, y2, x3, y3, step;
        node(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _step){
                x1 = _x1;
                y1 = _y1;
                x2 = _x2;
                y2 = _y2;
                x3 = _x3;
                y3 = _y3;
                step = _step;
        }

};

bool is_valid(ii a)
{
        if(a.ff >= 0 && a.ff < n && a.ss >= 0 && a.ss < n && g[a.ff][a.ss] != '#') return true;
        return false;
}


int bfs()
{
        queue<node> q;
        memset(visited, 0, sizeof visited);
        q.push(node(ax, ay, bx, by, cx, cy, 0));
        visited[ax][ay][bx][by][cx][cy] = true;

        while(!q.empty()){

                node u = q.front();
                q.pop();

                if(g[u.x1][u.y1] == 'X' && g[u.x2][u.y2] == 'X' && g[u.x3][u.y3] == 'X'){
                       return u.step;
                }
                ii x = ii(u.x1, u.y1);
                ii y = ii(u.x2, u.y2);
                ii z = ii(u.x3, u.y3);

                for(int i = 0; i < 4; i ++){
                        ii a = ii(u.x1 + row[i], u.y1 + col[i]);
                        ii b = ii(u.x2 + row[i], u.y2 + col[i]);
                        ii c = ii(u.x3 + row[i], u.y3 + col[i]);

                        if(!is_valid(a)) a = x;
                        if(!is_valid(b)) b = y;
                        if(!is_valid(c)) c = z;

                        for(int j = 0; j < 3; j ++){
                                if(a == b || a == c) a = x;

                                if(b == c || b == a) b = y;

                                if(c == a || c == b) c = z;
                        }
                        if(!visited[a.ff][a.ss][b.ff][b.ss][c.ff][c.ss]){
                                visited[a.ff][a.ss][b.ff][b.ss][c.ff][c.ss] = true;
                                q.push(node(a.ff, a.ss, b.ff, b.ss, c.ff, c.ss, u.step + 1));
                        }
                }

        }


        return -1;

}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);
                int cnt = 0;
                for(int i = 0; i < n; i ++){
                        scanf("%s", g[i]);
                        for(int j = 0; j < n; j ++){
                                if(g[i][j] == 'A') ax = i, ay = j;
                                if(g[i][j] == 'B') bx = i, by = j;
                                if(g[i][j] == 'C') cx = i, cy = j;
                        }
                }

                int ans = bfs();
                printf("Case %d: ", tt ++);
                if(ans == -1) printf("trapped\n");
                else printf("%d\n", ans);
        }


        return 0;
}
