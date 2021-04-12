#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b, c;
    bool flag = false;
    vector<int> arr;
    cin >> a >> b;
    c = a + b;
    if(c < 0){
        flag = true;
        c = abs(c);
    }
    if(c == 0) cout << c << endl;
    while(c > 0){
        arr.insert(arr.begin(), c % 10);
        c /= 10;
    }
    for(int i = 0; i < arr.size(); i++){
        if(flag){
            flag = false;
            cout << '-';
        }
        cout << arr[i];
        if(i != arr.size() - 1 && (arr.size() - i - 1) % 3 == 0) cout << ',';
    }
    return 0;
}
