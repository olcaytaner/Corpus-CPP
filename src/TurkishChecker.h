//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#ifndef CORPUS_TURKISHCHECKER_H
#define CORPUS_TURKISHCHECKER_H

#include "LanguageChecker.h"

class TurkishChecker : public LanguageChecker {
public:
    bool isValidWord(const string& word) override;
};


#endif //CORPUS_TURKISHCHECKER_H
