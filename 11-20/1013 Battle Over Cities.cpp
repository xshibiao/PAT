#include <iostream>
#include <vector>
using namespace std;
using PII = pair<int, int>;
const int N = 1005;
int p[N];
int n, m, k, setCount;
vector<PII> nums;

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void unite(int u, int v){
    setCount--;
    p[find(u)] = find(v);
}

void cal(int point){
    for(int j = 1; j <= n; j++) p[j] = j;
    setCount = n;
    for(int i = 0; i < nums.size(); i++){
        int st = nums[i].first, ed = nums[i].second;
        if(st == point || ed == point) continue;
        if(find(st) != find(ed)) unite(st, ed);
    }
}

int main(){
    cin >> n >> m >> k;
    while(m--){
        int st, ed;
        cin >> st >> ed;
        nums.push_back({st, ed});
    }
    while(k--){
        int point;
        cin >> point;
        cal(point);
        printf("%d\n", max(setCount-2, 0));
    }
    return 0;
}