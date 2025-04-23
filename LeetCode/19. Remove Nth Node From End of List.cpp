/**
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
// Time:O(N), Space:O(1)
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode empty(0,head);

        int index = 0;


        ListNode* walker = &empty;
        ListNode* stopper = &empty;//it starts walking when walker have moved n steps
        while(walker != nullptr)
        {

            if(index > n)
            {
                stopper=stopper->next;
            }
            else
            {
                ++index;
            }

            walker = walker->next;
        }

        //remove the node
        stopper->next = stopper->next->next;

        return empty.next;
    }
};
