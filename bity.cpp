#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200'000;
int tab[MAXN + 5];
int pref[MAXN + 5];



int main(){
    vector<int> pierwsze(2 * MAXN + 5, 0);
    string napis;
    cin>>napis;

    for (int i = 0; i < napis.size(); ++i){
        if (napis[i] == '0')
            tab[i+1] = -1;
        else 
            tab[i+1] = 1;
        pref[i+1] = pref[i] + tab[i+1];
        
    }
  
    pierwsze[MAXN] = 1;
    int odp = 0;
    for (int i = 1; i <= napis.size(); ++i){
        int wartosc = pierwsze[pref[i] + MAXN];
        int nr = pref[i] + MAXN;
        

        if (!wartosc)
            pierwsze[pref[i] + MAXN] = i+1;
        if (wartosc)
            odp = max(odp, i - wartosc + 1);
        
        
              
    }
    
    cout<<odp<<'\n';
}