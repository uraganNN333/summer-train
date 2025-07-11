#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class TreeToListConverter {
private:
    Node* prev = nullptr; 
    Node* head = nullptr;  

    void convert(Node* root) {
        if (!root) return;

        convert(root->left);

        if (!head) {
            head = root;
        }
        else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        convert(root->right);
    }

public:
    Node* convertToDoublyList(Node* root) {
        convert(root);
        return head;
    }
};

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->right) cout << " <-> ";
        head = head->right;
    }
    cout << endl;
}


int main() {
    /*
            12
           /  \
         25    10
              /  \
            30    36
                     \
                     15
    */
    
    Node* root = new Node(12);
    root->left = new Node(25);
    root->right = new Node(10);
    root->right->left = new Node(30);
    root->right->right = new Node(36);
    root->right->right->right = new Node(15);

    TreeToListConverter converter;
    Node* listHead = converter.convertToDoublyList(root);

    printList(listHead);
    return 0;
}
