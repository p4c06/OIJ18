#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	string n; int k, odp = 0;
	cin>>n>>k;
	sort(n.begin(), n.end());

	do {
		
		odp += !(bool)(stoll(n)%k);
	} while (next_permutation(n.begin(),n.end()));

	cout<<odp;
   
}