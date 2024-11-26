#include <iostream>
using namespace std;

// Define the structure of a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node with given value
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);  // Create a new node if root is null
    }

    if (value < root->data) {
        root->left = insert(root->left, value);  // Insert in the left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value);  // Insert in the right subtree
    }

    return root;  // Return the unchanged root pointer
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given value
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;  // Base case: the tree is empty

    if (value < root->data) {
        root->left = deleteNode(root->left, value);  // Move to the left subtree
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);  // Move to the right subtree
    } else {
        // Case 1 and 2: Node with one or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        Node* temp = findMin(root->right);  // Get the in-order successor
        root->data = temp->data;  // Copy the successor's data to this node
        root->right = deleteNode(root->right, temp->data);  // Delete the successor
    }
    return root;
}

// Function to search for a given value in the BST
bool search(Node* root, int target) {
    if (root == nullptr) {
        return false;  // Value not found
    }

    if (root->data == target) {
        return true;  // Value found
    } else if (target < root->data) {
        return search(root->left, target);  // Search in the left subtree
    } else {
        return search(root->right, target);  // Search in the right subtree
    }
}

// In-order traversal of the BST
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
        cout<<"2) Search Nodes"<<endl;
        cout<<"3) Delete Nodes"<<endl;
        cout<<"4) Exit"<<endl;
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
                      if(c==0)
                      {
                       root = insert(root, x);
                      }
                      else
                      {
                       insert(root, x);
                      }
                      c++;
                   }
                   cout << "In-order traversal of the BST: ";
                   inorderTraversal(root);
                   cout << endl;
                   break;
            case 2:// Search for values
                   cout<< "Enter the target ";cin>>target;
                   if (search(root, target)) 
                   {
                        cout << "Element " << target << " found in the BST." << endl;
                   } 
                   else 
                   {
                        cout << "Element " << target << " not found in the BST." << endl;
                   }
                   break;
            case 3://delete Nodes
                   cout<< "Enter the target ";cin>>target;
                   deleteNode(root,target);
                   cout << "In-order traversal of the BST: ";
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
