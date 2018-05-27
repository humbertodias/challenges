#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int num, op, var;
    bool is_stack, is_queue, is_my_priority_queueity_queue;

    while (cin >> num) {
        stack <int> my_stack;
        queue <int> my_queue;
        priority_queue <int> my_priority_queue;

        is_stack = true;
        is_queue = true;
        is_my_priority_queueity_queue = true;

        for (int i  = 0 ; i < num ; i++) {
            cin >> op >> var;

            if (op == 1) {
                my_stack.push(var);    
                my_queue.push(var);
                my_priority_queue.push(var);
            }
            else {
                if (!my_stack.empty()) {
                    if (my_stack.top() != var)
                        is_stack = false;
                    my_stack.pop();
                }
                else
                    is_stack = false;
                
                if (!my_queue.empty()) {
                    if (my_queue.front() != var)
                        is_queue = false;
                    my_queue.pop();
                }
                else
                    is_queue = false;

                if (!my_priority_queue.empty()) {
                    if (my_priority_queue.top() != var)
                        is_my_priority_queueity_queue = false;
                    my_priority_queue.pop();
                }
                else
                    is_my_priority_queueity_queue = false;
            }
        }

        if (is_stack && !is_queue && !is_my_priority_queueity_queue)
            cout << "stack" << endl;
        else if (!is_stack && is_queue && !is_my_priority_queueity_queue)
            cout << "queue" << endl;
        else if (!is_stack && !is_queue && is_my_priority_queueity_queue)
            cout << "priority queue" << endl;
        else if (!is_stack && !is_queue && !is_my_priority_queueity_queue)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;
    }

    return 0;    
}