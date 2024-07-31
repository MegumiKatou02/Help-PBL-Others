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
    ListNode *Pivot(ListNode *head, ListNode *&tail, int x)
    {
        ListNode *prev = nullptr;
        while(head != nullptr)
        {
            if(head->val >= x)
            {
                tail = prev;
                return head;
            }
            prev = head;
            head = head->next;
        }
        return nullptr;
    }
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return nullptr;
        ListNode *tail = nullptr;
        ListNode *pivot = Pivot(head, tail, x);
        if(!pivot) return head;
        ListNode *cur = pivot->next;

        ListNode *prev = pivot;

        // add first
        ListNode *empty = new ListNode();
        empty->next = head;
        //
        if(tail == nullptr)
        {
            tail = empty;
        }
        cout << pivot->val << "\n";

        while(cur != nullptr)
        {
            if(cur->val < x)
            {
                cout << tail->val << " - " << prev->val << " - " << cur->val << " - ";
                ListNode *temp = cur->next;
                tail->next = cur;
                cur->next = pivot;
                prev->next = temp;
                tail = cur;
                cur = prev->next;
                continue;
            }
            prev = cur;
            if(cur != nullptr)
                cur = cur->next;
        }
        head = empty->next;
        
        delete empty;
        empty = nullptr;

        return head;
    }
};

int main()
{

    return 0;
}