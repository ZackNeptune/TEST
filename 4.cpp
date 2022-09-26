#include <bits/stdc++.h>

using namespace std;

bool primes(int n, bool primeStatus[]) {
	primeStatus[0] = primeStatus[1] = false;

	for (int i = 2; i <= n; i++) {
		primeStatus[i] = true;
	}

	for (int i = 2; i * i <= n; i++) {
		if (primeStatus[i] == true) {
			for (int j = i * 2; j <= n; j += i)
				primeStatus[j] = false;
		}
	}
}


int main() {
	int n,c;
	cout<<"Enter the no of test cases:";
	cin>>c;
	while(c > 0)
	{
	    cout<<"Enter the number:";
	    cin>>n;
	    bool primeStatus[n + 1], pairsFound = false;

    	primes(n, primeStatus);

    	for (int i = 2; i < n; i++) {
    		int pair = n / i;

    		if (primeStatus[i] && primeStatus[pair] && pair != i
    			&& pair * i == n) {
    			cout << i << " " << pair << endl;
    			pairsFound = true;
    			break;
    		}
    	}

	if (!pairsFound){
		cout << "No pairs";
	}
	c--;
	}

	return 0;
}
