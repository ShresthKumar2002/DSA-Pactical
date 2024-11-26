#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int value) : data(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Class for Red-Black Tree
class RedBlackTree {
private:
    Node* root;

    Node* bstInsert(Node* root, Node* node) {
    // Perform the normal BST insert
    if (root == nullptr) {
        return node;
    }

    if (node->data < root->data) {
        root->left = bstInsert(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        root->right = bstInsert(root->right, node);
        root->right->parent = root;
    }

    return root;
    }

    Node* bstDelete(Node* root, int data) {
    if (root == nullptr) return root;

    if (data < root->data) {
        root->left = bstDelete(root->left, data);
    } else if (data > root->data) {
        root->right = bstDelete(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                // No child case
                temp = root;
                root = nullptr;
            } else {
                // One child case
                *root = *temp;
            }
            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = bstDelete(root->right, temp->data);
        }
    }

    return root;
}

// Helper function to find the minimum value node in a given subtree
Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}
    void rotateLeft(Node*& node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;

        if (node->right != nullptr)
            node->right->parent = node;

        rightChild->parent = node->parent;

        if (node->parent == nullptr)
            root = rightChild;
        else if (node == node->parent->left)
            node->parent->left = rightChild;
        else
            node->parent->right = rightChild;

        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node*& node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;

        if (node->left != nullptr)
            node->left->parent = node;

        leftChild->parent = node->parent;

        if (node->parent == nullptr)
            root = leftChild;
        else if (node == node->parent->left)
            node->parent->left = leftChild;
        else
            node->parent->right = leftChild;

        leftChild->right = node;
        node->parent = leftChild;
    }

    // Balances the tree after insertion of a node
    void balanceInsert(Node*& node) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;

            // Case A: Parent of node is left child of Grand-parent of node
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: The uncle of node is also red
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2: node is right child of its parent
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    // Case 3: node is left child of its parent
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            } else { // Case B: Parent of node is right child of Grand-parent of node
                Node* uncle = grandparent->left;

                // Case 1: The uncle of node is also red
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2: node is left child of its parent
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    // Case 3: node is right child of its parent
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }

        root->color = BLACK;
    }

    // Function to handle deletion
    void balanceDelete(Node* node) {
        while (node != root && node->color == BLACK) {
            if (node == node->parent->left) {
                Node* sibling = node->parent->right;

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    rotateLeft(node->parent);
                    sibling = node->parent->right;
                }

                if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                    sibling->color = RED;
                    node = node->parent;
                } else {
                    if (sibling->right->color == BLACK) {
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rotateRight(sibling);
                        sibling = node->parent->right;
                    }

                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(node->parent);
                    node = root;
                }
            } else {
                Node* sibling = node->parent->left;

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    rotateRight(node->parent);
                    sibling = node->parent->left;
                }

                if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                    sibling->color = RED;
                    node = node->parent;
                } else {
                    if (sibling->left->color == BLACK) {
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        rotateLeft(sibling);
                        sibling = node->parent->left;
                    }

                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rotateRight(node->parent);
                    node = root;
                }
            }
        }

        node->color = BLACK;
    }

public:
    RedBlackTree() : root(nullptr) {}

    // Insert a node
    void insert(int data) {
        Node* node = new Node(data);
        root = bstInsert(root, node);
        balanceInsert(node);
    }

    // Delete a node
    void deleteNode(int data) {
        Node* node = bstDelete(root, data);
        if (node) balanceDelete(node);
    }
    
    // Traversal (In-order)
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Wrapper function for traversal
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree tree;
    int x,n,c,w,a;
    int target;
    c=0;w=1;
    do
    {
        cout<<"Choose the following"<<endl;
        cout<<"1) Enter the Nodes"<<endl;
        cout<<"2) Delete Nodes"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"Enter the choice ";
        cin>>a;
        switch(a)
        {
            case 1:// Insert nodes
                   cout<<"Enter number of nodes to be added ";
                   cin>>n;
                   for(int i=0;i<n;i++)
                   {
                      cout<<"Enter node "<<i+1<<" ";
                      cin>>x;
                       tree.insert(x);
                      c++;
                      cout << "In-order traversal of the RBT tree: ";
                      tree.inorder();
                      cout << endl;
                   }
                   break;
            case 2://delete Nodes
                   cout<< "Enter the target ";cin>>target;
                   tree.deleteNode(target);
                   cout << "In-order traversal after deletion: ";
                   tree.inorder();
                   cout << endl;
                   break;
            default: w=0;
                     break;
        }
    }
    while(w==1);
    return 0;

    return 0;
}
