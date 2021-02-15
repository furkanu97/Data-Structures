/* @Tolga Ovatman
Student Name: Furkan Uysal
Student ID : 150150044
Date: 13.01.2021 */
#include <string>
#include <iostream>
#include <fstream>
#include "data_structs.h"

using namespace std;

int main(int argc,char* argv[])
{
    MultiQueue multi;
    multi.init();
    Stack* st = new Stack;
    Queue* q = new Queue;
    st->init();
    q->init();
    int i = 0, spec_count = 0, lateness = 0, process_no = 0, dead = 0, time = 0;
    bool printed = false, spec = false;
    char* filename;
    filename = argv[1];
    fstream s;
    s.open(filename);
    if(s.is_open())
    {
        while(s)
        {
            Process* pro = new Process;
            process_no++;
            s >> pro->name;
            if(s.eof()) break;
            s >> pro->priority;
            s >> pro->arrival_time;
            dead += pro->arrival_time;
            s >> pro->task_count;
            for(i = 0; i < pro->task_count; i++)
            {
                Subtask* sub = new Subtask;
                s >> sub->name;
                s >> sub->duration;
                dead += sub->duration;
                sub->next = NULL;
                st->push(sub);
            }
            pro->task_stack = *st;
            pro->deadline = dead;
            pro->next = NULL;
            dead = 0;
            multi.queue(pro);
        }
    }
    s.close();
    Subtask* temp;
    Process* tp;
    while(!multi.isEmpty())
    {
        for(i = 1; i < 4; i++)
        {
            tp = multi.front(i);
            while(tp)
            {
                if(tp->arrival_time <= time)
                {
                    if(tp->priority == 2)
                    {
                        if(spec) break;
                        spec_count++;
                    }
                    temp = tp->task_stack.pop();
                    tp->task_count--;
                    time += temp->duration;
                    if(tp->task_count == 0)
                    {
                        lateness += (time - tp->deadline);
                        multi.dequeue(i);
                    }
                    cout << tp->name << " " << temp->name << endl;
                    if(spec_count == 2) spec = true;
                    if(tp->priority == 3 && spec){
                        spec = false;
                        spec_count = 0;
                    }
                    printed = true;
                    break;
                }
                tp = tp->next;
            }
            if(printed){
                printed = false;
                break;
            }
        }
    }
    cout << "Cumulative Lateness: " <<  lateness << endl;
    return EXIT_SUCCESS;
}