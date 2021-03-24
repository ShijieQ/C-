class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool all = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *now = q.front();
                q.pop();
                if (now) {
                    if (!all) {
                        return false;
                    }
                    q.push(now->left);
                    q.push(now->right);
                }
                else {
                    all = false;
                }
            }
        }
        return true;
    }
};