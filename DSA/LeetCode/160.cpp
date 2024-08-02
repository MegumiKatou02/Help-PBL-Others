#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(ListNode *q = headA; q != nullptr; q = q->next)
        {
            for(ListNode *p = headB; p != nullptr; p = p->next)
            {
                if(q == p)
                    return p;
            }
        }
        return nullptr;
    }
};

int main()
{

    return 0;
}