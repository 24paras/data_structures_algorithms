#include <iostream>
using namespace std;

/*
 * LCA - Lowest Common Ancestor of a binary Tree
 */

class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v){
            this->val = v;
            this->left = NULL;
            this->right = NULL;
        }

        TreeNode* insertLeft(int x){
            this->left  = new TreeNode(x);
            return this->left; 
        }

        TreeNode* insertRight(int y){
            this->right = new TreeNode(y);
            return this->right;
        }

        

};

TreeNode * lca(TreeNode * root, TreeNode * p, TreeNode * q){

    if(root == NULL){
        return NULL;
    }

    if(root == p || root == q){
        return root;
    }

    TreeNode * left_lca = lca(root->left, p, q);
    TreeNode * right_lca = lca(root->right, p, q);

    if(left_lca && right_lca)
        return root;

    if(left_lca)
        return left_lca;

    else
        return right_lca;
    
}



int main(){

    TreeNode* root = new TreeNode(3);
    printf("root val is %d\n", root->val);
    TreeNode * l = root->insertLeft(5);
    TreeNode * r = root->insertRight(1);
    TreeNode * l1 = l->insertLeft(6);
    TreeNode * r1 = l->insertRight(2);
    TreeNode * l2 = r1->insertLeft(7);
    TreeNode * r2 = r1->insertRight(4);
    TreeNode * l3 = r->insertLeft(0);
    TreeNode * r3 = r->insertRight(8);
    
    TreeNode * node = root;

    printf("lca is %d\n", (lca(node, l, r2)->val));

    return 0;
}