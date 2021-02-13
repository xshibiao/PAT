#include <iostream>
using namespace std;

const int N = 1e5+5;

int k, a[N];
bool flag = true;

int main(){
    scanf("%d\n", &k);
    for(int i = 0; i < k; i++){
        int num;
        scanf("%d", &num);
        if(num >= 0) flag = false;
        a[i+1] = a[i] + num;
    }
    if(flag){
        printf("%d %d %d", 0, a[1] - a[0], a[k]-a[k-1]);
        return 0;
    }
    int ans = a[1], left = 1, right = k, idx = 0, mininum = 0;
    for(int i = 1; i <= k; i++){
        if(a[i] - mininum > ans){
            ans = a[i] - mininum;
            left = idx+1;
            right = i;
        }
        if(a[i] < mininum){
            mininum = a[i];
            idx = i;
        }
    }
    printf("%d %d %d", ans, a[left] - a[left-1], a[right] - a[right-1]);
    return 0;
}