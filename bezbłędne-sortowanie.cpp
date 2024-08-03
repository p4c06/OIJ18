#include <bits/stdc++.h>
using namespace std;

int potega(int i){
    int odp = 0;
    while (i >= 10){
        i /= 10;
        ++odp;
    }
    return odp;
}

int nast[500'005];
long long liczby[500'005];
int wynik[500'005];
int poprz[500'005];


int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; ++i){
        cin>>liczby[i];
    }
    sort(liczby, liczby + n);

    int wsk = n-1;
    for (int i = liczby[n-1]; i >= 0; --i){
        while (liczby[wsk] > i){
            wsk--;
        }
        nast[i] = wsk;
    }
    if (n == 1)
        cout<<1<<'\n'<<liczby[0]<<'\n';
    if (n == 2){
        if (to_string(liczby[0]) < to_string(liczby[1]))
            cout<<2<<'\n'<<liczby[0]<<' '<<liczby[1];
        else
            cout<<1<<'\n'<<liczby[0];
    }

    wynik[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--){
        bool done = false;
        if (potega(liczby[i]) == potega(liczby[i] + 1) && wynik[i] < wynik[nast[liczby[i] + 1]] + 1){
            wynik[i] = wynik[nast[liczby[i] + 1]] + 1;
            done = true;
            poprz[i] = nast[liczby[i] + 1];
        }
        if (liczby[i] <= liczby[n-1] / 10 && wynik[i] < wynik[nast[liczby[i] * 10]] + 1){
            wynik[i] = wynik[nast[liczby[i] * 10]] + 1;
            done = true;
            poprz[i] = nast[liczby[i] * 10];
        }
        if (!done){
            wynik[i] = 1;            
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; ++i){
        if (wynik[i] > wynik[maxi])
            maxi = i;
    }

    cout<<wynik[maxi]<<'\n';

    while (wynik[maxi] != 1){
        cout<<liczby[maxi]<<' ';
        maxi = poprz[maxi];
    }

    cout<<liczby[maxi];

}