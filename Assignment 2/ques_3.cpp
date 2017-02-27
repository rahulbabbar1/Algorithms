#include <bits/stdc++.h>

using namespace std;

int func(int p,int n, int a[]);

int main() {
	// your code goes here
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n,ans,maxNum;
		cin >> n;
		int a[2*n];
		for(int i= 0;i<n;i++){
			cin >> a[i];
			a[i+n] = a[i];
		}
		maxNum = 0;
		for(int i=0;i<n;i++){
			int temp = func(i,n,a);
			if(temp > maxNum)
				maxNum = temp;
		}
		cout << maxNum << endl;	
	}
	return 0;
}

int func(int p,int n, int a[]){
	int ans,dp[2*n];
	for(int i=p;i<p+n;i++)
	{
		int maxA = 0;
		for(int j=0;j<i;j++)
		{
			if(a[i] > a[j])
			{
				if(maxA < dp[j])maxA = dp[j];
			}
		}
		dp[i] = maxA+1;
	}
	ans = 0;
	for(int i=p;i<p+n;i++){
		if(ans < dp[i])
			ans = dp[i];
	}
	return ans;
}