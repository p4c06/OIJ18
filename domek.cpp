#include <iostream>
using namespace std;

string domek[1000];

int main(){
    int n, m;
    cin>>n>>m;

    for (int i = 0; i < n; ++i){
        cin>>domek[i];
    }
    
    for (int j = 0; j < m; ++j){
        int gwiazdki = 0;

        for (int i = 0; i < n; ++i){
            if (domek[i][j] == '*'){
                domek[i][j] = '.';
                gwiazdki++;
            }
            if (domek[i][j] == '#'){                
                for (int k = 1; k <= gwiazdki; k++){                    
                    domek[i - k][j] = '*';
                }
                gwiazdki = 0;
            }

        }

        for (int k = 1; k <= gwiazdki; k++){                    
            domek[n - k][j] = '*';
        }
    }

    for (int i = 0; i < n; ++i){
        cout<<domek[i]<<endl;
    }    

}