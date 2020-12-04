struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    ListNode* first = temp;
    ListNode* second = temp;
    
    for (int i=0 ; i<n ; i++) 
        first = first->next;
    
    while (first!=nullptr) {
        first = first->next;
        second = second->next;
    }
    second->val = second->next->val;
    second->next = second->next->next;
    
    return temp;
}