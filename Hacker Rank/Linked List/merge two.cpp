struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1;
    
    ListNode* sorted = new ListNode();
    ListNode* head = sorted;
    
    while (l1!=nullptr && l2!=nullptr) {
        if (l1->val < l2->val) {
            sorted->next = l1;
            l1=l1->next;
        }
        else {
            sorted->next = l2;
            l2=l2->next;
        }
        sorted = sorted->next;
    }
    
    if (l1==nullptr) sorted->next=l2;
    else sorted->next=l1;
    
    return head->next;
}