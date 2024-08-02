#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur != nullptr)
        {
            ListNode *fur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = fur;
        }
        head = prev;
        return head;
    }
};