#include<bits/stdc++.h>
using namespace std;

struct node{
	int low, high, max_high;
	node *left;
	node *right;
	node(int l, int r)
	{
		low = l;
		high = r;
		max_high = r;
		left = NULL;
		right = NULL;
	}
};

node* insertInterval(node *root,int l,int r)
{
    if(root==NULL)
    {
    	node *t = new node(l,r);
        root = t;
    }
    else if(l > root->low )
    {
        root->max_high = max(root->high,r);
        root->right = insertInterval(root->right,l,r);
    }
    else
    {
        root->max_high = max(root->high,r);
        root->left = insertInterval(root->left,l,r);
    }
    return root;
}

void printIntervals(node *intervals)
{
    if (intervals == NULL) return;

    printIntervals(intervals->left);
    cout<<intervals->low<<" "<<intervals->high<<" "<< intervals->max_high << endl;
    printIntervals(intervals->right);
}


int main(){
	int n;
	cin>>n;
	node *intervals;
	for(int i=0;i<n;i++){
		int low,high;
		cin>>low>>high;
		intervals = insertInterval(intervals, low, high);
	}
	
	while(true){
		cout<<"Press 1 to print, 2 to insert, 3 to search, 4 to delete, 5 to exit "<<"\n";
		int type;
		cin>>type;
		if(type == 1){
			printIntervals(intervals);
		}
		else if(type == 2){
			int low,high;
			cin>>low>>high;
			insertInterval(intervals,low,high);
		}
		else
			break;
	}
 return 0;
}
