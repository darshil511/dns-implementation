// Online C++ compiler to run C++ program online
#include <iostream>
#define SIZE 5

using namespace std;

struct Node {
    int data;
    Node* child[SIZE];
};

int search(Node* head, int searchValue) {
    int temp;
    if (head->data == searchValue) {
        return head->data;
    }
    else {
        if (head->child != NULL) {
            for (int i = 0; i < SIZE; i++) {
                if (head->child[i] != NULL) {
                    temp = search(head->child[i], searchValue);
                    if (temp != -1) {
                        return temp;
                    }
                }
            }
        }
        return -1;
    }
}

int main() {
    // Green node
    Node childNode1 = {4, NULL};

    // Green node
    Node childNode2 = {5, NULL};

    // Green node
    Node childNode3 = {8, NULL};

    // Red node
    Node parentNode1 = {-1, {&childNode1, &childNode2}};

    // Red node
    Node parentNode2 = {-1, {&childNode3}};

    //Blue node
    Node grandParentNode = {-1, {&parentNode1, &parentNode2}};

    cout << search(&grandParentNode, 9);

    return 0;
}