# Problem: Merge Two Sorted Lists
[LeetCode Problem Link](https://leetcode.com/problems/merge-two-sorted-lists/)

## Problem Statement
You are given the heads of two sorted linked lists `list1` and `list2`.  

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.  

Return the head of the merged linked list.

---

## Examples

### Example 1
**Input**:  
`list1 = [1,2,4]`  
`list2 = [1,3,4]`  
**Output**:  
`[1,1,2,3,4,4]`

---

### Example 2
**Input**:  
`list1 = []`  
`list2 = []`  
**Output**:  
`[]`

---

### Example 3
**Input**:  
`list1 = []`  
`list2 = [0]`  
**Output**:  
`[0]`

---

## Constraints
- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

---

## Approach
- Use two pointers to traverse both lists.
- Compare the values at the two pointers and link the smaller node to the result list.
- Adjust the `next` pointers to merge the nodes without creating new ones.

---

## Complexity
**Time Complexity**: `O(n + m)` – where `n` and `m` are the lengths of the two lists.  
**Space Complexity**: `O(1)` – No extra space used apart from the result list pointers.

---
