#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current_node = head;
    ListNode* nth_node = current_node;

    if (head->next == NULL) {
        return NULL;
    }

    while (n > 0 && nth_node != NULL) {
        nth_node = nth_node->next;
        n--;
    }

    while (nth_node != NULL && nth_node->next != NULL) {
        current_node = current_node->next;
        nth_node = nth_node->next;
    }

    if (nth_node == NULL && current_node != NULL) {
        return current_node->next;
    }

    if (current_node != NULL && current_node->next != NULL) {
        current_node->next = current_node->next->next;
    }

    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Test the function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2; // Remove 2nd node from end
    ListNode* head = createList(arr, 5);
    
    cout << "Original list: ";
    printList(head);
    
    head = removeNthFromEnd(head, n);
    
    cout << "Modified list: ";
    printList(head);
    
    return 0;
}
