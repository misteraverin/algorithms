/*

User: Maxim Averin
mail: averin13@gmail.com

*/


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = (int) 1e6 + 33;
const ll MOD = (ll) 1e9 + 7, P = 131;

struct Node {
    Node* next;
    Node* prev;
    pair <int, string> val;
    Node(Node *l, Node *r, pair <int, string> value) {
        prev = l;
        next = r;
        val = value;
    }
};

Node *h[N];

void prepare(int a) {
    int i = a % N;
    for (Node *cur = h[i]; cur; cur = cur -> next) {
        if (cur -> val.first == a) {
            if (cur -> prev) (Node *&) cur -> prev -> next = cur -> next;
            if (cur -> next) (Node *&) cur -> next -> prev = cur -> prev;
            (Node *&)cur = NULL;
            return;
        }
    }
}

void show(int key) {
    int i = key % N;
    for (Node *cur = h[i]; cur; cur = cur -> next) {
        if (cur -> val.first == key) {
            cout << cur -> val.second << '\n';
            return;
        }
    }
    cout << "none\n";
}

void add(pair <int, string> nw) {
    prepare(nw.first);
    Node *cur = h[nw.first % N];
    while (cur -> next) cur = cur -> next;
    (Node *&) cur -> next = new Node(cur, NULL, nw);
}

int has(string s) {
    ll p = 1;
    ll ret = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        ret = (p * (ll) s[i] + ret) % MOD;
        p = (p * P) % MOD;
    }
    return (int) ret;
}

void init() {
    for (int i = 0; i < N; ++i) {
        h[i] = new Node(NULL, NULL, make_pair(-1, ""));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    init();
    string s, a, b;
    while (cin >> s >> a) {
        if (s[0] == 'p') {
            cin >> b;
            add(make_pair(has(a), b));
        } else if (s[0] == 'g') {
            show(has(a));
        } else {
            prepare(has(a));
        }
    }
    return 0;
}
