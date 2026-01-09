/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* lowestCommonAncestor = nullptr;

    void findLCA(TreeNode* currentNode) {
        if (!currentNode->left && !currentNode->right) {
            lowestCommonAncestor = currentNode;
            return;
        }

        int leftDepth = calculateDepth(currentNode->left);
        int rightDepth = calculateDepth(currentNode->right);

        if (leftDepth == rightDepth) {
            lowestCommonAncestor = currentNode;
        } else if (leftDepth < rightDepth) {
            findLCA(currentNode->right);
        } else {
            findLCA(currentNode->left);
        }
    }
    int calculateDepth(TreeNode* node) {
        if (!node)
            return 0;
        return 1 + max(calculateDepth(node->left), calculateDepth(node->right));
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
            return root;

        findLCA(root);
        return lowestCommonAncestor;
    }
};
