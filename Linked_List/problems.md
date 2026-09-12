## 反转链表

新建链表法

```c++
ListNode *curr = nullptr;
while (head != nullptr){
    curr = new ListNo(head->val, curr);
    head = head->next;
}
return curr;
```

原地反转：`pre`记录已反转的链表的头节点,`nextnode`记录下一个需要反转的节点。

```c++
ListNode *pre = nullptr;
    while (head != nullptr){
        ListNode *next_node =head->next;
        head->next = pre;
        // 移动指针
        pre = head;
        head = next_node;
    }
return pre;
```

## 合并两个有序链表

虚拟头节点`dummy`，尾节点`curr`
当头节点不确定或有被删除的风险时使用虚拟头节点

```c++
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    while (list1 != nullptr && list2 != nullptr){
        if (list1->val < list2->val){
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
        }
        else{
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
        }
    }
    // 合并剩余节点
    curr->next = list1 == nullptr ? list2 : list1;
    return dummy->next;
}
```

## 环形链表

### 判断链表是否有环

快慢指针：`fast`指针移动两步，`slow`指针移动一步。
类比操场跑圈，跑的快的必定会套圈。

```c++
bool hasCycle(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;
    // fast 的下一个节点为空时就需要跳出循环
    // 否则访问 fast->next->next 会报错
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
```

### 找出入环的第一个节点

哈希表解法：存入走过的节点，第一个重复的节点即为入口

```c++
ListNode *detectCycle(ListNode *head){
    unordered_set<ListNode *> hs;
    ListNode *curr = head;
    while (curr != nullptr){
        if (hs.count(curr))
            return curr;
        hs.insert(curr);
        curr = curr->next;
    }
    return nullptr;
}
```

空间复杂度O(1)解法：
to be continued
