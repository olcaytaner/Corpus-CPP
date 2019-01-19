//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#include <regex>
#include "TurkishSplitter.h"
#include "TurkishLanguage.h"

/**
 * The contains method takes a String and a char input then check the given String contains the given char.
 *
 * @param s         String input to search for the char.
 * @param character Char input to look for in String.
 * @return true if char is found, false otherwise.
 */
bool TurkishSplitter::contains(string s, char character) {
    return s.find_first_of(character) != -1;
}

/**
 * The listContains method has a String array shortcuts which holds the possible abbreviations that might end with a '.' but not a
 * sentence finisher word. It also takes a String as an input and loops through the shortcuts array and returns
 * true if given String has any matching item in the shortcuts array.
 *
 * @param currentWord String input to check.
 * @return true if contains any abbreviations, false otherwise.
 */
bool TurkishSplitter::listContains(string currentWord) {
    string shortcuts[] = {"alb", "bnb", "bkz", "bşk", "co", "dr", "dç", "der", "em", "gn",
                          "hz", "kd", "kur", "kuv", "ltd", "md", "mr", "mö", "muh", "müh",
                          "no", "öğr", "op", "opr", "org", "sf", "tuğ", "uzm", "vb", "vd",
                          "yön", "yrb", "yrd", "üniv", "fak", "prof", "dz", "yd", "krm", "gen",
                          "pte", "p", "av", "II", "III", "IV", "VI", "VII", "VIII", "IX",
                          "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX",
                          "XX", "tuğa", "plt", "tğm", "tic", "srv", "bl", "dipl", "not", "min",
                          "cul", "san", "rzv", "or", "kor", "tüm", "st", "sn", "fr", "pl",
                          "ka", "tk", "ko", "vs", "yard", "bknz", "doç", "gör", "müz", "oyn",
                          "m", "s", "kr", "ms", "hv", "uz", "re", "ph", "mc", "ed",
                          "km", "yb", "bk", "jr", "bn", "os", "mrs", "bld", "sen", "alm",
                          "sir", "ord", "dir", "yay", "man", "brm", "edt", "dec", "mah", "cad",
                          "vol", "kom", "sok", "apt", "elk", "mad", "ort", "cap", "ste", "exc",
                          "ef"};
    for (const string &shortcut : shortcuts) {
        if (currentWord == shortcut) {
            return true;
        }
    }
    return false;
}

/**
 * The isNextCharUpperCaseOrDigit method takes a String line and an int i as inputs. First it compares each char in
 * the input line with " " and SEPARATORS ({@literal ()[]{}"'״＂՛}) and increment i by one until a mismatch or end of line.
 * <p>
 * When i equals to line length or contains one of the uppercase letters or digits it returns true, false otherwise.
 *
 * @param line String to check.
 * @param i    int defining starting index.
 * @return true if next char is uppercase or digit, false otherwise.
 */
bool TurkishSplitter::isNextCharUpperCaseOrDigit(string line, int i) {
    while (i < line.size() && (line[i] == ' ' || contains(SEPARATORS, line[i]))) {
        i++;
    }
    if (i == line.size() || contains(TurkishLanguage::UPPERCASE_LETTERS + TurkishLanguage::DIGITS + "-", line[i])) {
        return true;
    } else {
        return false;
    }
}

/**
 * The isPreviousWordUpperCase method takes a String line and an int i as inputs. First it compares each char in
 * the input line with " " and checks each char whether they are lowercase letters or one of the qxw. And decrement
 * input i by one till this condition is false.
 * <p>
 * When i equals to -1 or contains one of the uppercase letters or one of the QXW it returns true, false otherwise.
 *
 * @param line String to check.
 * @param i    int defining ending index.
 * @return true if previous char is uppercase or one of the QXW, false otherwise.
 */
bool TurkishSplitter::isPreviousWordUpperCase(string line, int i) {
    while (i >= 0 && (line[i] == ' ' || contains(TurkishLanguage::LOWERCASE_LETTERS + "qxw", line[i]))) {
        i--;
    }
    if (i == -1 || contains(TurkishLanguage::UPPERCASE_LETTERS + "QWX", line[i])) {
        return true;
    } else {
        return false;
    }
}

/**
 * The isNextCharUpperCase method takes a String line and an int i as inputs. First it compares each char in
 * the input line with " " and increment i by one until a mismatch or end of line.
 * <p>
 * When i equals to line length or contains one of the uppercase letters it returns true, false otherwise.
 *
 * @param line String to check.
 * @param i    int defining starting index.
 * @return true if next char is uppercase, false otherwise.
 */
