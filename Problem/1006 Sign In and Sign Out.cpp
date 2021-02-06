#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    string name, in, out;
};
vector<node> a;
vector<node> b;
int m;

bool cmp1(node u, node v){
    string x = u.in, y = v.in;
    int hour_x = (x[0] - '0')*10 + x[1] - '0', hour_y = (y[0] - '0')*10 + y[1] - '0';
    int min_x = (x[3] - '0')*10 + x[4] - '0', min_y = (y[3] - '0')*10 + y[4] - '0';
    int sec_x = (x[6] - '0')*10 + x[7] - '0', sec_y = (y[6] - '0')*10 + y[7] - '0';
    if(hour_x != hour_y) return hour_x < hour_y;
    else if(min_x != min_y) return min_x < min_y;
    else return sec_x < sec_y;
}

bool cmp2(node u, node v){
    string x = u.out, y = v.out;
    int hour_x = (x[0] - '0')*10 + x[1] - '0', hour_y = (y[0] - '0')*10 + y[1] - '0';
    int min_x = (x[3] - '0')*10 + x[4] - '0', min_y = (y[3] - '0')*10 + y[4] - '0';
    int sec_x = (x[6] - '0')*10 + x[7] - '0', sec_y = (y[6] - '0')*10 + y[7] - '0';
    if(hour_x != hour_y) return hour_x > hour_y;
    else if(min_x != min_y) return min_x > min_y;
    else return sec_x > sec_y;
}

int main(){
    cin >> m;
    for(int i = 1; i <= m; i++){
        string name, in, out;
        cin >> name >> in >> out;
        a.push_back({name, in, out});
        b.push_back({name, in, out});
    }
    sort(a.begin(), a.end(), cmp1);
    sort(b.begin(), b.end(), cmp2);
    cout << a.begin()->name << " " << b.begin()->name;
    return 0;
}