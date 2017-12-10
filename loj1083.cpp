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
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n;
ll arr[maxn], leftt[maxn];
stack<int> stk;

int main()
{
        //freopen("out.txt", "w", stdout);
        int t, tt = 1;
        scanf("%d", &t);
        while(t --){

                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf(" %lld", &arr[i]);
                }


                ll ans = 0;

                for(int i = 1; i <= n; i ++){
                        if(stk.empty()){
                                stk.push(i);
                                ans = max(ans, arr[i]);
                                leftt[i] = 0;
                        }
                        else if(arr[stk.top()] <= arr[i]){
                                leftt[i] = stk.top();
                                stk.push(i);
                                ans = max(ans, arr[i]);
                        }
                        else{
                                while(!stk.empty() && arr[stk.top()] >= arr[i]){
                                        ans = max(ans, (1LL * (i - leftt[stk.top()] - 1)) * arr[stk.top()]);
                                        stk.pop();
                                }
                                if(stk.empty()){
                                        leftt[i] = 0;
                                }
                                else leftt[i] = stk.top();
                                stk.push(i);
                                ans = max(ans, arr[i]);
                        }
                }
                while(!stk.empty()){
                        ans = max(ans, (1LL * (n - leftt[stk.top()])) * arr[stk.top()]);
                        stk.pop();
                }
                printf("Case %d: %lld\n", tt ++, ans);

        }

        return 0;
}
