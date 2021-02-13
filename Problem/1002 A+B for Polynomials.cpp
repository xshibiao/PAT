#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    map<int, float> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        float b;
        cin >> a >> b;
        mp[a] = b;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        float b;
        cin >> a >> b;
        mp[a] += b;
    }
    int count = 0;
    for(auto x = mp.rbegin(); x != mp.rend(); x++){
        if(x->second == 0) count += 1;
    }
    cout << mp.size() - count;
    for(auto x = mp.rbegin(); x != mp.rend(); x++){
        if(x->second != 0){
            cout << " ";
            printf("%d %.1f", x->first, x->second);
        }
    }
    return 0;
}
