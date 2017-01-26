#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <set>
#include <string>
#include <sys/wait.h>

#include "exec.hpp"

using std::set;
using std::string;

inline char* convert(const std::string& s) {
   char* pc = new char[s.size() + 1];
   strcpy(pc, s.c_str());
   return pc;
}

inline void vs2vc(vector<string>& vs, vector<char*>& vc) {
    transform(vs.begin(), vs.end(), back_inserter(vc), convert);
}

inline int libexec(const string& file) {
    const string path = LIBEXECDIR + string(getenv("PATH"));
    setenv("PATH", path.c_str(), 1);

    return execlp(file.c_str(), file.c_str(), NULL);
}

int main(int argc, char* argv[]) {
    string tmpLexecs[] = {"start",
                          "stop",
                          "restart",
                          "status",
                          "enable",
                          "disable",
                          "help"};
    set<string> lexecs(tmpLexecs,
                       tmpLexecs + sizeof(tmpLexecs) / sizeof(*tmpLexecs));

    if (argc < 2) {
        return libexec("help");
    }

    ++argv;
    if (lexecs.find(*argv) != lexecs.end()) {
        return libexec(*argv);
    }

    return libexec("help");
}