bool TurkishSplitter::isNextCharUpperCase(string line, int i) {
    while (i < line.size() && (line[i] == ' ')) {
        i++;
    }
    if (i == line.size() || contains(TurkishLanguage::UPPERCASE_LETTERS + "\"\'", line[i])) {
        return true;
    } else {
        return false;
    }
}

/**
 * The isNameShortcut method takes a String word as an input. First, if the word length is 1, and currentWord
 * contains UPPERCASE_LETTERS letters than it returns true.
 * <p>
 * Secondly, if the length of the word is 3 (i.e it is a shortcut) and it has a '.' at its 1st index and
 * currentWord's 2nd  index is an uppercase letter it also returns true. (Ex : m.A)
 *
 * @param currentWord String input to check whether it is a shortcut.
 * @return true if given input is a shortcut, false otherwise.
 */
bool TurkishSplitter::isNameShortcut(string currentWord) {
    if (currentWord.size() == 1 && TurkishLanguage::UPPERCASE_LETTERS.find_first_of(currentWord) != -1) {
        return true;
    }
    if (currentWord.size() == 3 && currentWord[1] == '.' && contains(TurkishLanguage::UPPERCASE_LETTERS, currentWord[2])) {
        return true;
    }
    return false;
}

/**
 * The repeatControl method takes a String word as an input, and a boolean exceptionMode and compress the repetitive chars. With
 * the presence of exceptionMode it directly returns the given word. Then it declares a counter i and loops till the end of the
 * given word. It compares the char at index i with the char at index (i+2) if they are equal then it compares the char at index i
 * with the char at index (i+1) and increments i by one and returns concatenated  result String with char at index i.
 *
 * @param word          String input.
 * @param exceptionMode boolean input for exceptional cases.
 * @return String result.
 */
string TurkishSplitter::repeatControl(string word, bool exceptionMode) {
    if (exceptionMode) {
        return word;
    }
    int i = 0;
    string result;
    while (i < word.size()) {
        if (i < word.size() - 2 && word[i] == word[i + 1] && word[i] == word[i + 2]) {
            while (i < word.size() - 1 && word[i] == word[i + 1]) {
                i++;
            }
        }
        result += word[i];
        i++;
    }
    return result;
}

/**
 * The isApostrophe method takes a String line and an integer i as inputs. Initially declares a String apostropheLetters
 * which consists of abcçdefgğhıijklmnoöprsştuüvyzABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ, âàáäãèéêëíîòóôûúqwxÂÈÉÊËÌÒÛQWX and 0123456789.
 * Then, it returns true if the result of contains method which checks the existence of previous char and next char
 * at apostropheLetters returns true, returns false otherwise.
 *
 * @param line String input to check.
 * @param i    index.
 * @return true if apostropheLetters contains previous char and next char, false otherwise.
 */
bool TurkishSplitter::isApostrophe(string line, int i) {
    string apostropheLetters = TurkishLanguage::LETTERS + TurkishLanguage::EXTENDED_LANGUAGE_CHARACTERS + TurkishLanguage::DIGITS;
    if (i + 1 < line.length()) {
        char previousChar = line[i - 1];
        char nextChar = line[i + 1];
        return contains(apostropheLetters, previousChar) && contains(apostropheLetters, nextChar);
    } else {
        return false;
    }
}

/**
 * The numberExistsBeforeAndAfter method takes a String line and an integer i as inputs. Then, it returns true if
 * the result of contains method, which compares the previous char and next char with 0123456789, returns true and
 * false otherwise.
 *
 * @param line String input to check.
 * @param i    index.
 * @return true if previous char and next char is a digit, false otherwise.
 */
bool TurkishSplitter::numberExistsBeforeAndAfter(string line, int i) {
    if (i + 1 < line.size() && i > 0) {
        char previousChar = line[i - 1];
        char nextChar = line[i + 1];
        return contains(TurkishLanguage::DIGITS, previousChar) && contains(TurkishLanguage::DIGITS, nextChar);
    } else {
        return false;
    }
}

/**
 * The isTime method takes a String line and an integer i as inputs. Then, it returns true if
 * the result of the contains method, which compares the previous char, next char and two next chars with 0123456789,
 * returns true and false otherwise.
 *
 * @param line String input to check.
 * @param i    index.
 * @return true if previous char, next char and two next chars are digit, false otherwise.
 */
