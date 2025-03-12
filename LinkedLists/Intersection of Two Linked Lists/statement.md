# Problem: Intersection of Two Linked Lists

[LeetCode Problem Link](https://leetcode.com/problems/intersection-of-two-linked-lists/)

---

## Problem Statement
Given the heads of two singly linked lists `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return `null`.

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

### Custom Judge:
The inputs to the judge are given as follows (your program is not given these inputs):
- `intersectVal` - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
- `listA` - The first linked list.
- `listB` - The second linked list.
- `skipA` - The number of nodes to skip ahead in `listA` (starting from the head) to get to the intersected node.
- `skipB` - The number of nodes to skip ahead in `listB` (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be accepted.

---

## Examples

### Example 1
**Input**:  
`intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3`  
**Output**: `Intersected at '8'`  
**Explanation**:  
- The intersected node's value is `8`.  
- From the head of A, it reads as `[4,1,8,4,5]`.  
- From the head of B, it reads as `[5,6,1,8,4,5]`.  
- There are `2` nodes before the intersected node in A.  
- There are `3` nodes before the intersected node in B.  

---

### Example 2
**Input**:  
`intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1`  
**Output**: `Intersected at '2'`  
**Explanation**:  
- The intersected node's value is `2`.  
- From the head of A, it reads as `[1,9,1,2,4]`.  
- From the head of B, it reads as `[3,2,4]`.  
- There are `3` nodes before the intersected node in A.  
- There is `1` node before the intersected node in B.  

---

### Example 3
**Input**:  
`intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2`  
**Output**: `No intersection`  
**Explanation**:  
- From the head of A, it reads as `[2,6,4]`.  
- From the head of B, it reads as `[1,5]`.  
- Since the two lists do not intersect, `intersectVal` must be `0`, while `skipA` and `skipB` can be arbitrary values.  

---

### Example 4
**Input**:  
`intersectVal = 0, listA = [1,3,5,7,9,11,13,15,17,19,21], listB = [2], skipA = 11, skipB = 1`  
**Output**: `No intersection`  
**Explanation**:  
- From the head of A, it reads as `[1,3,5,7,9,11,13,15,17,19,21]`.  
- From the head of B, it reads as `[2]`.  
- Since the two lists do not intersect, `intersectVal` must be `0`.  

---

### Example 5
**Input**:  
`intersectVal = 4, listA = [2,2,4,5,4], listB = [2,2,4,5,4], skipA = 2, skipB = 2`  
**Output**: `Intersected at '4'`  
**Explanation**:  
- The intersected node's value is `4`.  
- From the head of A, it reads as `[2,2,4,5,4]`.  
- From the head of B, it reads as `[2,2,4,5,4]`.  
- Both lists intersect at the node with value `4`.  

---

## Constraints
- The number of nodes of `listA` is in the range `[1, 3 * 10^4]`
- The number of nodes of `listB` is in the range `[1, 3 * 10^4]`
- `1 <= Node.val <= 10^5`
- `0 <= skipA <= m`
- `0 <= skipB <= n`
- `intersectVal` is `0` if `listA` and `listB` do not intersect.
- `intersectVal == listA[skipA] == listB[skipB]` if `listA` and `listB` intersect.

---

## Follow-Up
Could you write a solution that runs in `O(m + n)` time and uses only `O(1)` memory?
