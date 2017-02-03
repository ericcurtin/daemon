
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

inline char* convert(const std::string& s) {
   char* pc = new char[s.size() + 1];
   strcpy(pc, s.c_str());
   return pc;
}

inline void vs2vc(vector<string>& vs, vector<char*>& vc) {
    transform(vs.begin(), vs.end(), back_inserter(vc), convert);
}

int exec(const string& cmd) {
    string word;
    vector<string> words;
    stringstream ss;
    ss.str(cmd);

    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }

    return execvp(words.front().c_str(), &words, NULL);
}
