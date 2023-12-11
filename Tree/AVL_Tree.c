#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* lchild;
    int data;
    int height;
    struct Node* rchild;
} Node;

Node* root;

int NodeHeight(Node* p)
{
    int hl, hr;

    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(Node* p)
{
    int hl, hr;

    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

Node* LLRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    pl->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if (p == root)
        root = pl;

    return pl;
}

Node* LRRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

Node* RRRotation(Node* p) { return NULL; }
Node* RLRotation(Node* p) { return NULL; }
Node* RInsert(Node* p, int key)
{
    Node* t;

    if (p == NULL) {
        t = (Node*)malloc(sizeof(Node));
        t->data = key;
        t->height = 1;  // height start 1
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    /* LL rotation */
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    /* LR rotation */
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RLRotation(p);

    return p;
}

int main(int argc, char* argv[])
{
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 2);


    return 0;
}
