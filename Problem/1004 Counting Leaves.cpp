#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int N = 105;
int n, m;
vector<vector<int> > a(N);
vector<int> p;

int main(){
    scanf("%d%d\n", &n, &m);
    for(int i = 1; i <= m; i++){
        string root;
        int k;
        cin >> root >> k;
        int idx = (root[0] - '0')*10 + (root[1] - '0');
        for(int j = 1; j <= k; j++){
            string child;
            cin >> child;
            //cout << child << endl;
            int idx_child = (child[0] - '0') * 10 + (child[1] - '0');
            a[idx].push_back(idx_child);
        }
    }
    queue<int> q;
    q.push(1);
    while(q.size()){
        int n = q.size(), cnt = 0;
        for(int i = 1; i <= n; i++){
            int root = q.front();
            q.pop();
            int len = a[root].size();
            if(len == 0) cnt++;
            else{
                for(int i = 0; i < len; i++){
                    int x = a[root][i];
                    q.push(x);
                }
            }
        }
        p.push_back(cnt);
    }
    for(int i = 0; i < p.size()-1; i++) cout << p[i] << " ";
    cout << p.back();
    return 0;
}