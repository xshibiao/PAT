#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool isPrime(int x){
    if(x == 1) return false;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true; 
}

bool reverse(int x, int y){
    vector<int> res;
    while(x){
        res.push_back(x % y);
        x /= y;
    }
    int ans = 0;
    for(int i:res) ans = ans * y + i;
    return isPrime(ans);
}

int main(){
    int N, D;
    while(scanf("%d", &N) && N > 0){
        scanf("%d\n", &D);
        if(!isPrime(N) || !reverse(N, D)) puts("No");
        else puts("Yes");
    }
    return 0;
}
