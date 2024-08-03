#include <bits/stdc++.h>
using namespace std;

vector<long long> fib;

int main(){
    long long n;
    cin>>n;

    fib.push_back(0);
    fib.push_back(2);
    fib.push_back(3);
    
   
    for (int i = 3; fib.back() > 0; ++i){        
        fib.push_back(fib[i-1] + fib[i-2]);                
        
    }
    fib.pop_back();
    string odp = "a";
    
    for (int i = fib.size() - 1; i > 0; --i){
        long long test = fib[i];
        if (fib[i] > n || n == 1)
            continue;
        if (!(n % fib[i])){
            for (int j = 0; j < i; ++j){
                odp += "+";
            }
            odp += "a";
            n /= fib[i];
            i++;
        }
        if (odp.size() > 100000){
            break;
        }

    }
    if (n == 1  and odp.size() <= 100000)
        cout<<odp;
    else 
        cout<<"NIE";
    
    
}