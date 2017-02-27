#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, char delim = ',')
{

    vector<string> elems;

    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
            elems.push_back(item);
    }
    return elems;
}
int strtoint(string s)
{	
	int num = 0;
	for(int i=0;i<s.size();i++)
	{
		num = num*10;
		num += (int)s[i]-48;
	}
	return num;
}

long long int dp[101][101] = {0};
bool isBlocked[101][101] = {0};
int main() {
	// your code goes here
	int a,b;
	cin>>a>>b;

	string s;
	getline(cin,s,'}');
	
	s = s.substr(2);

	vector<string> vect = split(s,',');

	for(int i=0;i<vect.size();i++){
		string pString = vect[i];
		pString = pString.substr(1,pString.length()-2);
		vector<string> point = split(pString,' ');
		//cout<<point[0]<<" "<<point[1]<<" "<<point[2]<<" "<<point[3]<<"\n";
		int p1 = strtoint(point[0]);
		int p2 = strtoint(point[1]);
		int p3 = strtoint(point[2]);
		int p4 = strtoint(point[3]);
		isBlocked[p1][p2] = 1;
		isBlocked[p3][p4] = 1;
	}
	dp[0][0] = 1;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(isBlocked[i][j])
			{
				if(!isBlocked[i+1][j])
				{
					dp[i+1][j] += dp[i][j];
				}
				if(!isBlocked[i][j+1])
				{
					dp[i][j+1] += dp[i][j];
				}
			}
			else
			{
				dp[i+1][j] += dp[i][j];
				dp[i][j+1] += dp[i][j];
			}
		}
	}
	cout << dp[a][b] << endl;


	// string delimiter = "";

	// size_t pos = 0;
	// string token;
	// while ((pos = s.find(delimiter)) != std::string::npos) {
	//     token = s.substr(0, pos);
	//     cout << token << endl;
	//     s.erase(0, pos + delimiter.length());
	// }
	// cout << s << endl;

	return 0;
}