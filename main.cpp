#include "log_engine.h"
int main() {
    LogEngine logEngine;
    logEngine.addEvent(1, 101, "login");
    logEngine.addEvent(2, 102, "login");
    logEngine.addEvent(3, 101, "logout");
    logEngine.addEvent(4, 103, "login");

    cout << logEngine.countActiveAt(2) << endl;
    cout << logEngine.countActiveAt(3) << endl;
    cout << logEngine.countActiveAt(4) << endl;
    cout << logEngine.countActiveAt(5) << endl;

    return 0;
}