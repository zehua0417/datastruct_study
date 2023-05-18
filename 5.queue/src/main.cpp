#include <iostream>
#include <string>
#include "../include/queue.h"

using namespace std;

int main() {
    Queue queue;
    string command;

    cout << "Commands:" << endl;
    cout << "enqueue [value]" << endl;
    cout << "dequeue" << endl;
    cout << "isEmpty" << endl;
    cout << "isFull" << endl;
    cout << "print" << endl;
    cout << "quit" << endl;

    while (true) {
        cout << ">_@ ~$ ";
        cin >> command;

        if (command == "enqueue") {
            int value;
            cin >> value;
            queue.enqueue(value);
        }
        else if (command == "dequeue") {
            queue.dequeue();
        }
        else if (command == "isEmpty") {
            cout << "Queue is " << (queue.isEmpty() ? "" : "not ") << "empty" << endl;
        }
        else if (command == "isFull") {
            cout << "Queue is " << (queue.isFull() ? "" : "not ") << "full" << endl;
        }
        else if (command == "print") {
            queue.print();
        }
        else if (command == "quit") {
            break;
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
