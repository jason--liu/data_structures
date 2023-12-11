#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

Node *root;

void Insert(int key)
{
    Node* t = root;
    Node *r, *p;

    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->data = key;
        root->lchild = root->rchild = NULL;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (Node*)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void Inorder(Node* p)
{
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

Node* Search(int key)
{
    Node* t = root;

    while (t) {
        if (t->data == key)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }

    return NULL;
}

Node* RInsert(Node* p, int key)
{
    Node* t;

    if (p == NULL) {
        t = (Node*)malloc(sizeof(Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    return p;
}

int Height(Node* p)
{
    int x, y;

    if (p == NULL)
        return 0;

    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node* InPre(Node* p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

struct Node* InSucc(Node* p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}
Node* Delete(Node* p, int key)
{
    Node *q;

    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    return p;
}

int main(int argc, char* argv[])
{
    /* Insert(10); */
    /* Insert(5); */
    /* Insert(20); */
    /* Insert(8); */
    /* Insert(30); */
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);

    Delete(root, 10);
    Inorder(root);
    printf("\n");
    return 0;
}