bool TurkishSplitter::isTime(string line, int i) {
    if (i + 2 < line.length()) {
        char previousChar = line[i - 1];
        char nextChar = line[i + 1];
        char twoNextChar = line[i + 2];
        return contains(TurkishLanguage::DIGITS, previousChar) && contains(TurkishLanguage::DIGITS, nextChar) && contains(TurkishLanguage::DIGITS, twoNextChar);
    } else {
        return false;
    }
}

/**
 * The split method takes a String line as an input. Firstly it creates a new sentence as currentSentence a new {@link ArrayList}
 * as sentences. Then loops till the end of the line and checks some conditions;
 * If the char at ith index is a separator;
 * <p>
 * ' : assigns currentWord as currentWord'
 * { : increment the curlyBracketCount
 * } : decrement the curlyBracketCount
 * " : increment the specialQuotaCount
 * " : decrement the specialQuotaCount
 * ( : increment roundParenthesisCount
 * ) : decrement roundParenthesisCount
 * [ : increment bracketCount
 * ] : decrement bracketCount
 * " : assign quotaCount as 1- quotaCount
 * ' : assign apostropheCount as 1- apostropheCount
 * <p>
 * If the currentWord is not empty, it adds the currentWord after repeatControl to currentSentence.
 * <p>
 * If the char at index i is " and  bracketCount, specialQuotaCount, curlyBracketCount, roundParenthesisCount, and
 * quotaCount equal to 0 and also the next char is uppercase or digit, it adds currentSentence to sentences.
 * <p>
 * If the char at ith index is a sentence ender;
 * <p>
 * . and currentWord is www : assigns webMode as true. Ex: www.google.com
 * . and currentWord is a digit or in web or e-mail modes : assigns currentWord as currentWord+char(i) Ex: 1.
 * . and currentWord is a shortcut or an abbreviation : assigns currentWord as currentWord+char(i) and adds currentWord to currentSentence. Ex : bkz.
 * ' and next char is uppercase or digit: add word to currentSentence as ' and add currentSentence to sentences.
 *
 * <p>
 * If the char at index i is ' ', i.e space, add word to currentSentence and assign "" to currentSentence.
 * If the char at index i is -,  add word to currentSentence and add sentences when the wordCount of currentSentence greater than 0.
 * <p>
 * If the char at ith index is a punctuation;
 * : and if currentWord is "https" : assign webMode as true.
 * , and there exists a number before and after : assign currentWord as currentWord+char(i) Ex: 1,2
 * : and if line is a time : assign currentWord as currentWord+char(i) Ex: 12:14:24
 * - and there exists a number before and after : assign currentWord as currentWord+char(i) Ex: 12-1
 * {@literal @} : assign emailMode as true.
 *
 * @param line String input to split.
 * @return sentences {@link ArrayList} which holds split line.
 */
