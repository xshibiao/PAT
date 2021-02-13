#include <iostream>
#include <cmath>
using namespace std;

int n, ans = 0;

int main(){
    scanf("%d\n", &n);
    int num = 0;
    for(int i = 1; i <= n; i++){
        int floor;
        scanf("%d", &floor);
        if(floor > num){
            ans += (floor - num) * 6 + 5;
            num = floor;
        }else if(floor < num){
            ans += (num - floor) * 4 + 5;
            num = floor;
        }else{
            ans += 5;
        }
    }
    printf("%d\n", ans);
}