#include <bits/stdc++.h>
using namespace std;

int MAX = 2147483647;

void printArray(int array[],int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

struct edgeClass
{   
	int start, end, value;
};

void calculateForEdge(edgeClass edge, int answer[]){
	answer[edge.end] = min( answer[edge.end], answer[edge.start] + edge.value );
}

void calculateMinPath(int n, int e, int startPoint, edgeClass edges[], int answer[]){
	for(int i=0;i<n;i++)
		answer[i] = MAX;

	answer[startPoint] = 0;

	for(int i=0;i<n-1;i++){
		for(int i=0;i<e;i++){
			calculateForEdge(edges[i],answer);
		}
	}
}

pair<int,double> calculateTime(){
	pair<int,double> nVsTime;
	clock_t begin = clock();	

	int n,e,startPoint;

	//cout<<"Enter no. of vertices, edges and start vertix index (Use 0 based indexing for vertices)"<<"\n";

	cin>>n>>e>>startPoint;

	edgeClass edges[e];

	//cout<<"Enter start vertix, end vertix, cost for each of the "<<e<<" edges."<<"\n";

	for(int i=0;i<e;i++){
		edges[i].start = rand() % n;
		edges[i].end = rand() % n;
		edges[i].value = rand() % 100;
	}

	int answer[n];

	calculateMinPath(n, e, startPoint, edges, answer);

	clock_t end = clock();

	nVsTime.first = n;
	nVsTime.second =  double(end - begin)*1000/CLOCKS_PER_SEC;

	return nVsTime;
	//cout<<"Minimum Path for each vertix:"<<"\n";
	//printArray(answer,n);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	pair<int,double> nVsTime[t]; 
	for(int i=0;i<t;i++){
		nVsTime[i] = calculateTime();
	}

	for(int i=0;i<t;i++){
		cout << nVsTime[i].first << " " << nVsTime[i].second << " milliSeconds \n";
	}

	return 0;
}


