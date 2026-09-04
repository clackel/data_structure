#include <iostream>
using namespace std;

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &L) {
    L = new DNode;
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

/*
在p节点后插入s节点
*/
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        s->next->prior = s;
    s->prior = p;
    p->next = s;
}

/*
删除p节点的后继节点
*/
bool DeleteNextDNode(DNode *p) {
    if (p == NULL || p->next == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    delete q;
    return true;
}

int main() {
    // 初始化双链表
    DLinkList L;
    InitDLinkList(L);
}