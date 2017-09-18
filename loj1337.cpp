#include<bits/stdc++.h>
using namespace std;

char g[505][505];
int n, m, x , y, q, ans[250010], mat[505][505], visited[505][505];

int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};

void dfs(int r, int c, int fil)
{
        mat[r][c] = fil;
        if(g[r][c] == 'C') ans[fil] ++;
        visited[r][c] = 1;
        //cout << r <<" " << c << endl;
        for(int i = 0; i < 4;i ++){
                int nr = row[i] + r;
                int nc = col[i] + c;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '#'){
                        if(!visited[nr][nc]) dfs(nr, nc, fil);
                }

        }
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d", &n, &m, &q);

                memset(visited, 0, sizeof visited);
                memset(mat, 0, sizeof mat);
                memset(ans, 0, sizeof ans);

                for(int i = 0; i < n; i ++){
                        scanf("%s", g[i]);
                }
                int go = 0;
                for(int i = 0; i < n; i ++){
                        for(int j = 0; j < m; j ++){
                                if(g[i][j] != '#' && (g[i][j] == '.' || g[i][j] == 'C') && !visited[i][j]){
                                        go ++;
                                        dfs(i, j, go);
                                }
                        }
                }
                printf("Case %d:\n", tt ++);
                while(q --){
                        scanf("%d %d", &x, &y);
                        x --, y --;
                        printf("%d\n", ans[mat[x][y]]);
                }


        }



        return 0;
}
