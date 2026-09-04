#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

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

int main() {
    LinkList L;
    InitList(L);

    return 0;
}