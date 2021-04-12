#include <iostream>
#include <map>
using namespace std;

const int N = 1001;

int k;
int a[N];
map<int, double> mp;
map<int, double> ans;

int main(){
    scanf("%d", &k);
    while(k--){
        int x;
        double y;
        scanf("%d%lf", &x, &y);
        a[x] = 1;
        mp[x] = y;
    }
    scanf("%d\n", &k);
    while(k--){
        int x;
        double y;
        scanf("%d%lf", &x, &y);
        for(int i = 0; i < 1001; i++){
            if(a[i] == 1){
                ans[i+x] += mp[i] * y;
            }
        }
    }
    int cnt = 0;
    for(auto x = ans.rbegin(); x != ans.rend(); x++){
        if(x->second != 0) cnt++;
    }
    printf("%d", cnt);
    for(auto x = ans.rbegin(); x != ans.rend(); x++){
        if(x->second != 0){
            cout << " ";
            printf("%d %.1lf", x->first, x->second);
        }
    }
    return 0;
}