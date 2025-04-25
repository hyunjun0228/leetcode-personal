#include <vector>
#include <iostream>
#include <stack>
#include "../DataStructures/TreeNode.h"

using namespace std;

/*
To perform an inorder traversal of a binary tree using a stack (iterative approach), you follow the
Left -> Root -> Right order.

Steps:
1. Initialize an empty stack.
2. Start from the root and go as left as possible, pushing each node onto the stack.
3. When you reach a null left child, pop the top node from the stack, process it, and move to its right child.
4. Repeat steps 2-3 until the stack is empty and all nodes are visited.
*/

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *current = root;

    while (current != nullptr || !st.empty())
    {
        while (current)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = inorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}