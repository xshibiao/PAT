#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

string s;
vector<int> p;
map<int, string> mp = {{0,"zero"}, {1,"one"},{2,"two"}, {3,"three"}, {4,"four"}, {5,"five"}, {6,"six"}, {7,"seven"}, {8,"eight"}, {9,"nine"}};

int main(){
    cin >> s;
    int cnt = 0;
    for(int i = s.size()-1; i >= 0; i--){
        cnt += s[i] - '0';
    }
    if(cnt == 0) p.push_back(cnt);
    while(cnt){
        int x = cnt % 10;
        p.push_back(x);
        cnt /= 10;
    }
    reverse(p.begin(), p.end());
    for(int i = 0; i < p.size()-1; i++) cout << mp[p[i]] << " ";
    cout << mp[p.back()];
    return 0;
}