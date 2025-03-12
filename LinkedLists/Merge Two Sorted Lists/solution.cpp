#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    ListNode* pointer1 = list1;
    ListNode* pointer2 = list2;

    while(pointer1 != NULL && pointer2 != NULL) {
        if(pointer1->val <= pointer2->val) {
            while (pointer1->next != NULL && pointer1->next->val <= pointer2->val) {
                pointer1 = pointer1->next;
            }
            ListNode* temp = pointer1->next;
            pointer1->next = pointer2;
            pointer1 = temp;
        } else {
            while (pointer2->next != NULL && pointer2->next->val <= pointer1->val) {
                pointer2 = pointer2->next;
            }
            ListNode* temp = pointer2->next;
            pointer2->next = pointer1;
            pointer2 = temp;
        }
    }

    return list1->val > list2->val ? list2 : list1;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    // Creating first linked list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Creating second linked list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Merging the lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
