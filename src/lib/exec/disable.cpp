#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <set>
#include <string>
#include <sys/wait.h>

using std::set;
using std::string;

#define EXEC_PATH "/usr/bin"

inline int libexec(const string& file) {
    return execlp(file.c_str(), file.c_str(), NULL);
}

int main(int argc, char* argv[]) {
    string tmpExecs[] = {"start",
                         "stop",
                         "restart",
                         "status",
                         "enable",
                         "disable",
                         "printf",
                         "man",
                         "help"};
    set<string> execs(tmpExecs,
                      tmpExecs + sizeof(tmpExecs) / sizeof(*tmpExecs));

    setenv("PATH", EXEC_PATH, 1);

    if (argc < 2) {
        libexec("help");
        return 0;
    }

    ++argv;
    if (execs.find(*argv) != execs.end()) {
        return libexec(*argv);
    }

    else if (!strcmp(*argv, "help")) {
        libexec("help");
        return 0;
    }

    libexec("help");
    return 1;
}
