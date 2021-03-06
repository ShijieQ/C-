#include <cstdio>
#include <iostream>
#include <algorithm>

#define WTF(op)     233 op 466
using namespace std;
const int INF = 0x3f3f3f3f;
typedef char ElemType;

typedef struct BinaryTreeNode{
    ElemType Data;
    struct BinaryTreeNode *lchild, *rchild;
} BinaryTreeNode/*, *Binarytree*/;

BinaryTreeNode *PreCreateTree(BinaryTreeNode *&node){
    char ch;
    ch = getchar();
    if(ch == '#'){
        node = NULL;
    }
    else{
        node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        node->Data = ch;
        node->lchild = PreCreateTree(node->lchild);
        node->rchild = PreCreateTree(node->rchild);
    }
    return node;
}

void preOrderTransverse(BinaryTreeNode *node){
    if(node == NULL){
        return ;
    }
    cout<<node->Data<<" ";
    preOrderTransverse(node->lchild);
    preOrderTransverse(node->rchild);
}

void midOrderTransverse(BinaryTreeNode *node){
    if(node == NULL){
        return ;
    }
    midOrderTransverse(node->lchild);
    cout<<node->Data<<" ";
    midOrderTransverse(node->rchild);
}

void postOrderTransverse(BinaryTreeNode *node){
    if(node == NULL){
        return ;
    }
    postOrderTransverse(node->lchild);
    postOrderTransverse(node->rchild);
    cout<<node->Data<<" ";
}

int gethigh(BinaryTreeNode *node){
    int l = 0, r = 0, cnt = 1;
    if(node == NULL){
        cnt = 0;
    }
    else{
        l = gethigh(node->lchild);
        r = gethigh(node->rchild);
        cnt += l>r ? l:r;
    }
    return cnt;
}

void getnodeNum(BinaryTreeNode *node, int &ans){
    if(node == NULL){
        return ;
    }
    ans++;
    getnodeNum(node->lchild, ans);
    getnodeNum(node->rchild, ans);
}

void swapChild(BinaryTreeNode *&node){
    if(node == NULL){
        return ;
    }
    BinaryTreeNode *tem;
    tem = node->lchild;
    node->lchild = node->rchild;
    node->rchild = tem;
    swapChild(node->lchild);
    swapChild(node->rchild);
}

int cal(BinaryTreeNode *t)
{
    return (t == NULL) ? 0 : (cal(t->lchild)+cal(t->rchild) + (t->lchild == NULL)^(t->rchild == NULL));
}
int main(){
    cout << WTF(+);
    BinaryTreeNode *tree;
    // Init(&node);
    PreCreateTree(tree);
    cout<<"PreOrderTransverse :";
    preOrderTransverse(tree);
    cout<<endl;
    int heigh = gethigh(tree);
    int Nodenum = 0;
    getnodeNum(tree, Nodenum);
    cout<<"heigh = "<<heigh<<endl;
    cout<<"Nodenum = "<<Nodenum<<endl;
    swapChild(tree);
    cout<<"After swap: ";
    preOrderTransverse(tree);
    cout<<endl;
    cout<<"MidOrderTransverse :";
    midOrderTransverse(tree);
    cout<<endl;
    cout<<"PostOrderTransverse :";
    postOrderTransverse(tree);
    cout<<endl;
    return 0;
}
// ABEH###C#D##MN###