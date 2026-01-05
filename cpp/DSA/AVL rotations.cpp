#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
struct AVLNode
{
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

struct Warrior {
    int id;             // Primary key for AVL organization
    string name;
    int chiPower;

    // Comparison operators based on Warrior ID for AVL
    bool operator<(const Warrior& other) 
    { 
        return id < other.id;
    }
    bool operator>(const Warrior& other)
    {
        return id > other.id; 
    }
    bool operator==(const Warrior& other) 
    {
        return id == other.id; 
    }
};

template <typename T>
class AVLTree 
{
private:
    AVLNode<T>* root;

    // Utility functions
    int height(AVLNode<T>* node)
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode<T>* node)
    {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }

    void updateHeight(AVLNode<T>* node) 
    {
        if (node) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    AVLNode<T>* rotateRight(AVLNode<T>* y)
    {
        AVLNode<T>* x = y->left;
        AVLNode<T>* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x; // new root
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* x)
    {
        AVLNode<T>* y = x->right;
        AVLNode<T>* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y; // new root
    }

    // Left Right rotation
    AVLNode<T>* rotateLeftRight(AVLNode<T>* node)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left rotation
    AVLNode<T>* rotateRightLeft(AVLNode<T>* node)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    AVLNode<T>* balance(AVLNode<T>* node) 
    {
        if (!node) return node;

        updateHeight(node);

        int balanceFactor = getBalanceFactor(node);

        // LL Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);

        // RR Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);

        // LR Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0)
            return rotateLeftRight(node);

        // RL Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0)
            return rotateRightLeft(node);

        return node;
    }

    AVLNode<T>* insertHelper(AVLNode<T>* node, T data)
    {
        if (node == nullptr)
            return new AVLNode<T>(data);

        if (data < node->data)
            node->left = insertHelper(node->left, data);
        else if (data > node->data)
            node->right = insertHelper(node->right, data);
        else
            return node; // Duplicate IDs not allowed

        return balance(node);
    }

    AVLNode<T>* minValueNode(AVLNode<T>* node) 
    {
        AVLNode<T>* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode<T>* maxValueNode(AVLNode<T>* node)
    {
        AVLNode<T>* current = node;
        while (current && current->right != nullptr)
            current = current->right;
        return current;
    }

    AVLNode<T>* removeHelper(AVLNode<T>* node, T data)
    {
        if (!node)
            return node;

        if (data < node->data)
            node->left = removeHelper(node->left, data);
        else if (data > node->data)
            node->right = removeHelper(node->right, data);
        else {
            // node with only one child or no child
            if ((node->left == nullptr) || (node->right == nullptr)) 
            {
                AVLNode<T>* temp = node->left ? node->left : node->right;

                // No child case
                if (temp == nullptr) 
                {
                    temp = node;
                    node = nullptr;
                }
                else 
                { // One child case
                    *node = *temp; // Copy the contents
                }
                delete temp;
            }
            else
            {
                // node with two children: get inorder successor (smallest in right subtree)
                AVLNode<T>* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = removeHelper(node->right, temp->data);
            }
        }

        if (!node)
            return node;

        return balance(node);
    }

    AVLNode<T>* searchHelper(AVLNode<T>* node, T data)
    {
        if (node == nullptr || node->data == data)
            return node;
        if (data < node->data)
            return searchHelper(node->left, data);
        else
            return searchHelper(node->right, data);
    }

    void inorderHelper(AVLNode<T>* node) 
    {
        if (!node) return;
        inorderHelper(node->left);
        printNode(node);
        inorderHelper(node->right);
    }

    void preorderHelper(AVLNode<T>* node)
    {
        if (!node) return;
        printNode(node);
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(AVLNode<T>* node) 
    {
        if (!node) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        printNode(node);
    }

    bool isBalancedHelper(AVLNode<T>* node)
    {
        if (!node) return true;
        int bf = getBalanceFactor(node);
        if (bf > 1 || bf < -1) return false;
        return isBalancedHelper(node->left) && isBalancedHelper(node->right);
    }

    AVLNode<T>* cloneHelper(AVLNode<T>* node) 
    {
        if (!node) return nullptr;
        AVLNode<T>* newNode = new AVLNode<T>(node->data);
        newNode->height = node->height;
        newNode->left = cloneHelper(node->left);
        newNode->right = cloneHelper(node->right);
        return newNode;
    }

    void clearHelper(AVLNode<T>* node)
    {
        if (!node) return;
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }

    AVLNode<T>* predecessorHelper(AVLNode<T>* node, T data) 
    {
        AVLNode<T>* current = searchHelper(root, data);
        if (!current) return nullptr;

        // If left subtree exists, predecessor is rightmost node of left subtree
        if (current->left) 
        {
            AVLNode<T>* pred = current->left;
            while (pred->right) pred = pred->right;
            return pred;
        }

        // Else go up until we find a node that is smaller
        AVLNode<T>* pred = nullptr;
        AVLNode<T>* ancestor = root;
        while (ancestor != current) {
            if (current->data > ancestor->data)
            {
                pred = ancestor;
                ancestor = ancestor->right;
            }
            else 
            {
                ancestor = ancestor->left;
            }
        }
        return pred;
    }

    AVLNode<T>* successorHelper(AVLNode<T>* node, T data) 
    {
        AVLNode<T>* current = searchHelper(root, data);
        if (!current) return nullptr;

        // If right subtree exists, successor is leftmost node of right subtree
        if (current->right) 
        {
            AVLNode<T>* succ = current->right;
            while (succ->left) succ = succ->left;
            return succ;
        }

        // Else go up until we find a node that is larger
        AVLNode<T>* succ = nullptr;
        AVLNode<T>* ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                succ = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return succ;
    }

    void printNode(AVLNode<T>* node)
    {
        // Specialization for Warrior type since T may vary
        // This function should be specialized or overloaded for Warrior specifically.
    }

public:
    AVLTree() : root(nullptr) {}

    AVLTree(const AVLTree& other)
    {
        root = cloneHelper(other.root);
    }

    ~AVLTree() {
        clear();
    }

    AVLTree& operator=(const AVLTree& other) 
    {
        if (this != &other) 
        {
            clear();
            root = cloneHelper(other.root);
        }
        return *this;
    }

    void insert(T data)
    {
        root = insertHelper(root, data);
    }

    void remove(T data) 
    {
        root = removeHelper(root, data);
    }

    AVLNode<T>* search(T data)
    {
        return searchHelper(root, data);
    }

    T findMin() 
    {
        AVLNode<T>* minNode = minValueNode(root);
        if (minNode)
            return minNode->data;
        return -1;
    }

    T findMax() {
        AVLNode<T>* maxNode = maxValueNode(root);
        if (maxNode) 
            return maxNode->data;
        return -1;
        
    }

    AVLNode<T>* predecessor(T data) 
    {
        return predecessorHelper(root, data);
    }

    AVLNode<T>* successor(T data)
    {
        return successorHelper(root, data);
    }

    int height()
    {
        return height(root);
    }

    bool isBalanced()
    {
        return isBalancedHelper(root);
    }

    AVLTree clone()
    {
        AVLTree copy;
        copy.root = cloneHelper(root);
        return copy;
    }

    void clear()
    {
        clearHelper(root);
        root = nullptr;
    }

    // Recursive traversals
    void inorder()
    {
        inorderHelper(root);
    }

    void preorder() 
    {
        preorderHelper(root);
    }

    void postorder() 
    {
        postorderHelper(root);
    }

    // Iterative traversals
    void inorderIterative()
    {
        stack<AVLNode<T>*> s;
        AVLNode<T>* curr = root;

        while (curr != nullptr || !s.empty())
        {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            printNode(curr);

            curr = curr->right;
        }
    }

    void preorderIterative() 
    {
        if (!root) return;
        stack<AVLNode<T>*> s;
        s.push(root);

        while (!s.empty())
        {
            AVLNode<T>* node = s.top();
            s.pop();
            printNode(node);

            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
    }

    void postorderIterative() 
    {
        if (!root) 
            return;
        stack<AVLNode<T>*> s1, s2;
        s1.push(root);

        while (!s1.empty()) 
        {
            AVLNode<T>* node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        while (!s2.empty()) 
        {
            printNode(s2.top());
            s2.pop();
        }
    }

    void levelOrder()
    {
        if (!root) return;
        queue<AVLNode<T>*> q;
        q.push(root);

        while (!q.empty())
        {
            AVLNode<T>* node = q.front();
            q.pop();
            printNode(node);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    int size() 
    {
        return sizeHelper(root);
    }

private:
    int sizeHelper(AVLNode<T>* node) 
    {
        if (!node) return 0;
        return 1 + sizeHelper(node->left) + sizeHelper(node->right);
    }
};

template<>
void AVLTree<Warrior>::printNode(AVLNode<Warrior>* node)
{
    if (node)
    {
        cout << "ID: " << node->data.id
            << ", Name: " << node->data.name
            << ", ChiPower: " << node->data.chiPower << '\n';
    }
}


template<>
Warrior AVLTree<Warrior>::findMin()
{
   
    // Find by lowest chiPower, so we need to traverse all nodes
    Warrior minWarrior = root->data;
    queue<AVLNode<Warrior>*> q;
    q.push(root);
    while (!q.empty())
    {
        AVLNode<Warrior>* curr = q.front();
        q.pop();
        if (curr->data.chiPower < minWarrior.chiPower)
            minWarrior = curr->data;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return minWarrior;
}

template<>
Warrior AVLTree<Warrior>::findMax() 
{
    
    // Find by highest chiPower, so we need to traverse all nodes
    Warrior maxWarrior = root->data;
    queue<AVLNode<Warrior>*> q;
    q.push(root);
    while (!q.empty())
    {
        AVLNode<Warrior>* curr = q.front();
        q.pop();
        if (curr->data.chiPower > maxWarrior.chiPower)
            maxWarrior = curr->data;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return maxWarrior;
}


int displayMenu()
{
    cout << "\n--- Kung Fu Balance Tree Menu ---\n";
    cout << "1. Add Warrior\n";
    cout << "2. Remove Warrior\n";
    cout << "3. Find Warrior\n";
    cout << "4. Find Strongest Warrior\n";
    cout << "5. Find Weakest Warrior\n";
    cout << "6. List Warriors In-Order\n";
    cout << "7. Display Tree Stats\n";
    cout << "8. Clone Archive\n";
    cout << "9. Clear Archive\n";
    cout << "10. Battle Simulation\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}

int main()
{
    AVLTree<Warrior> archive;
    int choice;
    do 
    {
        choice = displayMenu();
        if (choice == 1) 
        {
            Warrior w;
            cout << "Enter Warrior ID: ";
            cin >> w.id;
            cout << "Enter Warrior Name: ";
            cin.ignore();
            getline(cin, w.name);
            cout << "Enter Chi Power Level: ";
            cin >> w.chiPower;
            archive.insert(w);
            cout << "Warrior added.\n";
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Warrior ID to remove: ";
            cin >> id;
            Warrior w{ id, "", 0 };
            archive.remove(w);
            cout << "Warrior removed if existed.\n";
        }
        else if (choice == 3) 
        {
            int id;
            cout << "Enter Warrior ID to find: ";
            cin >> id;
            Warrior w{ id, "", 0 };
            AVLNode<Warrior>* res = archive.search(w);
            if (res) {
                cout << "Warrior found:\n";
                cout << "ID: " << res->data.id << ", Name: " << res->data.name << ", ChiPower: " << res->data.chiPower << '\n';
            }
            else 
            {
                cout << "Warrior not found.\n";
            }
        }
        else if (choice == 4)
        {
           
                Warrior strongest = archive.findMax();
                cout << "Strongest Warrior (highest Chi Power):\n";
                cout << "ID: " << strongest.id << ", Name: " << strongest.name << ", ChiPower: " << strongest.chiPower << '\n';
           
        }
        else if (choice == 5) 
        {
            
                Warrior weakest = archive.findMin();
                cout << "Weakest Warrior (lowest Chi Power):\n";
                cout << "ID: " << weakest.id << ", Name: " << weakest.name << ", ChiPower: " << weakest.chiPower << '\n';
            
        }
        else if (choice == 6)
        {
            cout << "Warriors in-order (sorted by ID):\n";
            archive.inorder();
        }
        else if (choice == 7) 
        {
            cout << "Total Warriors: " << archive.size() << '\n';
            cout << "Tree Height: " << archive.height() << '\n';
            cout << "Is Balanced: " << (archive.isBalanced() ? "Yes" : "No") << '\n';
        }
        else if (choice == 8) 
        {
            AVLTree<Warrior> clone = archive.clone();
            cout << "Archive cloned successfully. Displaying cloned archive:\n";
            clone.inorder();
        }
        else if (choice == 9)
        {
            archive.clear();
            cout << "Archive cleared.\n";
        }
        else if (choice == 10)
        {
            int id1, id2;
            cout << "Enter ID of first warrior: ";
            cin >> id1;
            cout << "Enter ID of second warrior: ";
            cin >> id2;
            Warrior w1{ id1, "", 0 }, w2{ id2, "", 0 };
            AVLNode<Warrior>* node1 = archive.search(w1);
            AVLNode<Warrior>* node2 = archive.search(w2);
            if (!node1 || !node2) 
            {
                cout << "One or both warriors not found.\n";
            }
            else
            {
                cout << "Comparing Chi Power:\n";
                if (node1->data.chiPower > node2->data.chiPower)
                    cout << node1->data.name << " wins!\n";
                else if (node1->data.chiPower < node2->data.chiPower)
                    cout << node2->data.name << " wins!\n";
                else
                    cout << "It's a tie!\n";
            }
        }
        else if (choice == 0)
        {
            cout << "Exiting system.\n";
        }

    } while (choice != 0);

   
}
