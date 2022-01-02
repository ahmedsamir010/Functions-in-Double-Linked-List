//اذا مررت من هنا فادعو الله ان ييسر لي امري ويحقق لي حلمي ....اللهم علمنا وفهمنا
#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
    node* pre;
};
class linked {
private:
    node* head = NULL;
public:
    void insertFirst(int value);
    void insertLast(int value);
    void insertPosition(int value, int pos);
    void deltFirst();
    void deltLast();
    void deltPos(int pos);
    void deltData(int value);
    void display();
    void reverse();
};
int main()
{
    linked l;
    l.insertLast(10);
    l.insertLast(20);
    l.insertLast(90);
    l.deltPos(1);
    l.insertLast(30);
    l.insertLast(40);
    l.insertPosition(80, 2);
    l.deltFirst();
    l.deltData(30);
    l.reverse();
    l.display();
    return 0;
}

void linked::insertFirst(int value)
{
    node* newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->pre = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
    }
}

void linked::insertLast(int value)
{
    node* newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->pre = NULL;
    if (head == NULL)
        head = newNode;
    else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->pre = temp;
    }
}

void linked::insertPosition(int value, int pos)
{
    node* newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->pre = NULL;
    node* cur = head;
    if (pos == 1) {
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
        return;
    }
    for (int i = 1;i < pos;i++)
    {
        cur = cur->next;
        if (cur == NULL)
        {
            cout << "Linked list is Empty" << endl;
            return;
        }
    }
    if (cur->next == NULL) {
        cur->next = newNode;
        newNode->pre = cur->next;
        return;
    }
    cur->pre->next = newNode;
    newNode->pre = cur->pre;
    newNode->next = cur;
    cur->pre = newNode;
}
void linked::deltFirst()
{
    if (head == NULL) {
        cout << "Linked List is Empty" << endl;
        return;
    }
    else {
        node* temp = head;
        head = temp->next;
        head->pre = NULL;
        delete temp;
    }
}
void linked::deltLast()
{
    if (head == NULL)
        return;
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->pre->next = NULL;
    delete temp;
}
void linked::deltPos(int pos)
{
    node* cur = head;node* prev = NULL;
    if (head == NULL)return;
    if (pos == 1) {
        head = cur->next;
        delete cur;
        return;
    }
    for (int i = 1;i < pos;i++) {
        prev = cur;
        cur = cur->next;
        if (cur == NULL) {
            cout << "it is Not here" << endl;
            return;
        }
    }
    if (cur->next == NULL) {
        prev->next = NULL;
        delete(cur);return;
    }
    prev->next = cur->next;
    cur->next->pre = prev;
    delete cur;
}
void linked::deltData(int value)
{
    node* temp = new node;
    temp = head;
    node* pre = NULL;
    if (temp->data == value) {
        if (temp->next == NULL) {
            temp = NULL;
            delete temp;
            return;
        }
        else {
            head = head->next;
            delete temp;return;
        }
    }
    else if (head == NULL) {
        return;
    }
    while (temp->data != value) {
        pre = temp;
        temp = temp->next;
    }
    if (temp->next == NULL and temp->data != value)
    {
        cout << "Elemnt i not exist in LinKed ";
        return;
    }
    else if (temp->next == NULL) {
        pre->next = NULL;
        delete temp;
    }
    else {
        pre->next = temp->next;
        temp->next->pre = pre;
        delete temp;
    }
}
void linked::display()
{
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

void linked::reverse()
{
    node* temp = head;
    if (head == NULL)return;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->pre;
    }
}