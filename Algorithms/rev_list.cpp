/**@file	playground/Algorithms/rev_list.cpp
 * @author	puneet
 * @version	704
 * @date
 * 	Created:	Fri Jun  3 09:53:11 2016 \n
 * 	Last Update:	Fri Jun  3 09:53:11 2016
 */

/*===========================================================================*/
/*===============================[ Includes ]===============================*/
/*===========================================================================*/
// Reverses a singly linked list

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "lib/utils.h"

/*===========================================================================*/
/*===============================[ Includes ]===============================*/
/*===========================================================================*/
using namespace std;

struct Node
{
    int x;
    Node *next;
} ;

//This has got O(n) space complexity because of recursion stack. 
//Better to use the non-recursive function
Node* rev_recurse(Node* head)
{
    if (!head || !head->next) {
        return head;
    }

    Node* second = head->next;
    Node* new_head = rev_recurse(second);
    second->next = head;
    head->next = nullptr;

    return new_head;
}

Node* rev_nonrec(Node* head)
{
    Node* prev = nullptr;
    while (head)
    {
        Node* nxt = head->next;
        head->next = prev;
        prev = head;     
        head = nxt;
    }
    return prev;

}

void print(Node* node)
{
    while (node)
    {
        cout << node->x << " ";
        node = node->next;
    }
    cout << "nullptr";
    
}


//Tests
int main()
{
    vector<Node*> tests;

    //1. empty
    Node* empty = nullptr;
    tests.push_back(empty);

    //2. size 1
    Node* one = new Node{1, nullptr};
    tests.push_back(one);

    //2. size 2
    Node* two = new Node{ 1, new Node {2, nullptr}};
    tests.push_back(two);

    //3. more
    Node* four = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};
    tests.push_back(four);

    //execute tests
    for ( auto test: tests)
    {
        cout << endl;
        print(test);
        cout<<endl;

        Node* rev1 = rev_recurse(test);
        print(rev1);
        cout<<endl;

        Node* rev2 = rev_nonrec(rev1);
        print(rev2);
        cout<<endl;
    }
}

