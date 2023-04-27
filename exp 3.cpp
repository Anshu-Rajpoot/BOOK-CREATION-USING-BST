//Book Creation Using Binary Search Tree

#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
class node{
	public:
		char label[10];
		int chcount;
		node*child[10];
}*root;
class bst{
	public:
		void createtree();
		void display(node*rl);
		bst(){
			root=NULL;
		}
};
void bst:: createtree(){
	int tb,tch,i,j,k;
	root=new node();
	cout<<"enter name of the book : "<<endl;
	cin>>root->label;
	cout<<"enter no. of chapters in the book"<<endl;
	cin>>tch;
	root->chcount=tch;
	for(i=0;i<tch;i++){
		root->child[i]=new node;
		cout<<"enter chapter name"<<endl;
		cin>>root->child[i]->label;
		cout<<"enter no. of sections"<<endl;
		cin>>root->child[i]->chcount;
		for(j=0;j<root->child[i]->chcount;j++){
			root->child[i]->child[j]=new node;
			cout<<"Enter section"<<endl;
			cin>>root->child[i]->child[j]->label;
		}
	}
}
void bst::display(node*rl){
	int i,j,k,tch;
	if(rl!=NULL){
		cout<<"----BOOK HIERARCHY----"<<endl;
		cout<<"Book title"<<rl->label<<endl;
		tch=rl->chcount;
		for(i=0;i<tch;i++){
			cout<<"chapter"<<i+1<<endl;
			cout<<""<<rl->child[i]->label<<endl;
			cout<<"sections"<<endl;
			for(j=0;j<rl->child[i]->chcount;j++){
				cout<<rl->child[i]->child[j]->label<<endl;
			}
		}
	}
}
int main(){
	int ch;
	bst b;
	while(1){
		cout<<"-----------------"<<endl;
		cout<<"book creation"<<endl;
		cout<<"-----------------"<<endl;
		cout<<"1. create"<<endl;
		cout<<"2. diaplay"<<endl;
		cout<<"3. quit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				b.createtree();
			case 2:
				b.display(root);
				break;
			case 3:
				exit(1);
			default:
				cout<<"wrong choice"<<endl;
		}
	}
}
