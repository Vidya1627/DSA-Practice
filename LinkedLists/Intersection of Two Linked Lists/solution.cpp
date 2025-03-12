#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Method using a hash set
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> seen_nodes;
    ListNode* pointer1 = headA;
    ListNode* pointer2 = headB;

    while(pointer1 != NULL) {
        seen_nodes.insert(pointer1);
        pointer1 = pointer1->next;
    }
    while(pointer2 != NULL) {
        if(seen_nodes.find(pointer2) != seen_nodes.end()) {
            return pointer2;
        }
        pointer2 = pointer2->next;
    }
    
    return NULL;
}

// Method using constant space
ListNode *getIntersectionNodeOptimized(ListNode *headA, ListNode *headB) {
    ListNode* pointer1 = headA;
    ListNode* pointer2 = headB;

    int size_of_listA = 0;
    int size_of_listB = 0;

    while(pointer1 != NULL) {
        size_of_listA++;
        pointer1 = pointer1->next;
    }

    while(pointer2 != NULL) {
        size_of_listB++;
        pointer2 = pointer2->next;
    }

    pointer1 = headA;
    pointer2 = headB;

    // Adjust the starting point of the longer list
    if(size_of_listA > size_of_listB) {
        int diff = size_of_listA - size_of_listB;
        while(diff) {
            pointer1 = pointer1->next;
            diff--;
        }
    }
    if(size_of_listA < size_of_listB) {
        int diff = size_of_listB - size_of_listA;
        while(diff) {
            pointer2 = pointer2->next;
            diff--;
        }
    }

    // Find the intersection point
    while(pointer1 != NULL && pointer2 != NULL) {
        if(pointer1 == pointer2) {
            return pointer1;
        }
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }

    return NULL;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    ListNode* intersection = getIntersectionNodeOptimized(headA, headB);
    if(intersection != NULL) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}
