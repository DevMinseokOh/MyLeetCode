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
public:
    void checkNode(ListNode* head, int val) {
        if (head->next != nullptr) {
            if (head->next->val == val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }

            if (head != nullptr) {
                checkNode(head, val);
            }
        }
    }
    ListNode* removeElements(ListNode* head, int val) {

        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode* res = head;

        if (head != nullptr) {
            checkNode(head, val);
        } else {
            res = nullptr;
        }

        return res;
    }
};