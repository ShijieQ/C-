#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;
const int mod = 1e9+7;
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
int main(){
    
    return 0;
}