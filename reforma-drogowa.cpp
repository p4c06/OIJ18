#include <bits/stdc++.h>
using namespace std;

vector<int> graf[500'005];
map<pair<int, int>, int> id; 
set<pair<int, int>> np;
set<pair<int, int>> p;
int spojne[500'005];
int w[500'005];

void DFS(int wierzcholek, int spojna){
   
    spojne[wierzcholek] = spojna;
    for (int sasiad: graf[wierzcholek]){
        if (spojne[sasiad]){
            
            if (p.find({sasiad, wierzcholek}) == p.end() and np.find({sasiad, wierzcholek}) == np.end())
                np.insert({wierzcholek, sasiad});
            continue;
        }
        p.insert({wierzcholek, sasiad});
        DFS(sasiad, spojna);
    } 
}


int main(){
    int n;
    cin>>n;

    for (int i = 1; i < n; ++i){
        int pocz, kon;
        cin>>pocz>>kon;

        graf[pocz].push_back(kon);
        graf[kon].push_back(pocz);

        id[{pocz, kon}] = i;
        id[{kon, pocz}] = i;
    }
    
    int spojna = 1;
    for (int i = 1; i <= n; ++i){
        w[spojna] = i;
        
        if (spojne[i]){
            continue;
        }
        
        DFS(i, spojna);
        
        spojna++;
        
        
    }

    cout<<spojna - 2<<'\n';
    int a = 1;
    for (auto [i, j]: np){
        cout<<id[{i, j}]<<' '<<w[a]<<' '<<w[a+1]<<'\n';
        ++a;
    }
}