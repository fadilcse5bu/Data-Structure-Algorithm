#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct node {
    int value;
    node *pre, *next;
};
node *root = NULL, *left_node = NULL, *right_node = NULL;

int queue_size = 0;
void append_left(int value)
{
    cout << "Pushed in left: " << value << endl;
    ++queue_size;
    if(root == NULL) {
        root = new node();
        left_node = new node();
        root->pre = left_node;
        left_node->value = value;
        left_node->pre = root;
        left_node->next = NULL;
    }
    else if(root->pre == NULL) {
        left_node = new node();
        left_node->value = value;
        left_node->pre = root;
        left_node->next = NULL;
        root->pre = left_node;
    }
    else {
        node *nc = new node();
        left_node->next = nc;
        nc->value = value;
        nc->pre = left_node;
        nc->next = NULL;
        left_node = nc;
    }
}

void append_right(int value)
{
    cout << "Pushed in right: " << value << endl;
    ++queue_size;
    if(root == NULL) {
        root = new node();
        right_node = new node();
        root->next = right_node;
        right_node->value = value;
        right_node->pre = root;
        right_node->next = NULL;
    }
    else if(root->next == NULL) {
        right_node = new node();
        right_node->value = value;
        right_node->pre = root;
        right_node->next = NULL;
        root->next = right_node;
    }
    else {
        node *nc = new node();
        right_node->next = nc;
        nc->value = value;
        nc->pre = right_node;
        nc->next = NULL;
        right_node = nc;
    }
}

void delete_left()
{
    --queue_size;
    if(root == NULL or (left_node == NULL and right_node == NULL)) {
        cout << "The queue is empty" << endl;
        return;
    }
    if(left_node == NULL) {
        node *nc = new node();
        nc = root->next;
        int v = nc->value;
        cout << "Popped from left: " << v << endl;
        if(nc->next == NULL) {
            delete(nc);
            root = NULL;
        }
        else {
            node *ncc = new node();
            ncc = nc->next;
            root->next = ncc;
            delete(nc);
        }
    }
    else if(left_node->pre == root) {
        cout << "Popped from left: " << left_node->value << endl;
        root->pre = NULL;
        delete(left_node);
        left_node = NULL;
    }
    else {
        cout << "Popped from left: " << left_node->value << endl;
        node *nc = new node();
        nc = left_node->pre;
        delete(left_node);
        left_node = nc;
        left_node->next = NULL;
    }
}

void delete_right()
{
    --queue_size;
    if(root == NULL or (left_node == NULL and right_node == NULL)) {
        cout << "The queue is empty" << endl;
        return;
    }
    if(right_node == NULL) {
        node *nc = new node();
        nc = root->pre;
        int v = nc->value;
        cout << "Popped from right: " << v << endl;
        if(nc->next == NULL) {
            delete(nc);
            root = NULL;
        }
        else {
            node *ncc = new node();
            ncc = nc->next;
            root->pre = ncc;
            delete(nc);
        }
    }
    else if(right_node->pre == root) {
        cout << "Popped from right: " << right_node->value << endl;
        root->next = NULL;
        delete(right_node);
        right_node = NULL;
    }
    else {
        cout << "Popped from right: " << right_node->value << endl;
        node *nc = new node();
        nc = right_node->pre;
        delete(right_node);
        right_node = nc;
        right_node->next = NULL;
    }
}

int main()
{
    append_left(1);
    append_left(2);
    append_right(-1);
    append_right(3);
    delete_left();
    append_right(-2);
    delete_left();
    delete_right();
    delete_right();
    delete_right();
    delete_right();
    delete_right();
    delete_right();
    append_right(-5);
    delete_left();


    return 0;
}
