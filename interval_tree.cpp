#include<bits/stdc++.h>
using namespace std;

struct node{
	int low, high, max_high;
	node *left;
	node *right;
	node()
	{
		low = 0;
		high = 0;
		max_high = 0;
		left = NULL;
		right = NULL;
	}
};

node* insertInterval(node *root,int l,int r)
{
    if(root==NULL)
    {
    	// node *t = new node(l,r);
        // root = t;
        node *t = new node;
        t->low = l;
        t->high = r;
        t->max_high = r;
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

node* searchInterval(node *intervals,int l,int r)
{
	if (intervals == NULL)
        return NULL;
    if (intervals->low<=r && intervals->high>=l)
        return intervals;
    if (intervals->left != NULL && (intervals->left)->max_high >= l)
        return searchInterval(intervals->left, l, r);
    return searchInterval(intervals->right, l, r);

}


void swap_intervals(node* node1, node* node2){
	node1->low=node2->low;
	node1->high=node2->high;
}
void deleteNode(node* current,node* root, node* parent, bool head){
	//head=true here indicates it is the root node
	int child=0;
	bool left=false, right=false;
	if(current->low <= parent->low) left=true;
	else right=true;

	if(current->left) child++;
	if(current->right) child++;

	if(child==0){
		if(head){
			parent=NULL;
			return;
		}
		if(left) parent->left=NULL;
		else parent->right=NULL;
	}
	else if(child==1){
		if(head){
			if(current->left) root=root->left;
			else root=root->right;
			return;
		}
		if(left){
			if(current->right) parent->left=current->right;
			else parent->left=current->left;
		}
		else{
			if(current->right) parent->right=current->right;
			else parent->right=current->left;
		}
	}
	else{
		node* temp=current;
		temp=temp->left;
		if(temp->right){
			while(temp->right){
				parent=temp;
				temp=temp->right;
			}
			swap_intervals(current, temp);
			parent->right=NULL;
		}
		else{
			swap_intervals(current, temp);
			deleteNode(temp, root,current, false);
		}
	}
}
node* deleteInterval(node* root,int l, int r)
{
	node* temp_node = new node;
	temp_node->low = l;
	temp_node->high = r;
	temp_node->max_high = r;
    node* current=new node();
    current = root;
	node *parent= new node();
	parent = root;
	while(true){
		if(current==NULL){
			cout<<"The interval you requested to delete does not exist"<<endl;
			break;
		}
		if(temp_node->low < current->low){
			parent=current; current=current->left;
		}
		else if(temp_node->low > current->low){
			parent=current; current=current->right;
		}
		else{
			deleteNode(current,root, parent, false);
			break;
		}
	}
}

int main(){
	int n;
	cin>>n;
	node *intervals = new node;
	intervals=NULL;
	for(int i=0;i<n;i++){
		int low,high;
		cin>>low>>high;
		intervals = insertInterval(intervals, low, high);
	}
	// printIntervals(intervals);
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
		else if(type==3){
			int low,high;
			cin>>low>>high;
			node *interval = searchInterval(intervals,low,high);
			if(interval==NULL)
				cout<<"Interval not found"<<"\n";
			else
				cout<<"Interval found with low = "<<interval->low<<", high = "<<interval->high<<" and max = "<<interval->max_high<<"\n";
		}
		else if(type==4){
			int low,high;
			cin>>low>>high;
			deleteInterval(intervals,low,high);
			cout<<"Interval Deleted"<<"\n";
		}
		else
			break;
	}
 return 0;
}
