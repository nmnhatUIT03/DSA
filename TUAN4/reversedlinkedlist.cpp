#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

// Hàm để chèn một nút mới vào danh sách liên kết đã sắp xếp
void insert_node(SinglyLinkedList* llist, int node_data) {
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(node_data);

    // Nếu danh sách rỗng hoặc giá trị của nút mới nhỏ hơn giá trị đầu tiên
    if (llist->head == nullptr || node_data < llist->head->data) {
        new_node->next = llist->head;
        llist->head = new_node;
        return;
    }

    SinglyLinkedListNode* current = llist->head;

    // Tìm vị trí để chèn nút mới
    while (current->next != nullptr && current->next->data < node_data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Hàm để đảo ngược danh sách liên kết
void reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist->head;
    SinglyLinkedListNode* next_node;

    while (current != nullptr) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    llist->head = prev;
}

// Hàm để in danh sách liên kết
void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* current = llist->head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;

    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist, llist_item);
    }

    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
