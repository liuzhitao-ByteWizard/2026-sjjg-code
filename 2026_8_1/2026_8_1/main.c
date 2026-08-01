#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;

// 二叉链
typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* left;   // 指向左孩子的指针
    struct BinaryTreeNode* right;  // 指向右孩子的指针
    BTDataType data;               // 数据元素
} BTNode;

// 创建一个二叉树结点
BTNode* BuyBTNode(int val)
{
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return NULL;
    }

    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

int size = 0;
void TreeSize1(BTNode* root) {
    if (root == NULL)
        return;
    ++size;
    TreeSize1(root->left);
    TreeSize1(root->right);
}


int TreeSize(BTNode* root) {
    return root == NULL ? 0 : 
        1 + TreeSize(root->left) 
        + TreeSize(root->right);
}



// 手动构造一棵二叉树
BTNode* CreateTree()
{
    BTNode* nodea = BuyBTNode('a');
    BTNode* nodeb = BuyBTNode('b');
    BTNode* nodec = BuyBTNode('c');
    BTNode* noded = BuyBTNode('d');
    BTNode* nodee = BuyBTNode('e');
    BTNode* nodef = BuyBTNode('f');

    nodea->left = nodeb;
    nodea->right = nodec;

    nodeb->left = noded;
    nodeb->right = nodee;

    nodec->right = nodef;

    return nodea;
}

// 前序遍历：根结点 -> 左子树 -> 右子树
void Preorder(BTNode* root)
{
    // 空树是递归的终止条件
    if (root == NULL)
    {
        return;
    }

    // 先访问根结点
    printf("%c ", root->data);

    // 再递归遍历左子树
    Preorder(root->left);

    // 最后递归遍历右子树
    Preorder(root->right);
}

// 中序遍历：左子树 -> 根结点 -> 右子树
void Inorder(BTNode* root)
{
    // 空树是递归的终止条件
    if (root == NULL)
    {
        return;
    }

    // 先递归遍历左子树
    Inorder(root->left);

    // 再访问根结点
    printf("%c ", root->data);

    // 最后递归遍历右子树
    Inorder(root->right);
}

// 后序遍历：左子树 -> 右子树 -> 根结点
void Postorder(BTNode* root)
{
    // 空树是递归的终止条件
    if (root == NULL)
    {
        return;
    }

    // 先递归遍历左子树
    Postorder(root->left);

    // 再递归遍历右子树
    Postorder(root->right);

    // 最后访问根结点
    printf("%c ", root->data);
}

int main()
{
    BTNode* root = CreateTree();

    Preorder(root);
    printf("\n");

    size = 0;
    TreeSize1(root);
    printf("%d\n", size);
    size = 0;
    TreeSize1(root);
    printf("%d\n", size);
    size = 0;
    TreeSize1(root);
    printf("%d\n", size);

    return 0;
}

//// pi 指向当前写入位置，递归调用之间共享同一个下标
//void _tree2str(struct TreeNode* root, char* str, int* pi)
//{
//    // 递归终止条件：当前结点为空
//    if (root == NULL)
//        return;
//
//    // 将当前结点的整数值转换为字符串
//    char arr[10];
//    sprintf(arr, "%d", root->val);
//
//    // 将结点值追加到结果字符串，并更新写入位置
//    strcpy(str + (*pi), arr);
//    (*pi) += strlen(arr);
//
//    /*
//     * 只要存在左子树或右子树，就必须生成左子树对应的括号。
//     * 当左子树为空、右子树不为空时，需要保留空括号 ()，
//     * 以表示后面的子树属于右子树。
//     */
//    if (root->left || root->right)
//    {
//        str[(*pi)++] = '(';
//        _tree2str(root->left, str, pi);
//        str[(*pi)++] = ')';
//    }
//
//    // 只有右子树存在时，才生成右子树对应的括号
//    if (root->right)
//    {
//        str[(*pi)++] = '(';
//        _tree2str(root->right, str, pi);
//        str[(*pi)++] = ')';
//    }
//}
//
//// 将二叉树转换为符合要求的字符串
//char* tree2str(struct TreeNode* root)
//{
//    // 申请保存结果字符串的空间
//    char* str = (char*)malloc(sizeof(char) * 100000);
//
//    // i 表示下一个字符的写入位置
//    int i = 0;
//
//    // 从根结点开始递归构造字符串
//    _tree2str(root, str, &i);
//
//    // 在字符串末尾添加结束标志
//    str[i] = '\0';
//
//    return str;
//}

// 记录中序遍历过程中上一个被访问的结点
struct TreeNode* prev = NULL;

// 按照“左子树 → 根结点 → 右子树”的顺序遍历
bool _isValidBST(struct TreeNode* root)
{
    // 空树满足二叉搜索树的条件
    if (root == NULL)
        return true;

    // 先判断左子树是否为二叉搜索树
    if (_isValidBST(root->left) == false)
        return false;

    /*
     * 二叉搜索树的中序遍历结果必须严格递增。
     * 如果前一个结点值大于或等于当前结点值，
     * 说明当前树不是二叉搜索树。
     */
    if (prev != NULL && prev->val >= root->val)
        return false;

    // 当前结点将成为下一次中序遍历时的前一个结点
    prev = root;

    // 再判断右子树是否为二叉搜索树
    if (_isValidBST(root->right) == false)
        return false;

    return true;
}

bool isValidBST(struct TreeNode* root)
{
    /*
     * prev 是全局变量，可能保留上一次调用的结果。
     * 每次开始判断一棵新树之前，都必须将它重置为空。
     */
    prev = NULL;

    return _isValidBST(root);
}