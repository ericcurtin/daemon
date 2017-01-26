
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

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
