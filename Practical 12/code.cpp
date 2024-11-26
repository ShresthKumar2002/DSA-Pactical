#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// Function to get the height of a node
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Function to calculate the balance factor of a node
int getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert a node in an AVL tree
Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        return node;  // Duplicate values not allowed
    }

    // Update the height of the ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node
    int balance = getBalance(node);

    // Balance the tree
    if (balance > 1 && value < node->left->data) {
        return rightRotate(node);
    }
    if (balance < -1 && value > node->right->data) {
        return leftRotate(node);
    }
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the node with minimum value
Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from an AVL tree
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            // Node with two children
            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr) {
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor of this node
    int balance = getBalance(root);

    // Balance the tree
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal of the AVL tree
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
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
                       root = insert(root, x);
                      c++;
                      cout << "In-order traversal of the AVL tree: ";
                      inorderTraversal(root);
                      cout << endl;
                   }
                   break;
            case 2://delete Nodes
                   cout<< "Enter the target ";cin>>target;
                   deleteNode(root,target);
                   cout << "In-order traversal after deletion: ";
                   inorderTraversal(root);
                   cout << endl;
                   break;
            default: w=0;
                     break;
        }
    }
    while(w==1);
    return 0;
}
