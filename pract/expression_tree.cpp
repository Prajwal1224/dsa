#include <iostream> 
#include <stack> 
#include <cctype>  // for isalpha() 
using namespace std;
struct TreeNode { 
    char data; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(char val) : data(val), left(NULL), right(NULL) {} 
}; 
bool isOperator(char c)  
{ 
    return (c == '+' || c == '-' || c == '*' || c == '/'); 
} 
TreeNode* constructExpressionTree(const string& prefix)  
{ 
    stack<TreeNode*> stack; 
    for (int i = prefix.length() - 1; i >= 0; i--) 
 { 
        char currentChar = prefix[i]; 
        if (isalpha(currentChar))  
       { 
            stack.push(new TreeNode(currentChar)); 
        }  
    else if (isOperator(currentChar))  
       {
               TreeNode* operatorNode = new TreeNode(currentChar); 
            operatorNode->left = stack.top(); 
            stack.pop(); 
            operatorNode->right = stack.top(); 
            stack.pop(); 
 
            stack.push(operatorNode); 
        } 
    } 
    return stack.top(); 
} 
void postOrderTraversal(TreeNode* root)  
{ 
    if (!root)  
   { 
        return; 
    } 
    stack<TreeNode*> stack; 
    std::stack<char> resultStack; 
    stack.push(root); 
    while (!stack.empty())  
   { 
        TreeNode* current = stack.top(); 
        stack.pop(); 
        resultStack.push(current->data); 
        if (current->left) 
      { 
            stack.push(current->left); 
        } 
        if (current->right)  
      { 
            stack.push(current->right); 
        } 
    } 
    while (!resultStack.empty())  
  { 
        cout << resultStack.top() << " "; 
        resultStack.pop(); 
    } 
    cout << endl; 
 } 
void deleteTree(TreeNode* root)  
{ 
    if (root == NULL)  
   { 
        return; 
    } 
    // Post-order traversal for deletion 
    stack<TreeNode*> stack; 
    stack.push(root); 
    while (!stack.empty())  
   { 
        TreeNode* current = stack.top(); 
        stack.pop(); 
        if (current->left)  
       { 
            stack.push(current->left); 
        } 
        if (current->right)  
      { 
            stack.push(current->right); 
        } 
        delete current; 
    }
} 
int main()  
{ 
    string prefixExpression = "+--a*bc/def"; 
    // Construct the expression tree 
    TreeNode* root = constructExpressionTree(prefixExpression); 
    // Traverse the tree using post-order traversal 
    cout << "Post-order Traversal: "; 
    postOrderTraversal(root); 
    // Delete the entire tree 
    deleteTree(root); 
    cout<<"Tree deleted!";
    return 0; 
}
