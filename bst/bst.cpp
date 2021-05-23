#include <iostream>
using namespace std;

class BST()
{
    int data;
    BST *left, *right;

    public:
    // default constructor
    BST(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }

    void inOrder(*BST);
};

BST* BST::Insert(BST* root, int x)
{
    if(!root)
    {
        
    }
}

int main()
{

}
