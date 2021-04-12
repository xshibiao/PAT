#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 22;
int sum[N];
queue<int> Q[N];
unordered_map<int, int> mp;

int main(){
    int n, m, k, q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 1; i <= k; i++){
        int time, t = 0;
        scanf("%d", &time);
        for(int j = 0; j < n; j++){
            if(i <= n*m){
                if(Q[j].size() < Q[t].size()) t = j;
            }else{
                if(Q[j].front() < Q[t].front()) t = j;
            }
        }
        sum[t] += time;
        if(i > n*m) Q[t].pop();
        Q[t].push(sum[t]);
        if(sum[t] - time < 540) mp[i] = sum[t];
    }
    while(q--){
        int id;
        scanf("%d", &id);
        if(mp.find(id) != mp.end()) printf("%02d:%02d\n", mp[id]/60 + 8, mp[id]%60);
        else printf("Sorry\n");
    }
    return 0;
}
