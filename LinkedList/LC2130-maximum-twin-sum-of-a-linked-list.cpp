#include<bits/stdc++.h>

using namespace std;


 //* Definition for singly-linked list.
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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void printTwinPairs(ListNode* head) {
        if (head == nullptr) return;

        // Step 1: Find the second middle using your first example
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        // slow now points to the start of the second half
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        // Step 3: Traverse both halves together
        ListNode* p1 = firstHalf;
        ListNode* p2 = secondHalf;
        int max_sum = -1;
        std::cout << "Twin pairs are:\n";
        while (p2 != nullptr) { // p2 will finish first or at the same time
            std::cout << "(" << p1->val << ", " << p2->val << ")\n";
        
            max_sum = std::max(max_sum, p1->val + p2->val);

            p1 = p1->next;
            p2 = p2->next;
        }
        std::cout << "Max-Sum: " << max_sum;
    }
};

// Helper utility to build a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper utility to free allocated memory
void freeLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Creating an even-length linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    std::vector<int> values = {10, 20, 30, 40, 50, 60};
    ListNode* head = createLinkedList(values);

    // Run the twin pairing logic
    Solution solver;
    solver.printTwinPairs(head);

    // Clean up memory
    freeLinkedList(head);

    return 0;
}