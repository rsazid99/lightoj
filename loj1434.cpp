
//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second

typedef pair<int, int> ii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
int r, c, q, sx, sy, level[35][35][20];
int row[] = {1, -1, 0, 0, -1, 1, 1, -1, 0};
int col[] = {0, 0, 1, -1, 1, 1, -1, -1, 0};
string mp [] = {"D", "U", "R", "L", "UR", "DR", "DL", "UL", "*" };
char g[35][35], s[20];
vector<string> ans;

struct node{
        int x, y, p;
        vector<string> vec;
        node(int _x, int _y, int _p, vector<string> _vec)
        {
                x = _x;
                y = _y;
                p = _p;
                vec = _vec;
        }

};

bool bfs(int x, int y, string ss)
{
        queue<node> q;
        vector<string> tmp;

        q.push(node(x, y, 1, tmp));
        level[x][y][0] = 0;

        while(!q.empty()){
                node u = q.front();
                q.pop();
                if(u.p == ss.size()){
                        ans = u.vec;
                        return true;
                }
                for(int i = 0; i < 9;i ++){
                        int nr = row[i] + u.x;
                        int nc = col[i] + u.y;
                        vector<string> tm = u.vec;
                        if(nr >= 0 && nr < r && nc >= 0 && nc < c && g[nr][nc] == ss[u.p] && level[nr][nc][u.p] < 0){
                                level[nr][nc][u.p] = level[u.x][u.y][u.p - 1] + 1;
                                tm.push_back(mp[i]);
                                q.push(node(nr, nc, u.p + 1, tm));
                        }
                }
        }
        return false;
}


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &r, &c);

                for(int i = 0; i < r;i ++){
                        scanf("%s", g[i]);
                }

                scanf("%d", &q);
                printf("Case %d:\n", tt ++);
                while(q--){
                        scanf("%s", s);
                        bool flag  = false;
                        memset(level, -1, sizeof level);
                        for(int i = 0;i < r; i ++){
                                for(int j = 0; j < c; j ++){
                                        if(g[i][j] == s[0]){
                                                flag = bfs(i, j, s);
                                                if(flag){
                                                        sx = i;
                                                        sy = j;
                                                        break;
                                                }
                                        }
                                }
                                if(flag) break;
                        }
                        if(!flag) printf("%s not found\n", s);
                        else  {
                                printf("%s found:", s);
                                printf(" (%d,%d),", sx + 1, sy + 1);
                                for(int i = 0; i < ans.size();i ++){
                                        if(i < ans.size() - 1) cout << " " << ans[i] <<",";
                                        else cout << " " << ans[i] <<"\n";
                                }
                        }
                        ans.clear();
                }
        }

        return 0;
}
