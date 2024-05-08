#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a new node into the binary tree
void Insert(Node*& root, Node* temp) {
  if (root == NULL) {
    root = temp; // Insert as the root if the tree is empty
  } else {
    Node* parent = NULL; // Use a parent pointer to keep track of the parent

    // Traverse the tree to find the correct insertion position
    Node* current = root;
    while (current != NULL) {
      parent = current; // Update parent pointer before moving

      if (temp->data < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    // Insert the node at the leaf position based on BST property
    if (temp->data < parent->data) {
      parent->left = temp;
    } else {
      parent->right = temp;
    }
  }
}

// Function to display nodes in preorder traversal
void Preorder(Node* temp) {
    if (temp != NULL) {
        cout << temp->data << " ";
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

// Function to display nodes in inorder traversal
void Inorder(Node* temp) {
    if (temp != NULL) {
        Inorder(temp->left);
        cout << temp->data << " ";
        Inorder(temp->right);
    }
}

// Function to display nodes in postorder traversal
void Postorder(Node* temp) {
    if (temp != NULL) {
        Postorder(temp->left);
        Postorder(temp->right);
        cout << temp->data << " ";
    }
}

// Function to search for an element in the binary search tree
Node* Search(Node* root, int val, Node* parent) {
    if (root != NULL) {
        if (root->data > val)
            return Search(root->left, val, root);
        else if (root->data < val)
            return Search(root->right, val, root);
        else {
            cout << "Value is found successfully" << endl;
            return parent;
        }
    } else {
        return NULL;
    }
}

// Function to find the smallest element in the binary search tree
void Smallest(Node* root) {
    while (root->left != NULL)
        root = root->left;
    cout << "Smallest element: " << root->data << endl;
}

// Function to find the longest path in the binary tree
int LongestPath(Node* root) {
    if (root == NULL)
        return 0;
    int L = LongestPath(root->left);
    int R = LongestPath(root->right);
    if (L > R)
        return (L + 1);
    else
        return (R + 1);
}

// Function to swap left and right pointers at every node
void swapNodes(Node* root) {
    if (root == NULL)
        return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapNodes(root->left);
    swapNodes(root->right);
}

int main() {
    Node* root = NULL; // Initialize root as NULL
    
    // Create binary tree
    char choice;
    do {
        int value;
        cout << "Enter data element for the node: ";
        cin >> value;
        Node* temp = new Node(value);
        Insert(root, temp);
        cout << "Do you want to add another node? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Preorder traversal: ";
    Preorder(root);
    cout << endl;
    
    cout << "Inorder traversal: ";
    Inorder(root);
    cout << endl;
    
    cout << "Postorder traversal: ";
    Postorder(root);
    cout << endl;
    
    int val;
    cout << "Enter the value to search: ";
    cin >> val;
    Node* parent = Search(root, val, NULL);
    if (parent == NULL)
        cout << "Value not found" << endl;
    
    Smallest(root);
    
    cout << "Length of longest path: " << LongestPath(root) << endl;
    
    swapNodes(root);
    cout << "Binary tree after swapping left and right pointers: " << endl;
    cout << "Inorder traversal: ";
    Inorder(root);
    
    cout << endl;
    
    return 0;
}
