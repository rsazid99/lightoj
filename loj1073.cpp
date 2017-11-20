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
string srr[16], arr[16];
int n, dp[32800][17], mat[17][17];
string best;


bool ok(int ln, int p, int q)
{
        int cnt = 0;
        for(int i = arr[p].size() - ln, j = 0; j < ln && i < arr[p].size(); i ++, j ++){
                if(arr[p][i] == arr[q][j]) cnt ++;
                else break;
        }
        return cnt == ln;

}

int find_sub(int p, int q)
{
        int ans = 0, sz = min(arr[p].size(), arr[q].size()), pr = 0;
        for(int i = sz - 1; i >= 0; i --){
                if(ok(i, p, q)){
                        ans = i;
                        break;
                }
        }
        return arr[q].size() - ans;
}
int inter(int a, int b)
{
        if(a < 0) return arr[b].size();
        else return mat[a][b];
}

int dpfun(int mask, int last)
{
        if(mask == (1 << n) - 1) return dp[mask][last + 1] = 0;

        if(dp[mask][last + 1] != -1) return dp[mask][last + 1];

        int ret = inf;

        for(int i = 0; i < n; i ++){
                if(!(mask & (1 << i))){
                        ret = min(ret, dpfun(mask | (1 << i), i) + inter(last, i));
                }
        }
        return dp[mask][last + 1] = ret;
}

void find_str(int mask, int last, string crnt)
{
        if(crnt > best) return;
        if(mask == (1 << n) - 1){
                //cout << crnt << " " << best <<" "<< crnt.size() <<" " << best.size()<< endl;
                if(crnt < best) best = crnt;
                return;
        }

        for(int i = 0; i < n; i ++){
                if(mask & (1 << i)) continue;
                if(dp[mask][last + 1] == dp[mask | (1 << i)][i + 1] + inter(last, i)){
                        int need = arr[i].size() - inter(last, i);
                        find_str(mask | (1 << i), i, crnt + arr[i].substr(need));
                }
        }
}



int main()
{
        //std::ios::sync_with_stdio(false);
        //freopen("out.txt", "w", stdout);
        int t, tt = 1;
        cin >> t;


        while(t --){
                cin >> n;

                for(int i = 0; i < n; i ++){
                        cin >> srr[i];
                }

                for(int i = 0; i < n; i ++){
                        for(int j = 0; j < n; j ++){
                                if(i != j && srr[i].find(srr[j]) != string :: npos) srr[j] = "";
                        }
                }

                int it = 0;
                for(int i = 0; i < n; i ++){
                        if(srr[i] != "") arr[it ++] = srr[i];
                }
                n = it;

                for(int i = 0; i <= n; i ++){
                        for(int j = 0; j <= n; j ++){
                                if(i != j) mat[i][j] = find_sub(i, j);
                                else mat[i][j] = 0;
                        }
                }
                memset(dp, -1, sizeof dp);
                dpfun(0, -1);

                best = 'Z';
                find_str(0, -1, "");
                printf("Case %d: ", tt ++);
                cout << best << "\n";

        }

        return 0;
}
