// now we learn about fthe qeue
#include <bits/stdc++.h>
using namespace std;
void explainqueue()
{
    // queue is like FIFO
    // FIFO- first in first out
    // queue is opposite to the stack

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);
    // [1, 2, 3, 4] this is print
    q.back() += 4;
    // back means is 4 not 1
    cout << q.back() << endl;

    cout << q.front() << endl;

    // this means print the 1
    // delete the front guy means 1
    q.pop();
    cout << q.front() << endl;

    // size swap empty same as stack
}
void explainPQ()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.push(8);
    pq.emplace(10);
    cout << pq.top();
    pq.pop();
    cout << pq.top();
    // size swap empty function same as ohters
    // minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); //{5}
    pq.push(2); // {2,5}

    pq.push(9); //{2,5,9}

    pq.emplace(10); //{2,5,8,10}
    cout << pq.top();
}

int main()
{

    return 0;
}