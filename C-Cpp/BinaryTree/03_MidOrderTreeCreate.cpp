#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct tree
{
    char data;
    tree *leftchild;
    tree *rightchild;
} * Tree;

void CreateTree(Tree &T, string Mid, string Order)
{
    if (Order.length() == 0)
    {
        T = NULL;
        return;
    }
    char root = Order[Order.length() - 1];
    int Position = Mid.find(root);

    string LeftSubStrMid = Mid.substr(0, Position);
    string RightSubStrMid = Mid.substr(Position + 1);

    int LeftLenMid = LeftSubStrMid.length();
    int RightLenMid = RightSubStrMid.length();

    string LeftSubStrOrder = Order.substr(0, LeftLenMid);
    string RightSubStrOrder = Order.substr(LeftLenMid ,RightLenMid);

    T = (Tree)malloc(sizeof(tree));
    if (T != NULL)
    {
		T->data = root;
        CreateTree(T->leftchild, LeftSubStrMid, LeftSubStrOrder);
        CreateTree(T->rightchild, RightSubStrMid, RightSubStrOrder);
    }
}

void Pre(Tree &T)
{
    if (T == NULL)
    {
        return;
    }
    cout << T->data;
    Pre(T->leftchild);
    Pre(T->rightchild);
}

int main(void)
{
    Tree T;
    string s1, s2;
    cin >> s1 >> s2;
    CreateTree(T, s1, s2);
    Pre(T);
    return 0;
}