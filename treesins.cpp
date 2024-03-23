#include <stdio.h>
#include <stdlib.h>

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
private:
    TreeNode *root;

public:
    BinaryTree() {
        root = NULL;
    }

    TreeNode* getRoot() {
        return root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    TreeNode* insert(TreeNode *node, int value) {
        if (node == NULL) {
            node = new TreeNode(value);
        } else {
            if (value < node->data) {
                node->left = insert(node->left, value);
            } else {
                node->right = insert(node->right, value);
            }
        }
        return node;
    }

    void inorderTraversal(TreeNode *node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            printf("%d ", node->data);
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(TreeNode *node) {
        if (node != NULL) {
            printf("%d ", node->data);
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode *node) {
        if (node != NULL) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            printf("%d ", node->data);
        }
    }
};

int main() {
    BinaryTree tree;

    int choice, value;

    do {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                tree.insert(value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                tree.inorderTraversal(tree.getRoot());
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                tree.preorderTraversal(tree.getRoot());
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                tree.postorderTraversal(tree.getRoot());
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
