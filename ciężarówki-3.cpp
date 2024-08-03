#include <bits/stdc++.h>
using namespace std;

int main(){
    string napis;
    cin>>napis;
    int k;
    cin>>k;

    vector<int> ciezarowki;
    for (int i = 0; i < napis.size(); ++i){
        if (napis[i] == 'X')
            ciezarowki.push_back(i);
    }

    double odp = 1'000'000'000;
    for (int i = 0; i < ciezarowki.size() - k + 1; ++i){
        odp = min(odp, (double)(ciezarowki[i+k - 1] - ciezarowki[i]) / 2);
    }

    cout<<odp;
}