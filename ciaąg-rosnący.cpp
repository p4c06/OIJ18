#include <bits/stdc++.h>
using namespace std;

int liczby[2005];


int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; ++i){
        cin>>liczby[i];
    }
    int maxx = 0, odp = 0;
    for (int k = 1; k <= 2000; ++k){
        int maxi = 0, num = 0;
        bool OK = true;
        for (int i = 0; i < n; ++i){
            if (liczby[i] % k)
                continue;
            if (liczby[i] <= maxi){
                OK = false;
                break;
            }
            num++;
            maxi = liczby[i];
        }
        if (OK && num >maxx){
            maxx = num;
            odp = k;
        }
    }
    if (odp){
        cout<<odp;
    }
    else {
        cout<<2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
    }
}