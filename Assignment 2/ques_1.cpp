#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		//take input value of n
		int n;
		cin >> n;

		int a[n];
		int maxHigher[n];
		int maxLower[n];
		int higher, lower;

		for(int i=0;i<n;i++){
			cin >> a[i];
		}

		maxHigher[0] = 1;
		maxLower[0] = 1;
		
		for(int i=1;i<n;i++){
			higher =0,lower=0;
			for(int j=0;j<i;j++){
				if(a[j] < a[i])
					if(maxLower[j] > lower)
						lower = maxLower[j];
				if(a[j] > a[i])
					if(maxHigher[j] > higher)
						higher = maxHigher[j];
			}
			maxHigher[i] = lower+1;
			maxLower[i] = higher +1 ;
		}

		int maxFinal = 0;
		for(int i=0;i<n;i++){
			if(maxHigher[i] > maxFinal)
				maxFinal= maxHigher[i];
			if(maxLower[i] > maxFinal)
				maxFinal = maxLower[i];
		}
		cout << maxFinal << endl;
	}
	return 0;
}