#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string kolejka;
    cin>>n>>kolejka;

    int pocz, kon;
    
    for (int i= n-1; i >= 0; --i){
        if (kolejka[i] == 'X'){
            kon = i;
            break;

        }    
    }

    for (int i = 0; i < n; ++i){
        if (kolejka[i] == 'X'){
            pocz = i;
            break;
        }
    }
  
    int ile = (kon-pocz);
    cout<<ile + n- pocz;

    

    
}