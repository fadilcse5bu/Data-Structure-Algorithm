#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int qs = 0, rear, frnt, n, dq[2000000];
void append_left(int value)
{
    if(qs == n) {
        cout << "The queue is full" << endl;
        return;
    }
    if(qs == 0) {
        rear = -1;
        frnt = 0;
    }
    ++qs;
    ++rear;
    if(rear == n) rear = 0;
    dq[rear] = value;
    cout << "Pushed in left: " << value << endl;
}

void append_right(int value)
{
    if(qs == n) {
        cout << "The queue is full" << endl;
        return;
    }
    if(qs == 0) {
        rear = 0;
        frnt = 1;
    }
    ++qs;
    --frnt;
    if(frnt < 0) frnt = n - 1;
    dq[frnt] = value;
    cout << "Pushed in right: " << value << endl;
}

void delete_left()
{
    if(qs == 0) {
        cout << "The queue is empty" << endl;
        return;
    }
    --qs;
    int value = dq[rear];
    --rear;
    if(rear < 0) rear = n - 1;
    cout << "Popped from left: " << value << endl;
}

void delete_right()
{
    if(qs == 0) {
        cout << "The queue is empty" << endl;
        return;
    }
    --qs;
    int value = dq[frnt];
    ++frnt;
    if(frnt == n) frnt = 0;
    cout << "Popped from right: " << value << endl;
}

int main()
{
    int deque_size, operation;
    cin >> deque_size;
    n = deque_size;

    append_left(1);
    append_left(2);
    append_right(-1);
    append_right(1);
    delete_left();
    delete_right();
    delete_left();
    delete_right();

    return 0;
}
