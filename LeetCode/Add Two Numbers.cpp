/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
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
	//walk over the lists to add them
	//Time: N(O), Space: N(O)
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* result = nullptr;
        ListNode* resultHead = nullptr;

        //if one of the number ran out of node, we treat as 0 so we have the same logic
        while(l1 || l2 || carry > 0)
        {
            int digit1 = (l1 == nullptr)? 0 : l1->val;
            int digit2 = (l2 == nullptr)? 0 : l2->val;

            //update sum and carry for the new result node
            sum = digit1+digit2 + carry;
            carry = sum / 10;
            sum %= 10;

            //create new node for the result
            ListNode* newNode = new ListNode(sum);
            if(!resultHead)
            {
                // store the first node and don't change it
                resultHead = newNode;
                // no need to walk the result node since it is null at this point
            }
            else
            {
                //if you are not on the first digit, we already have a result node
                result->next = newNode;
            }
            result = newNode;

            //walk the lists
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }

        return resultHead;
    }
};