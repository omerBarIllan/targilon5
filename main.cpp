#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex> // Include mutex header

using namespace std;

int counter = 0;
mutex counter_mutex;

void foo(bool use_mutex) {
    if (use_mutex) {
        lock_guard<mutex> guard(counter_mutex);
        counter++;
        cout << counter << endl;
    } else {
        counter++;
        cout << counter << endl;
    }
}

int main() {
    thread threads[10];
    bool use_mutex;
    cout << "Enter 1  use mutex  ";
    cin >> use_mutex;
    for (int i = 0; i < 10; i++) {
        threads[i] = thread(foo, use_mutex);
    }

    for (int i = 0; i < 10; i++) {
        threads[i].join();
    }

    // Print final counter value
    cout << "Final counter value: " << counter << endl;

    return 0;
}
