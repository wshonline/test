// 美团二面
// 递增有序链表，反转在区间内的结点
// 类似于leetcode92

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int n) : val(n), next(nullptr) {};
};

Node* func(Node *head, int left, int right) {
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;
    Node *cur = head;
    while (cur && cur->val < left) {
        prev = prev->next;
        cur = cur->next;
    }
    while (cur->next && cur->next->val <= right) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }
    return dummy->next;
}

int main() {
    Node n1(1);
    Node n2(3);
    Node n3(4);
    Node n4(5);
    Node n5(6);
    Node n6(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    Node *head = func(&n1, 4, 7);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
