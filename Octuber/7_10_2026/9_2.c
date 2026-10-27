
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct Node* insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void display(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += 5;
    display(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);

    display(root->left, space);
}

struct Node* largest(struct Node *root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

struct Node* smallest(struct Node *root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

/* Height of a node: number of edges on its
   longest path down to a leaf */
int height(struct Node *root) {
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight
                ? leftHeight : rightHeight);
}

struct Node* findNode(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return findNode(root->left, key);

    return findNode(root->right, key);
}

int countLeafNodes(struct Node *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left)
         + countLeafNodes(root->right);
}

int main() {
    struct Node *root = NULL;
    struct Node *temp;
    int n, data, option, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("BST Created\n");
    display(root, 0);

    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Insert\n");
        printf("2. Largest\n");
        printf("3. Smallest\n");
        printf("4. Height\n");
        printf("5. Count leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element to insert in BST: ");
                scanf("%d", &data);

                root = insert(root, data);
                display(root, 0);
                break;

            case 2:
                temp = largest(root);
                if (temp != NULL)
                    printf("Largest element in BST = %d\n",
                           temp->data);
                else
                    printf("BST is empty\n");
                break;

            case 3:
                temp = smallest(root);
                if (temp != NULL)
                    printf("Smallest element in BST = %d\n",
                           temp->data);
                else
                    printf("BST is empty\n");
                break;

            case 4:
                printf("Enter node value to find height: ");
                scanf("%d", &key);

                temp = findNode(root, key);
                if (temp != NULL)
                    printf("Height of node %d = %d\n",
                           key, height(temp));
                else
                    printf("Node not found\n");
                break;

            case 5:
                printf("Number of leaf nodes = %d\n",
                       countLeafNodes(root));
                break;

            case 6:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid option\n");
        }
    }
}
