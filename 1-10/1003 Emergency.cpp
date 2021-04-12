#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

using PII = pair<int, int>;
const int N = 505;
int n, m, st, ed;
int a[N], cnt[N], max_team[N], dist[N];
bool vis[N];
vector<vector<PII> > b(N);

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[st] = 0;
    max_team[st] = a[st];
    cnt[st] = 1;
    heap.push({0, st});
    while(heap.size()){
        PII u = heap.top();
        int x = u.second, w = u.first;
        heap.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = 0; i < b[x].size(); i++){
            int y = b[x][i].first, d = b[x][i].second;
            if(dist[x] + d < dist[y]){
                dist[y] = dist[x] + d;
                cnt[y] = cnt[x];
                max_team[y] = max_team[x] + a[y];
                heap.push({dist[y], y});
            }else if(dist[x] + d == dist[y]){
                cnt[y] += cnt[x];
                max_team[y] = max(max_team[y], max_team[x] + a[y]);
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d\n", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++){
        int x, y, z;
        scanf("%d%d%d\n", &x, &y, &z);
        b[x].push_back({y, z});
        b[y].push_back({x, z});
    }
    dijkstra();
    // for(int i = 0; i < n; i++) cout << cnt[i] << endl;
    printf("%d %d", cnt[ed], max_team[ed]);
    return 0;
}