/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int matchingNodes = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0}; // {sum, count}

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int currentSum = node->val + left.first + right.first;
        int currentCount = 1 + left.second + right.second;

        if (currentSum / currentCount == node->val) {
            matchingNodes++;
        }

        return {currentSum, currentCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodes;
    }
};