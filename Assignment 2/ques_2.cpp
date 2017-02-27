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

int main() {
	// your code goes here
	int a,b;
	cin>>a>>b;

	string s;
	getline(cin,s,'}');
	
	s = s.substr(2);
	//remove '{' from string

	vector<string> vect = split(s,',');

	cout<<vect[0];

	

	// string delimiter = "";

	// size_t pos = 0;
	// string token;
	// while ((pos = s.find(delimiter)) != std::string::npos) {
	//     token = s.substr(0, pos);
	//     cout << token << endl;
	//     s.erase(0, pos + delimiter.length());
	// }
	// cout << s << endl;



}