#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* result = new ListNode(0);
    ListNode* next = result;

    ListNode* num1 = l1;
    ListNode* num2 = l2;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int n1 = num1 != NULL ? num1->val : 0;
        int n2 = num2 != NULL ? num2->val : 0;

        int sum = n1 + n2 + carry;
        int val = sum % 10;
        carry = sum / 10;

        ListNode* new_node = new ListNode(val);
        next->next = new_node;
        next = next->next;

        if (num1 != NULL) {
            num1 = num1->next;
        }
        if (num2 != NULL) {
            num2 = num2->next;
        }
    }

    return result->next;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Test case
int main() {
    // First number: 342 represented as 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Second number: 465 represented as 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Output result
    cout << "Sum: ";
    printList(result);

    return 0;
}
