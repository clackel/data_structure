## 思想

### 后序遍历

大多数二叉树题目都是左右中的递归顺序，在拿到左子树和右子树的信息之后判断当前节点是否满足条件。

### 前序遍历

前序遍历在自上而下传递信息的题目中常见

剪枝策略的核心递归顺序是中左右，对当前节点判断后确实是否剪枝来过滤不必要的判断。

---

例如`搜索二叉树`，拿到最小和最大限制之后进行判断，不满足要求就直接返回false。

```c++
/*
@TreeNode *root
@long long min_limit
@long long max_limit
*/
if (root == nullptr)
        return true;
    bool left = dfs(root->left, min_limit,root->val);
    bool right = dfs(root->right, root->val,max_limit);
    if (left && right && root->val >min_limit && root->val < max_limit)
        return true;
    return false;
```
