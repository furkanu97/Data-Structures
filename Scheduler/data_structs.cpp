/* @Tolga Ovatman
Student Name: Furkan Uysal
Student ID : 150150044
Date: 13.01.2021 */
#include "data_structs.h"
#include <iostream>
#include <string>

using namespace std;

void Stack::init(){
    head = NULL;
}

void Stack::close(){
    Subtask* p;
    while(head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void Stack::push(Subtask* in)
{
    if(isEmpty()) head = in;
    else
    {
        in->next = head;
        head = in;
    }
}

Subtask* Stack::pop()
{
    Subtask *toptask;
    toptask = head;
    if(head->next != NULL) head = head->next;
    return toptask;
}

bool Stack::isEmpty()
{
    return head == NULL;
}

void Queue::init()
{
    head = NULL;
    tail = NULL;
}

void Queue::close()
{
    Process *p;
	while (head) {
		p = head;
		head = head->next;
		delete p;
	}
}

void Queue::queue(Process* in)
{
    if(isEmpty())
    {
        head = in;
        tail = in;
    }
    else 
    {
        tail->next = in;
        tail = in;
    }
}

Process* Queue::dequeue()
{
    Process *firstnode;
	firstnode = head;
    head = head->next;
	return firstnode;
}

bool Queue::isEmpty()
{
    return head == NULL;
}

Process* Queue::front()
{
    return head;
}

void MultiQueue::init()
{
    for(int i = 0; i<3; i++)
    {
        queues[i].init();
    }
}

void MultiQueue::close()
{
    for(int i = 0; i<3; i++)
    {
        queues[i].close();
    }
}

void MultiQueue::queue(Process* in)
{
    queues[in->priority-1].queue(in);
}

Process* MultiQueue::dequeue(int priority)
{
    return queues[priority-1].dequeue();
}

bool MultiQueue::isEmpty()
{
    return queues[0].head == NULL && queues[1].head == NULL && queues[2].head == NULL;
}

Process* MultiQueue::front(int priority)
{
    return queues[priority-1].head;
}