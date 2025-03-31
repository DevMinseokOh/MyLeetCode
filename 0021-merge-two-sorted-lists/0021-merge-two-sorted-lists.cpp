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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        vector<int> temp;

        ListNode* tempPtr = nullptr;
        while (list1 != nullptr) {
            temp.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            temp.push_back(list2->val);
            list2 = list2->next;
        }

        sort(temp.begin(), temp.end());

        ListNode* result = nullptr;
        ListNode* turn = nullptr;
        for (int value : temp) {
            ListNode* tempPtr = new ListNode(value);
            if (result == nullptr) {
                result = tempPtr;
                turn = tempPtr;
            } else {
                turn->next = tempPtr;
                turn = turn->next;
            }
        }

        return result;
    }
};