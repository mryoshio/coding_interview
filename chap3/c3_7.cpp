#include <iostream>

using namespace std;

class Node {
 public:
  Node* next;
  int order;
  string animal;

  Node() {}
  Node(int o, string a): order(o), animal(a) {};
  ~Node() {}
};

class AnimalQueue {
  int o;

public:
  Node* dogQbegin;
  Node* catQbegin;

  Node* dogQend;
  Node* catQend;

  AnimalQueue() {
    dogQbegin = nullptr;
    catQbegin = nullptr;
    o = 0;
  }

  void enqueue(string a) {
    if (a == "dog") {
      if (dogQbegin == nullptr) {
        dogQbegin = new Node(o++, "dog");
        dogQend = dogQbegin;
        return;
      }
      dogQend->next = new Node(o++, "dog");
      dogQend = dogQend->next;
      return;
    }

    if (catQbegin == nullptr) {
      catQbegin = new Node(o++, "cat");
      catQend = catQbegin;
      return;
    }
    catQend->next = new Node(o++, "cat");
    catQend = catQend->next;
  }

  Node* dequeueAny() {
    if (empty()) return nullptr;

    Node* r;

    if (catQbegin == nullptr) {
      r = dogQbegin;
      dogQbegin = dogQbegin->next;
      return r;
    }

    if (dogQbegin == nullptr) {
      r = catQbegin;
      catQbegin = catQbegin->next;
      return r;
    }

    if (dogQbegin->order <= catQbegin->order) {
      r = dogQbegin;
      dogQbegin = dogQbegin->next;
      return r;
    }

    r = catQbegin;
    catQbegin = catQbegin->next;
    return r;
  }

  Node* dequeueDog() {
    if (dogQbegin == nullptr) return nullptr;
    Node* r = dogQbegin;
    dogQbegin = dogQbegin->next;
    return r;
  }

  Node* dequeueCat() {
    if (catQbegin == nullptr) return nullptr;
    Node* r = catQbegin;
    catQbegin = catQbegin->next;
    return r;
  }

  bool empty() {
    return dogQbegin == nullptr && catQbegin == nullptr;
  }
};

void dump_list(Node* n) {
  if (n == nullptr) return;
  Node* cur_n = n;
  while (cur_n != nullptr) {
    if (static_cast<void*>(cur_n) != static_cast<void*>(n)) cout << " -> ";
    cout << "(" << cur_n->order << ": " << cur_n->animal << ")";
    cur_n = cur_n->next;
  }
  cout << endl;
}

void dump_q(AnimalQueue Q) {
  cout << "####### Q" << endl;
  dump_list(Q.dogQbegin);
  dump_list(Q.catQbegin);
}

int main() {
  srand((unsigned int)time(NULL));

  AnimalQueue Q;
  int size = 10;

  while (size--) {
    int x = rand() % 2;
    Q.enqueue(x ? "dog" : "cat");
  }

  dump_q(Q);

  while (!Q.empty()) {
    int x = rand() % 3;
    Node* n;

    switch (x) {
    case 0:
      n = Q.dequeueDog(); 
      cout << "--- deq dog";
      break;
    case 1:
      n = Q.dequeueCat();
      cout << "--- deq cat";
      break;
    case 2:
      n = Q.dequeueAny();
      cout << "--- deq any";
      break;
    }
    if (n == nullptr) {
      cout << " => got nothing" << endl;
      continue;
    }
    cout << " => (" << n->order << ", " << n->animal << ")" << endl;
    dump_q(Q);
  }
}
