#include <iostream>
using namespace std;

char ans[3];
int idx = 0;
double res = 1;

double max(double x, double y, double z){
    if(x < y) swap(x, y);
    if(x < z) swap(x, z);
    return x;
}

int main(){
    for(int i = 0; i < 3; i++){
        double w, t, l;
        cin >> w >> t >> l;
        double x = max(w, t, l);
        res *= x;
        if(w == x) ans[idx++] = 'W';
        else if(t == x) ans[idx++] = 'T';
        else ans[idx++] = 'L';
    }
    for(int i = 0; i < 3; i++) printf("%c ", ans[i]);
    printf("%.2lf", (res*0.65 - 1)*2);
    return 0;
}