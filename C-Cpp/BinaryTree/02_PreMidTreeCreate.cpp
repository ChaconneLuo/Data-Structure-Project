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

void CreateTree(Tree &T, string Pre, string Mid)
{
    if (Pre.length() == 0)
    {
        T = NULL;
        return;
    }
    char root = Pre[0];
    int Position = Mid.find(root);
    string LeftSubStrMid = Mid.substr(0, Position);
    string RightSubStrMid = Mid.substr(Position + 1);

    int LeftLenMid = LeftSubStrMid.length();
    int RightLenMid = RightSubStrMid.length();

    string LeftSubStrPre = Pre.substr(1, LeftLenMid);
    string RightSubStrPre = Pre.substr(LeftLenMid + 1);
    T = (Tree)malloc(sizeof(tree));
    if (T != NULL)
    {
        T->data = root;
        CreateTree(T->leftchild, LeftSubStrPre, LeftSubStrMid);
        CreateTree(T->rightchild, RightSubStrPre, RightSubStrMid);
    }
}

void Order(Tree &T)
{
    if (T == NULL)
    {
        return;
    }
    Order(T->leftchild);
    Order(T->rightchild);
    cout << T->data;
}

int main(void)
{
    Tree T;
    string s1, s2;
    cin >> s1 >> s2;
    CreateTree(T, s1, s2);
    Order(T);
    return 0;
}