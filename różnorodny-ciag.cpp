#include <iostream>
using namespace std;

const int MAXN = 200'000;
const int MAXA = 1'000'000;
int zlicz[MAXA];

int main(){
    int n, maxx = -1;
    long long koszt = 0; 
    cin>>n;

    for (int i = 0; i < n; ++i){
        int liczba;
        cin>>liczba;
        zlicz[liczba]++;
        maxx = max(maxx, liczba);
    }

    for (int i = maxx; i > 0; --i){
        while (zlicz[i] > 1){
            zlicz[0] = 0;
            for (int j = i; j >= 0; --j){
                if (zlicz[j] == 0 && zlicz[i] > 1){
                    zlicz[i]--;
                    zlicz[j]++;
                    koszt += i - j;
                }
            }
        }
    }

    cout<<koszt;
}