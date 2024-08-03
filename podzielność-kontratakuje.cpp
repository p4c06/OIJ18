#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;

    string napis;
    cin>>napis;

    if (napis.size() == 1){
        
        if (stoi(napis) % n){
            cout<<"1\n";
            cout<<napis;
        }
        else {
            cout<<"0\n";
        }
    }
    if (napis.size() == 2){
        bool ok1 = 0, ok2 = 0, okrazem = 0;
         
        if (((napis[0] - 48) +  (napis[1] - 48)) % n){
            okrazem = 1;
        }
        if ((napis[0] - 48) % n)
            ok1 = 1;
        if ((napis[1] - 48) % n)
            ok2 = 1; 

        if (okrazem and ok1 and ok2)
            cout<<2<<'\n'<<napis[0]<<napis[1];
        else if (ok1 or ok2)
            cout<<1<<'\n'<<(ok1)? napis[0]: napis[1];
        else
            cout<<0<<"\n";
    }
}