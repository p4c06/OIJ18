#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    long long suma = 0, minnp = 1e9, ilenp = 0;

    while (n--){
        int liczba;
        cin>>liczba;

        suma+=liczba;

        if (liczba % 2){
            minnp = min((long long)liczba, minnp);
            ilenp++;
        }
        
    }
    cout<<suma - ((ilenp % 2) * minnp);
    
}