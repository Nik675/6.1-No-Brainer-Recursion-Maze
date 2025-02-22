#ifndef SUBSEQUENCE_H
#define SUBSEQUENCE_H

#include <string>
#include <iostream>
using namespace std;

class Subsequence {
public:
    Subsequence(string word) : originalWord(word) {

    }

    bool isSubsequence(string sub) {

        return isSubsequenceHelper( sub, 0, 0 );
    }

    friend ostream& operator<<( ostream& os, const Subsequence& s ) 
    {
        os << "Original Word: " << s.originalWord;
        return os;
    }

private:
    string originalWord;

    bool isSubsequenceHelper(string sub, int subIndex, int wordIndex) {
        if (subIndex == sub.size()) {
            return true;
        }

        if (wordIndex == originalWord.size()) {
            return false;
        }

        if (originalWord[wordIndex] == sub[subIndex]) {

            return isSubsequenceHelper( sub, subIndex + 1, wordIndex + 1 );

        } else {
            return isSubsequenceHelper( sub, subIndex, wordIndex + 1 );
        }
    }
};

#endif // SUBSEQUENCE_H
