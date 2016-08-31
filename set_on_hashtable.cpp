#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e7 + 33;

struct Node {
    Node* next;
    Node* prev;
    int value;
    Node(Node *l, Node *r, int val) {
        this -> prev = l;
        this -> next = r;
        this -> value = val;
    }
};

Node *h[N];

bool check(int a) {
    int i = a % N;
    Node *cur = h[i];
    while (cur) {
        if (cur -> value == a) return true;
        cur = cur -> next;
    }
    return false;
}


void add(int a) {
    int i = a % N;
    if (check(a)) return;
    Node* cur = h[i];
    while (cur -> next) cur = cur -> next;
    (Node*&)(cur -> next) = new Node(cur, NULL, a);
}

void cancel(int a) {
    int i = a % N;
    Node* cur = h[i];
    while (cur && cur -> value != a) cur = cur -> next;
    if (cur) {
        if (cur -> prev) (Node *&)cur -> prev -> next = cur -> next;
        if (cur -> next) (Node *&)cur -> next -> prev = cur -> prev;
        (Node *&)cur = NULL;
    }
}

int main() {
    char s[30];
    int a;
    for (int i = 0; i < N; ++i) {
        h[i] = new Node(NULL, NULL, -1);
    }
    while (scanf("%s %d\n", s, &a) == 2) {
        a += (int) 1e9;
        if (s[0] == 'i') {
            add(a);
        } else if (s[0] == 'e') {
            if (check(a)) puts("true");
            else puts("false");
        } else {
            cancel(a);
        }
    }
    return 0;
}
