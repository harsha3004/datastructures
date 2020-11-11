#include <iostream>   

using namespace std;   

struct node{   

    int data;   

    struct node *left;   

    struct node *right;   

};   

struct node *newnode(int key){   

    struct node *Node=new node;   

    Node->data=key;   

    Node->left=Node->right=NULL;   

    return Node;   

}   

struct node *insert(struct node *root,int key){   

    if(root==NULL)   

        return newnode(key);   

    if(key<root->data)   

        root->left=insert(root->left,key);   

    else   

        root->right=insert(root->right,key);   

    return root;   

}   

int minValue(struct node *root){   

    struct node *current=root;   

    while(current->left!=NULL){   

        current=current->left;   

    }   

    return current->data;   

}   

int maxValue(struct node *root){   

    struct node *current=root;   

    while(current->right!=NULL){   

        current=current->right;   

    }   

    return current->data;   

}   

struct node *search(struct node *root,int key){   

    if(root==NULL) return NULL;  

    else if(root->data==key) return root;  

    else if(root->data<key) return search(root->right,key);  

    else return search(root->left,key);  

}   

  

void predecessor(struct node *root,struct node *&pred,struct node *&succ,int key){  

    if(root==NULL) return;  

    if(root->data==key){  

        if(root->left!=NULL){  

            struct node *temp=root->left;  

            while(temp->right){  

                temp=temp->right;  

            }  

            pred=temp;  

        }  

        return;  

    }  

  

    if(root->data<key){  

        pred=root;  

        predecessor(root->right,pred,succ,key);  

    }  

    else{  

        succ=root;  

        predecessor(root->left,pred,succ,key);  

    }  

}  

void successor(struct node *root,struct node *&pred,struct node *&succ,int key){  

    if(root==NULL) return;  

    if(root->data==key){  

        if(root->right!=NULL){  

            struct node *temp=root->right;  

            while(temp->left){  

                temp=temp->left;  

            }  

            succ=temp;  

        }  

        return;  

    }  

    if(root->data>key){  

        succ=root;  

        successor(root->left,pred,succ,key);  

    }  

    else{  

        pred=root;  

        successor(root->right,pred,succ,key);  

    }  

}  

struct node *deletenode(struct node *root,int key){ 

    if(root==NULL) 

        return root; 

    if(key<root->data) 

        root->left=deletenode(root->left,key); 

    else if(key>root->data) 

        root->right=deletenode(root->right,key); 

    else{ 

        if (root->left == NULL){ 

            struct node *temp = root->right; 

            free(root); 

            return temp; 

        } 

        else if (root->right == NULL){ 

            struct node *temp = root->left; 

            free(root); 

            return temp; 

        } 

        struct node* temp = minValue(root->right); 

        root->data = temp->data; 

        root->right = deletenode(root->right, temp->data); 

    } 

    return root; 

} 

int main(){   

    struct node *root=NULL;   

    int s;   

    root=insert(root,37);   

    insert(root,25);   

    insert(root,59);   

    insert(root,39);   

    insert(root,11);   

    insert(root,100);   

    insert(root,53);   

    insert(root,27);   

    root=deletenode(root,53); 

    int min=minValue(root);   

    cout<<"Minimum value in the tree is: "<<min<<"\n";   

    int max=maxValue(root);   

    cout<<"Maximum value in the tree is: "<<max<<"\n";   

    int Number=11;  

    struct node *Search=search(root,Number);  

    if(Search==NULL){  

        cout<<Number<<" not found\n";  

    }  

    else  

        cout<<Number<<" is found\n";  

    int number=13;  

    struct node *pre=NULL;  

    struct node *suc=NULL;  

    predecessor(root,pre,suc,number);  

    successor(root,pre,suc,number);  

    if(pre!=NULL)  

        cout<<"Predecessor is "<<pre->data<<"\n";  

    else  

        cout<<"No predecessor\n";  

    if(suc!=NULL)  

        cout<<"Successor is "<<suc->data<<"\n";  

    else  

        cout<<"No successor\n";  

    return 0;  

} 
