#include <bits/stdc++.h>
using namespace std;

map<int, int> wystapienia;

int main(){
    int n;
    cin>>n;


    for (int i = 0; i < n; ++i){
        int karta;
        cin>>karta;
        wystapienia[karta]++;
    }

    int odp = 100'000'000;
    for (int i = 0; i <= 1'000'000; ++i){
        odp = min(odp, i + wystapienia[i]);
    }

    cout<<odp + 1;
}