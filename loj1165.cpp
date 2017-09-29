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

map<ll, int> state;
int mask, tt = 1, tmp[8];
bool is_prime[21] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0};

struct node{
        int step;
        int vec[8];
        node(int _step, int _vec[8]){
                step = _step;
                for(int i = 0; i < 8;i ++) vec[i] = _vec[i];
        }

};

ll hash_ret()
{
        ll ret = 0;
        for(int i = 0;i < 8;i ++){
                ret = (ret * 10 + (tmp[i] + 1));
        }
        return ret;
}

int bfs()
{
        queue<node> q;
        q.push(node(0, tmp));

        state[hash_ret()] = 1;

        while(!q.empty()){
                node u = q.front();
                q.pop();

                if(u.vec[0] == 0 && u.vec[1] == 1 && u.vec[2] == 2 && u.vec[3] == 3 && u.vec[4] == 4 && u.vec[5] == 5 && u.vec[6] == 6 && u.vec[7] == 7){
                        return u.step;
                }

                for(int i = 0; i < 8;i ++){
                        if(check(mask, u.vec[i])){
                                for(int j = 0; j < 8; j ++){
                                        if(i == j || check(mask, u.vec[j])) continue;

                                        if(is_prime[u.vec[i] + u.vec[j] + 2]){

                                                if(j < i){
                                                        for(int k = 0; k < 8;k ++) tmp[k] = u.vec[k];
                                                        int fn = abs(i - j);
                                                        for(int k = 1; k <= fn; k ++){
                                                                swap(tmp[i - k], tmp[i - k + 1]);
                                                                if(k == fn - 1 && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                                if(k == fn && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                        }
                                                        for(int k = 0; k < 8;k ++) tmp[k] = u.vec[k];

                                                        for(int k = 1; k <= fn; k ++){
                                                                swap(tmp[j + k], tmp[j + k - 1]);
                                                                if(k == fn - 1 && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                                if(k == fn && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                        }

                                                }
                                                else{
                                                        int fn = abs(i - j);
                                                        for(int k = 0; k < 8;k ++) tmp[k] = u.vec[k];
                                                        for(int k = 1; k <= fn; k ++){
                                                                swap(tmp[i + k], tmp[i + k - 1]);
                                                                if(k == fn - 1 && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                                if(k == fn && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                        }
                                                        for(int k = 0; k < 8;k ++) tmp[k] = u.vec[k];
                                                        for(int k = 1; k <= fn; k ++){
                                                                swap(tmp[j - k], tmp[j - k + 1]);
                                                                if(k == fn - 1 && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                                if(k == fn && state.find(hash_ret()) == state.end()){
                                                                        state[hash_ret()] = 1;
                                                                        q.push(node(u.step + 1, tmp));
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
        return -1;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        int t;
        scanf("%d", &t);

        while(t --){
                mask = 0;

                for(int i = 0; i < 8; i ++){
                        scanf("%d", &tmp[i]);
                        if(tmp[i] < 0){
                                mask |= (1 << (abs(tmp[i]) - 1));
                                tmp[i] *= -1;
                        }
                        tmp[i] --;
                }

                int ans = bfs();

                printf("Case %d: %d\n", tt ++, ans);
                state.clear();

        }

        return 0;
}

