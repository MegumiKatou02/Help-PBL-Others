#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void Add(ListNode *&list, int value)
{
    ListNode *node = new ListNode(value);
    if(list == nullptr)
    {
        list = node;
    }
    else 
    {
        ListNode *temp = list;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int license = 0;
        ListNode *head = nullptr;
        while(l1 != nullptr)
        {
            if(l2 != nullptr)
            {
                int value = l1->val + l2->val + license;
                license = 0;
                if(value >= 10) 
                {
                    license = value / 10;
                    value = value % 10;
                }
                // tao node moi
                Add(head, value);
            }
            else 
            {
                int value = l1->val + license;
                license = 0;
                if(value >= 10)
                {
                    license = value / 10;
                    value = value % 10;
                }
                Add(head, value);
            }
            l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }
        while(l2 != nullptr)
        {
            int value = l2->val + license;
            cout << value << ": value\n";
            if(value >= 10)
            {
                license = (l2->val + license) / 10;
                value = (l2->val + license) % 10;
            }
            else license = 0;
            Add(head, value);
            l2 = l2->next;
        }
        if(license != 0)
        {
            Add(head, license);
        }
        return head;
    }
};

int main()
{

    return 0;
}