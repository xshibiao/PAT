#include <iostream>
#include <string>
using namespace std;
using LL = long long;
string N1, N2;
int tag, radix;

int get(char c){
    if(c > '9') return c - 'a' + 10;
    else return c - '0';
}

LL ten(string s, LL x){
    LL ans = 0;
    for(int i = 0; i < s.size(); i++){
		// 可能会爆long long,采用double比较
		if((double) ans * x + get(s[i]) > 1e16) return 1e18;
        ans = ans * x + get(s[i]);
    }
    return ans;
}

int main(){
    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 2) swap(N1, N2);
    LL target = ten(N1, radix);
    int maxinum = 2;
    // 左边界必定是N2中最大的值加1
    for(char c: N2) maxinum = max(maxinum, get(c) + 1);
    LL l = maxinum, r = target;
    while(l < r){
        LL mid = l + (r - l) / 2;
        if(ten(N2, mid) >= target) r = mid;
        else l = mid + 1;
    }
    
    if(ten(N2, l) != target) printf("Impossible");
    else printf("%lld", l);
    return 0;
}
