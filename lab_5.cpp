#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* l;
    Node* r;

    Node(int value) : data(value), parent(nullptr), l(nullptr), r(nullptr) {}
};

struct Tree {
    Node* root = nullptr;

    Node* search(int x) {
        Node* act = root;
        while (act != nullptr && x != act->data) {
            if (x < act->data) {
                act = act->l;
            } else {
                act = act->r;
            }
        }
        return act;
    }

    void insert(int x) {
        if (check(x))
            return;

        Node* newel = new Node(x);
        Node* act = root;
        Node* parent = nullptr;

        while (act != nullptr) {
            parent = act;
            if (newel->data < act->data) {
                act = act->l;
            } else {
                act = act->r;
            }
        }

        newel->parent = parent;
        if (parent == nullptr) {
            root = newel;
        } else {
            if (newel->data < parent->data) {
                parent->l = newel;
            } else {
                parent->r = newel;
            }
        }
    }

    bool check(int x) {
        return search(x) != nullptr;
    }
};

int main() {
    Tree tree;
    queue<Node*> queue;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        tree.insert(element);
    }

    if (tree.root != nullptr) {
        queue.push(tree.root);

        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0; i < size; ++i) {
                Node* current = queue.front();
                queue.pop();
                if (i == size - 1) {
                    cout << current->data << " ";
                }

                if (current->l != nullptr) {
                    queue.push(current->l);
                }

                if (current->r != nullptr) {
                    queue.push(current->r);
                }
            }
        }
    }

}