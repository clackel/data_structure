#include <iostream>
using namespace std;

#define InitSize 10

typedef struct {
    int *data;   // Pointer to the array
    int MaxSize; // 顺序表最大容量
    int length;  // 顺序表当前长度
} SqList;

// 初始化顺序表
void InitList(SqList &L) {
    L.data = new int[InitSize];

    for (int i = 0; i < InitSize; i++) {
        L.data[i] = 0;
    }

    L.MaxSize = InitSize;
    L.length = 0;
}

// 增加动态数组的长度
void IncreaseSize(SqList &L, int len) {
    int *p = L.data;
    L.data = new int[L.MaxSize + len];

    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }

    L.MaxSize += len;
    delete[] p;
}

// 插入
bool ListInsert(SqList &L, int i, int e) {

    if (i < 1 || i > L.length + 1) {
        cout << "Invalid position!" << endl;
        return false;
    }

    if (L.length >= L.MaxSize) {
        cout << "List is full" << endl;
        return false;
    }

    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }

    L.data[i - 1] = e;
    L.length++;
    return true;
}

/*
删除表
*/
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;

    e = L.data[i - 1];

    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }

    L.length--;
    return true;
}

/*
查找表中第一个值为e的元素，返回其位置
*/
int LocateElem(SqList &L, int e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;

    return 0;
}

int main() {
    SqList L;
    InitList(L);
    cout << "Initial MaxSize: " << L.MaxSize << endl;

    for (int i = 1; i <= 5; i++)
        ListInsert(L, i, i);

    cout << LocateElem(L, 5) << endl;
    return 0;
}