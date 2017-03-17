#include <bits/stdc++.h>
using namespace std;

int MAX = 1000000000;

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

int main() {
	// your code goes here
	int n,e,startPoint;

	cout<<"Enter no. of vertices, edges and start vertix index (Use 0 based indexing for vertices)"<<"\n";

	cin>>n>>e>>startPoint;

	edgeClass edges[e];

	cout<<"Enter start vertix, end vertix, cost for each of the "<<e<<" edges."<<"\n";

	for(int i=0;i<e;i++){
		cin >> edges[i].start >> edges[i].end >> edges[i].value; 
	}

	int answer[n];

	calculateMinPath(n, e, startPoint, edges, answer);

	cout<<"Minimum Path for each vertix:"<<"\n";
	printArray(answer,n);

	return 0;
}
