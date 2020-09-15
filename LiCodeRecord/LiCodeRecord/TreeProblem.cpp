#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*（104）二叉树的最大深度

//全局变量递归
int MaxDepth;
void Helper(TreeNode* root, int depth)
{
    MaxDepth = (MaxDepth > depth) ? MaxDepth : depth;

    if (root->left)
        Helper(root->left, depth + 1);
    if (root->right)
        Helper(root->right, depth + 1);
}

//左右子树递归
int Helper2(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    int left = Helper2(root->left);
    int right = Helper2(root->right);

    return (left > right) ? left + 1 : right + 1;
}

int maxDepth(TreeNode* root) {
    //MaxDepth = 0;
    //if (root)
    //    Helper(root, MaxDepth + 1);

    //return MaxDepth;
    return Helper2(root);
}
*/

/*(94)二叉树的中序遍历

//栈的迭代算法
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* node = root;

    while (node!=nullptr || !s.empty())
    {
        //最左节点
        while (node!=nullptr)
        {
            s.push(node);
            node = node->left;
        }
        //回溯
        node = s.top();
        s.pop();
        //加入Res
        res.push_back(node->val);
        //当前节点右子树
        node = node->right;
    }

    return res;
}
*/

/*（101）对称二叉树
//递归法
bool Helper(TreeNode* left, TreeNode* right)
{
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr && right != nullptr)
        return false;
    if (left != nullptr && right == nullptr)
        return false;
    if (left->val != right->val)
        return false;

    return Helper(left->left, right->right) && Helper(left->right, right->left);
}
//迭代法
bool Helper2(TreeNode* root)
{
    deque<TreeNode*> que;
    que.push_back(root->left);
    que.push_back(root->right);

    while (!que.empty())
    {
        TreeNode* front = que.front();
        TreeNode* back = que.back();

        if (front == nullptr && back == nullptr)
            continue;
        if (front == nullptr && back != nullptr)
            return false;
        if (front != nullptr && back == nullptr)
            return false;
        if (front->val != back->val)
            return false;

        que.push_front(front->right);
        que.push_back(back->left);
        que.push_front(front->left);
        que.push_back(back->right);
    }

    return true;
}

bool isSymmetric(TreeNode* root) {
    if (root)
    {
        return Helper(root->left, root->right);
        //return Helper2(root);
    }
    return true;
}
*/

/*(108)将有序数组转换为二叉搜索树

TreeNode* Helper(vector<int>& nums, int star, int end)
{
    if (star > end)
        return nullptr;

    int mid = (star + end) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = Helper(nums, star, mid - 1);
    node->right = Helper(nums, mid + 1, end);

    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return Helper(nums, 0, nums.size() - 1);
}
*/

/*(236)二叉树的最近公共祖先

TreeNode* Helper(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr)
        return nullptr;
    TreeNode* left = Helper(root->left, p, q);
    TreeNode* right = Helper(root->right, p, q);

    if (root->val == p->val || root->val == q->val)
        return root;
    if (left != nullptr && right != nullptr)
        return root;
    if (left == nullptr && right != nullptr)
        return right;
    if (left != nullptr && right == nullptr)
        return left;
    if (left == nullptr && right == nullptr)
        return nullptr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return Helper(root, p, q);
}
*/

/*(103)二叉树的锯齿形层次遍历

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    int count = 1;
    bool flag = true;
    vector<vector<int>> res;
    deque<TreeNode*> que;
    que.push_back(root);
    while (!que.empty())
    {
        deque<int> q;
        vector<int> v;
        int num = 0;
        for (int i = 0;i < count&&!que.empty();++i)
        {
            TreeNode* node = que.front();
            que.pop_front();

            if (node != nullptr)
            {
                if (flag)
                    q.push_back(node->val);
                else
                    q.push_front(node->val);

                que.push_back(node->left);
                que.push_back(node->right);
                num += 2;
            }
        }
        while (!q.empty())
        {
            v.push_back(q.front());
            q.pop_front();
        }
        if (!v.empty())
            res.push_back(v);
        count = num;
        flag = !flag;
    }

    return res;
}
*/

/*(230)二叉搜索树中第K小的元素

//递归法
int n = 0;
int res;
bool flag = false;
void Helper(TreeNode* root, int k)
{
    if (flag)
        return;

    if (root->left)
        Helper(root->left, k);
    
    n++;
    if (n == k)
    {
        res = root->val;
        flag = true;
    }

    if (root->right)
        Helper(root->right, k);
}

//迭代法（栈）
int Helper2(TreeNode* root, int k)
{
    stack<TreeNode*> s;

    while (true)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();

        if (--k == 0)
            return root->val;
        root = root->right;
    }
}

int kthSmallest(TreeNode* root, int k) {
    Helper(root, k);

    return res;
}
*/

#pragma region 二叉搜索树（BST）

/*96. 不同的二叉搜索树

int Helper(int n, vector<int>& dp)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = 0, right = 0;

        if (dp[i - 1] == -1)
            dp[i - 1] = Helper(i - 1, dp);
        if (dp[n - i] == -1)
            dp[n - i] = Helper(n - i, dp);

        left = dp[i - 1];
        right = dp[n - i];

        res += left * right;
    }
    return res;
}

int numTrees(int n) {
    if (n < 2)
        return 1;
    if (n == 2)
        return 2;

    vector<int> dp(n, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    return Helper(n, dp);
}
*/

/*95. 不同的二叉搜索树 II

//递归法
vector<TreeNode*> Helper(int l, int r)
{
    vector<TreeNode*> res;
    if (l > r)
        return {nullptr};

    for (int i = l; i <= r; i++)
    {
        vector<TreeNode*> left = Helper(l, i - 1);
        vector<TreeNode*> right = Helper(i + 1, r);

        for (TreeNode* lnode : left)
        {
            for (TreeNode* rnode : right)
            {
                TreeNode* node = new TreeNode(i);
                node->left = lnode;
                node->right = rnode;

                res.push_back(node);
            }
        }
    }

    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n <= 0)
        return vector<TreeNode*>();

    return Helper(1, n);
}
*/

#pragma endregion

