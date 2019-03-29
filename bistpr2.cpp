#include<iostream>
using namespace std;
class node{
public:
int data;
node*left;
node*right;
node*parent;
	node(int value){
		data=value;		
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};
class bist{
public:
node*root;
int count;
	bist(){
	root=NULL;
	count=0;
	}
	void insert(int value){
		if(root==NULL){
			root=new node(value);
			count++;
		}
		else{
			inserthelper(root,value);		
		}
	}
	void inserthelper(node*current,int value){
		if(current->data >= value){
			if(current->left==NULL){
				current->left=new node(value);
				current->left->parent=current;
				count++;
			}
			else{
				inserthelper(current->left,value);		
			}		
		}
		else{
			if(current->right==NULL){
				current->right=new node(value);
				current->right->parent=current;
				count++;
			}
			else{
				inserthelper(current->right,value);		
			}		
		}
	}
	void display(){
		displayhelper(root);
		cout<<"NULL"<<endl;
	}
	void displayhelper(node*current){
		if(current==NULL) return;
		else{
			displayhelper(current->left);
			cout<<current->data;
			cout<<"->";
			displayhelper(current->right);
		}
	}
	node*search(int value){
	return searchhelper(root,value);
	}
	node*searchhelper(node*current,int value){
		if(current==NULL or current->data==value){
			return current;
		}
		else{
			if(current->data >= value)	return searchhelper(current->left,value);
			else return searchhelper(current->right,value);	
		}
	}
	void print2d(){
		print2dhelper(root,0);
	}
	void print2dhelper(node*current,int space){
		if(current==NULL) return;
		else{
			print2dhelper(current->right,space+1);
			for(int i=0;i<space;i++){
				cout<<"  ";
			}
			cout<<current->data<<endl;
			print2dhelper(current->left,space+1);		
		}
	}
	int Count(node*current){
		if(current==NULL) return 0;
		else{
			int a=0,b=0;
			a=1+Count(current->left);
			b=Count(current->right);		
			return a+b;
		}		
	}
	node*find_min(node*current){
		if(current==NULL or current->left==NULL){
			return current;
		}
		else{
			return find_min(current->left);		
		}		
	}
	node*find_max(node*current){
		if(current==NULL or current->right==NULL){
			return current;
		}
		else{
			return find_max(current->right);		
		}		
	}
	int height(){
		int a=0;
		heighthelper(root,0,a);
		return a;
	}
	void heighthelper(node*current,int i,int &p){
		if(current ==NULL){
			if(p<i) p=i;
			else return;			
		}
		else{
			heighthelper(current->left,i+1,p);
			heighthelper(current->right,i+1,p);		
		}
			
	}
	void replace_at_parent(node*a,node*b){
		if(a->left==b)a->parent->left==b;
		else a->parent->right==b;
	}
	int rangesearch(int k1,int k2){
		int a,b,c;
		if(k1>k2){a=k1;b=k2;}
		else{a=k2;b=k1;}
		c=rangesearchhelper(b,a,root);
		cout<<"NULL"<<endl;
		cout<<"the nos of elements in between them is:- ";
		return c;	
	}
	int rangesearchhelper(int k1,int k2,node*current){
		if(current==NULL) return 0;
		else if(current->data <k1 or current->data>k2) return 0; 
		else{
			int a=0,b=0;
			a=1+rangesearchhelper(k1,k2,current->left);
			cout<<current->data;
			cout<<"->";
			b=rangesearchhelper(k1,k2,current->right);
			return a+b;		
		}	
	}	

};
int main(){
bist bst1;
    bst1.insert(4);
    bst1.insert(2);
    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(6);
    bst1.insert(5);
    bst1.insert(7);
    bst1.insert(8);
    
bst1.display();
	if(bst1.search(2) != NULL) cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;
	bst1.print2d();
cout<<"the nos of elements in the tree are :- "<<bst1.Count(bst1.root)<<endl;
cout<<"the min element of the tree is:- "<<bst1.find_min(bst1.root)->data<<endl;
cout<<"the max element of the tree is:- "<<bst1.find_max(bst1.root)->data<<endl;
cout<<"the height of the tree is :- "<<bst1.height()<<endl;
cout<<"the elements between 4 nd 8 are:- "<<bst1.rangesearch(4,8)<<endl;














}











