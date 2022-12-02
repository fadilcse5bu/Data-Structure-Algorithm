#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *next;
};
node *root = NULL;

void append(int roll)
{
    if(root == NULL){
        root = new node();
        root->roll = roll;
        root->next = NULL;
    }
    else {
        node *current_node = root;
        while(current_node->next != NULL) {
            current_node=current_node->next;
        }
        node *newnode = new node();
        newnode->roll = roll;
        newnode->next = NULL;
        current_node->next = newnode;
    }
}

void delete_node(int roll)
{
    node *current_node = root;
    node *previous_node = NULL;
    while(current_node->roll != roll){
        previous_node = current_node;
        current_node = current_node->next;
    }

    if(current_node == root) {
        node *temp = root;
        root = root->next;
        delete(temp);
    }
    else {
        previous_node->next = current_node->next;
        delete(current_node);
    }
}

void print()
{
    node *current_node = root;
    while(current_node != NULL) {
        printf("%d\n", current_node->roll);
        current_node = current_node->next;
    }
}

int main()
{
    append(1);
    append(2);
    append(6);

    delete_node(2);
    print();

    return 0;
}