vector<Sentence> TurkishSplitter::split(string line) {
    bool emailMode = false, webMode = false;
    int i = 0, roundParenthesisCount = 0, bracketCount = 0, curlyBracketCount = 0, quotaCount = 0, apostropheCount = 0;
    Sentence currentSentence = Sentence();
    string currentWord;
    vector<Sentence> sentences;
    while (i < line.size()) {
        if (contains(SEPARATORS, line[i])) {
            if (line[i] == '\'' && !currentWord.empty() && isApostrophe(line, i)) {
                currentWord += line[i];
            } else {
                if (!currentWord.empty()) {
                    currentSentence.addWord(new Word(repeatControl(currentWord, webMode || emailMode)));
                }
                currentSentence.addWord(new Word(string(1, line[i])));
                currentWord = "";
                switch (line[i]) {
                    case '{':
                        curlyBracketCount++;
                        break;
                    case '}':
                        curlyBracketCount--;
                        break;
                    case '(':
                        roundParenthesisCount++;
                        break;
                    case ')':
                        roundParenthesisCount--;
                        break;
                    case '[':
                        bracketCount++;
                        break;
                    case ']':
                        bracketCount--;
                        break;
                    case '"':
                        quotaCount = 1 - quotaCount;
                        break;
                    case '\'':
                        apostropheCount = 1 - apostropheCount;
                        break;
                }
                if (line[i] == '"' && bracketCount == 0 && curlyBracketCount == 0 &&
                    roundParenthesisCount == 0 && quotaCount == 0 && isNextCharUpperCaseOrDigit(line, i + 1)) {
                    sentences.emplace_back(currentSentence);
                    currentSentence = Sentence();
                }
            }
        } else {
            if (contains(SENTENCE_ENDERS, line[i])) {
                if (line[i] == '.' && currentWord == "www") {
                    webMode = true;
                }
                if (line[i] == '.' && !currentWord.empty() && (webMode || emailMode || contains(TurkishLanguage::DIGITS, line[i - 1]))) {
                    currentWord += line[i];
                } else {
                    if (line[i] == '.' && (listContains(currentWord) || isNameShortcut(currentWord))) {
                        currentWord += line[i];
                        currentSentence.addWord(new Word(currentWord));
                        currentWord = "";
                    } else {
                        if (!currentWord.empty()) {
                            currentSentence.addWord(new Word(repeatControl(currentWord, webMode || emailMode)));
                        }
                        currentWord = line[i];
                        do {
                            i++;
                        } while (i < line.length() && contains(SENTENCE_ENDERS, line[i]));
                        i--;
                        currentSentence.addWord(new Word(currentWord));
                        if (roundParenthesisCount == 0 && bracketCount == 0 && curlyBracketCount == 0 && quotaCount == 0) {
                            if (i + 1 < line.length() && line[i + 1] == '\'' && apostropheCount == 1 && isNextCharUpperCaseOrDigit(line, i + 2)) {
                                currentSentence.addWord(new Word("'"));
                                i++;
                                sentences.emplace_back(currentSentence);
                                currentSentence = Sentence();
                            } else {
                                if (i + 2 < line.length() && line[i + 1] == ' ' && line[i + 2] == '\'' && apostropheCount == 1 && isNextCharUpperCaseOrDigit(line, i + 3)) {
                                    currentSentence.addWord(new Word("'"));
                                    i += 2;
                                    sentences.emplace_back(currentSentence);
                                    currentSentence = Sentence();
                                } else {
                                    if (isNextCharUpperCaseOrDigit(line, i + 1)) {
                                        sentences.emplace_back(currentSentence);
                                        currentSentence = Sentence();
                                    }
                                }
                            }
                        }
                        currentWord = "";
                    }
                }
            } else {
                if (line[i] == ' ') {
                    emailMode = false;
                    webMode = false;
                    if (!currentWord.empty()) {
                        currentSentence.addWord(new Word(repeatControl(currentWord, webMode || emailMode)));
                        currentWord = "";
                    }
                } else {
                    if (line[i] == '-' && !webMode && roundParenthesisCount == 0 && isNextCharUpperCase(line, i + 1) && !isPreviousWordUpperCase(line, i - 1)) {
                        if (!currentWord.empty() && TurkishLanguage::DIGITS.find_first_of(currentWord) == -1) {
                            currentSentence.addWord(new Word(repeatControl(currentWord, webMode || emailMode)));
                        }
                        if (currentSentence.wordCount() > 0) {
                            sentences.emplace_back(currentSentence);
                        }
                        currentSentence = Sentence();
                        roundParenthesisCount = bracketCount = curlyBracketCount = quotaCount = 0;
                        if (!currentWord.empty() && regex_match(currentWord, regex("\\d+"))) {
                            currentSentence.addWord(new Word(currentWord + " -"));
                        } else {
                            currentSentence.addWord(new Word("-"));
                        }
                        currentWord = "";
                    } else {
                        if (contains(PUNCTUATION_CHARACTERS, line[i]) || contains(TurkishLanguage::ARITHMETIC_CHARACTERS, line[i])) {
                            if (line[i] == ':' && (currentWord == "http" || currentWord == "https")) {
                                webMode = true;
                            }
                            if (webMode) {
                                currentWord += line[i];
                            } else {
                                if (line[i] == ',' && numberExistsBeforeAndAfter(line, i)) {
                                    currentWord += line[i];
                                } else {
                                    if (line[i] == ':' && isTime(line, i)) {
                                        currentWord += line[i];
                                    } else {
                                        if (line[i] == '-' && numberExistsBeforeAndAfter(line, i)) {
                                            currentWord += line[i];
                                        } else {
                                            if (!currentWord.empty()) {
                                                currentSentence.addWord(new Word(repeatControl(currentWord, webMode || emailMode)));
                                            }
                                            currentSentence.addWord(new Word(string(1, line[i])));
                                            currentWord = "";
                                        }
                                    }
                                }
                            }
                        } else {
                            if (line[i] == '@') {
                                currentWord += line[i];
                                emailMode = true;
                            } else {
                                currentWord += line[i];
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    if (!currentWord.empty()) {
        currentSentence.addWord(new Word(repeatControl(currentWord, webMode || emailMode)));
    }
    if (currentSentence.wordCount() > 0) {
        sentences.emplace_back(currentSentence);
    }
    return sentences;
}
