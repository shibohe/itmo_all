#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* l;
    Node* r;
};

struct Tree {
    Node* root = 0;
    Node* search(int x) {
        Node* act = root;
        while (act != 0 && x != act -> data) {
            if (x < act -> data) {
                act = act -> l;
            }
            else {
                act = act -> r;
            }
        }
        return act;
    }

    void insert(int x) {
        if (check(x))
            return;
        Node* newel = new Node;
        newel -> data = x;
        newel -> parent = 0;
        newel -> l = 0;
        newel -> r = 0;

        Node* act = root;
        while (act != 0) {
            newel -> parent = act;
            if (newel -> data < act -> data) {
                act = act -> l;
            }
            else {
                act = act -> r;
            }
        }
        if (newel -> parent == 0) {
            root = newel;
        }
        else {
            if (newel -> data < newel -> parent -> data) {
                newel -> parent -> l = newel;
            }
            else {
                newel -> parent -> r = newel;
            }
        }
    }
    void Delete(int x) {
        Node* deleting = search(x);
        if (deleting == 0)
        {
            return;
        }
        Node* prev;
        Node* tmp;
        if (deleting -> l == 0 || deleting -> r == 0) {
            prev = deleting;
        }
        else {
            prev = next(x);
        }
        if (prev -> l != 0) {
            tmp = prev -> l;
        }
        else {
            tmp = prev -> r;
        }
        if (tmp != 0) {
            tmp -> parent = prev -> parent;
        }
        if (prev -> parent == 0) {
            root = tmp;
        }
        else {
            if (prev == prev -> parent -> l) {
                prev -> parent -> l = tmp;
            }
            else {
                prev -> parent -> r = tmp;
            }
        }
        if (prev != deleting) {
            deleting -> data = prev -> data;
        }
        delete prev;
    }

    bool check(int x) {
        return search(x) != 0;
    }

    Node* next(int x) {
        Node* current = root;
        Node* son = 0;
        while (current != 0) {
            if (current -> data > x) {
                son = current;
                current = current -> l;
            }
            else {
                current = current -> r;
            }
        }
        return son;
    }

    Node* prev(int x) {
        Node* current = root;
        Node* prev_el = 0;
        while (current != 0) {
            if (current -> data < x) {
                prev_el = current;
                current = current -> r;
            }
            else {
                current = current -> l;
            }
        }
        return prev_el;
    }
};

int main() {
    Tree tree;
    string command;
    int key;
    while (cin >> command >> key) {
        if (command == "insert") {
            tree.insert(key);
        }
        if (command == "delete") {
            tree.Delete(key);
        }
        if (command == "exists") {
            if (tree.search(key)) {
                cout << "true" << "\n";
            }
            else {
                cout << "false" << "\n";
            }
        }
        if (command == "next") {
            Node* result = tree.next(key);
            if (result == 0) {
                cout << "none" << "\n";
            }
            else {
                cout << result -> data << "\n";
            }
        }
        if (command == "prev") {
            Node* result = tree.prev(key);
            if (result == 0) {
                cout << "none" << "\n";
            }
            else {
                cout << result -> data << "\n";
            }
        }
    }
}