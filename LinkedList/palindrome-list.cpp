/*
234. Palindrome Linked List - Easy or Medium
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

Copyright Lokeswara Rao Bonta - 2020
DS & Algo - LinkedList
*/
#include<iostream>
using namespace  std;
// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *head2, *fast;
        slow = head;
        fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev, *curr, *next;
        prev = nullptr;
        curr = slow;
        next = nullptr;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head2 = prev;
        while(head2)
        {
            if(head->val != head2->val) return false;
            head2 = head2->next;
            head = head->next;
        }
        return true;
    }
};

int main()
{
    ListNode list(1);
    ListNode list2(2);
    ListNode list3(3);
    list.next = &list2;
    list2.next = &list3;
    Solution S;
    std::cout << "Output " << S.isPalindrome(&list) << std::endl;
    return 0;
}