#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
using PII = pair<int, string>;
using PIV = pair<int, char>;
const int N = 2005;

PII A[N], C[N], M[N], E[N];
int n, m, idx = 0;
unordered_map<string, PIV> mp;

bool cmp(PII u, PII v){
    return u.first > v.first;
}

void get(PII nums[], char c){
    int rank = 1;
    unordered_map<int, int> list;
    for(int i = 0; i < idx; i++){
        int degree = nums[i].first;
        if(!list.count(degree)) list[degree] = i+1;
    }
    for(int i = 0; i < idx; i++){
        string id = nums[i].second;
        int degree = nums[i].first;
        if(!mp.count(id)) mp[id] = {list[degree], c};
        else{
            if(list[degree] < mp[id].first) mp[id] = {list[degree], c};
        }
    }
}

int main(){
    cin >> n >> m;
    while(n--){
        string sid;
        int c, m, e;
        cin >> sid >> c >> m >> e;
        int num = (c + m + e) / 3;
        if(c + m + e - num*3 >= 2) num++;
        A[idx] = {num, sid};
        C[idx] = {c, sid};
        M[idx] = {m, sid};
        E[idx++] = {e, sid};
    }
    sort(A, A+idx, cmp);
    sort(C, C+idx, cmp);
    sort(M, M+idx, cmp);
    sort(E, E+idx, cmp);
    get(A, 'A');
    get(C, 'C');
    get(M, 'M');
    get(E, 'E');
    while(m--){
        string id;
        cin >> id;
        if(mp.count(id)) cout << mp[id].first << " " << mp[id].second << endl;
        else cout << "N/A" << endl;
    }
    return 0;
}