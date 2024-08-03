#include <bits/stdc++.h>
using namespace std;

int main(){
    string tasma, zestaw;
    cin>>tasma>>zestaw;

    map<char, int> zlicz;
    map<char, int> zlicz2;

    for (char znak: zestaw)
        zlicz[znak]++;

    int limit = ceil((double)zestaw.size() / 2);
    long long odp = 0;
    
    int pocz = 0, kon = 0, n = tasma.size();
    zlicz2[tasma[0]]++;

    while (zlicz2[tasma[pocz]] > zlicz[tasma[pocz]]){
        zlicz2[tasma[pocz]]--;
        pocz++;
        kon++;
    }
    
    string fragment;
    while (kon < n){
        
        int x = zlicz[tasma[pocz+1]], y = zlicz2[tasma[pocz+1]];
        while (x > y && pocz < n-1){
            
            pocz++;
            zlicz2[tasma[pocz]]++;
            x = zlicz[tasma[pocz+1]], y = zlicz2[tasma[pocz+1]];              
        }
        // zlicz2[pocz]--;
        // pocz--;
        odp += max(0, (pocz- kon +2)-limit);
        
        zlicz2[tasma[kon]]--;
        kon++;
        if (kon >= n || pocz >= n)
            break;
        int wsk = kon+1;
        
        if (pocz <= kon && y< 2){
            
            if (wsk ==n)
                break;
            
            while (zlicz[tasma[wsk]] == 0){
            
                wsk++;
                if (wsk == n){
                    break;
                }
            }           
            
            zlicz2[tasma[kon]]--;
            kon = wsk;
            pocz = kon;
            zlicz2[tasma[pocz]]++;
            
            
        }
        
    }
    
    

    cout<<odp;
    

    
}