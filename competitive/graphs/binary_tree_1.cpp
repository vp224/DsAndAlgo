#include<bits/stdc++.h>
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef struct _node {
    struct _node *left;
    struct _node *right;
    int data;
}node;

void solve(node* root, bool &flag) {
    if(root==NULL || root->left == NULL && root->right == NULL ) {
        flag=1;
        return;
    }
    else {
        int l=0;
        if(root->left!=NULL) {
            l=root->left->data;
        }
        int r=0;
        if(root->right!=NULL) {
            r=root->right->data;
        }
        if(root->data == l+r) {
            if(root->left!=NULL) {
                int temp = (root->left->data);
                solve(root->left,flag);
            }
            if(root->right!=NULL) {
                int temp1 = (root->right->data);
                solve(root->right,flag);
            }
        }
        else {
            flag=0;
            return;
        }
    }
}
node* getNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main() {

    jaldi

    node* root;
    root = getNode(10);
    root->left = getNode(8);
    root->right = getNode(2);
    root->left->left = getNode(3);
    root->left->right = getNode(5);
    root->right->left = getNode(2);
    bool flag = true;
    solve(root,flag);
    cout<<flag<<'\n';

}
