#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

	srand(time(0));
	ll t=1;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=0;i<n;i++){
			cout<<rand()%2;
		}
		cout<<endl;
	}
}