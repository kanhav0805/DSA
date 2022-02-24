#include<iostream>
#include<climits>
#include<bits/stdc++.h>
#include "stack class array.cpp"
using namespace std;
int main() {
    Stack<char> s;
    s.push(100);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}
