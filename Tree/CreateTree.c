#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

struct Stack {
    int size;
    int top;
    struct Node **S;
};

struct Queue {
    int size;
    int front;
    int rear;
    Node** Q;
};

void Stackcreate(struct Stack* st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node**)malloc(st->size * sizeof(struct Node*));
}

void push(struct Stack* st, struct Node* x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node* pop(struct Stack* st)
{
    struct Node* x = NULL;

    if (st->top == -1)
        printf("Stack Underflow\n");
    else {
        x = st->S[st->top--];
    }

    return x;
}

int isEmptyStack(struct Stack st)
{
    if(st.top==-1)
        return 1;

    return 0;
}

int isFullStack(struct Stack st) { return st.top == st.size - 1; }

void IPreorder(struct Node* p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while (p || !isEmptyStack(stk)) {
        if (p) {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IIreorder(struct Node* p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while (p || !isEmptyStack(stk)) {
        if (p) {
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
void create(struct Queue* q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node**)malloc(q->size * sizeof(Node*));
}

void enqueue(struct Queue* q, Node* x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node* dequeue(struct Queue* q)
{
    Node* x = NULL;

    if (q->front == q->rear) {
        printf("Queue is Empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

int isEmpty(struct Queue q) { return q.front == q.rear; }

struct Node* root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("enter root value");
    scanf("%d", &x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;

    enqueue(&q, root);
    while (!isEmpty(q)) {
        p = dequeue(&q);
        printf("enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node* p)
{
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node* p)
{
    if (p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void posorder(struct Node* p)
{
    if (p) {
        posorder(p->lchild);
        posorder(p->rchild);
        printf("%d ", p->data);
    }
}

void LevelOrder(struct Node* root)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmpty(q)) {
        root = dequeue(&q);
        if (root->lchild) {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild) {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int countNode(struct Node* root)
{
    if (root)
        return countNode(root->lchild) + countNode(root->rchild) + 1;
    return 0;
}

int treeHigh(struct Node* root)
{
    int x = 0, y = 0;

    if (!root)
        return 0;
    x = treeHigh(root->lchild);
    y = treeHigh(root->rchild);

    if (x > y)
        return x + 1;
    return y + 1;
}
int main(int argc, char* argv[])
{

    Treecreate();
    preorder(root);
    printf("\n");

    IPreorder(root);
    printf("\n");

    IIreorder(root);
    printf("\n");

    LevelOrder(root);
    printf("\n");
    return 0;
}
