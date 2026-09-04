#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

LNode *GetElem(LinkList L, int i);

/*
初始化单链表
*/
bool InitList(LinkList &L) {
    L = new LNode;
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

/*
判断是否为空
*/
bool Empty(LinkList L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}

/*
在p节点后插入元素e
*/
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL)
        return false;

    LNode *s = new LNode;

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/*
在p节点之前插入元素e
*/
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL)
        return false;

    LNode *s = new LNode;
    s->data = p->data;
    s->next = p->next;
    p->next = s;
    p->data = e;
    return true;
}

/*
在第i个位置插入元素e
*/
bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1)
        return false;

    LNode *p = GetElem(L, i - 1);
    InsertNextNode(p, e);

    return InsertNextNode(p, e);
}

/*
删除第i个节点
*/
bool ListDelete(LinkList &L, int i, int &e) {
    if (i < 1)
        return false;

    LNode *p = GetElem(L, i - 1);

    if (p == NULL || p->next == NULL)
        return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}

/*
删除指定节点
*/
bool DeleteNode(LNode *p) {
    if (p == NULL)
        return false;

    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    delete q;
    return true;
}

/*
按位查找
*/
LNode *GetElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/*
按值查找
*/
LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

/*
求表长
*/
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

int main() {
    LinkList L;
    InitList(L);

    return 0;
}