//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#include "TurkishSplitter.h"
#include "Language/TurkishLanguage.h"

/**
 * Returns Turkish UPPERCASE letters.
 * @return Turkish UPPERCASE letters.
 */
string TurkishSplitter::upperCaseLetters() {
    return TurkishLanguage::UPPERCASE_LETTERS;
}

/**
 * Returns Turkish lowercase letters.
 * @return Turkish lowercase letters.
 */
string TurkishSplitter::lowerCaseLetters() {
    return TurkishLanguage::LOWERCASE_LETTERS;
}

/**
 * Returns shortcut words in Turkish language.
 * @return Shortcut words in Turkish language.
 */
vector<string> TurkishSplitter::shortCuts(){
    vector<string> shortCuts;
    shortCuts.emplace_back("alb");
    shortCuts.emplace_back("bnb"); 
    shortCuts.emplace_back("bkz");
    shortCuts.emplace_back("bşk");
    shortCuts.emplace_back("co");
    shortCuts.emplace_back("dr");
    shortCuts.emplace_back("dç");
    shortCuts.emplace_back("der");
    shortCuts.emplace_back("em");
    shortCuts.emplace_back("gn");
    shortCuts.emplace_back("hz");
    shortCuts.emplace_back("kd");
    shortCuts.emplace_back("kur");
    shortCuts.emplace_back("kuv");
    shortCuts.emplace_back("ltd");
    shortCuts.emplace_back("md");
    shortCuts.emplace_back("mr");
    shortCuts.emplace_back("mö");
    shortCuts.emplace_back("muh");
    shortCuts.emplace_back("müh");
    shortCuts.emplace_back("no");
    shortCuts.emplace_back("öğr");
    shortCuts.emplace_back("op");
    shortCuts.emplace_back("opr");
    shortCuts.emplace_back("org");
    shortCuts.emplace_back("sf");
    shortCuts.emplace_back("tuğ");
    shortCuts.emplace_back("uzm");
    shortCuts.emplace_back("vb");
    shortCuts.emplace_back("vd");
    shortCuts.emplace_back("yön");
    shortCuts.emplace_back("yrb");
    shortCuts.emplace_back("yrd");
    shortCuts.emplace_back("üniv");
    shortCuts.emplace_back("fak");
    shortCuts.emplace_back("prof");
    shortCuts.emplace_back("dz");
    shortCuts.emplace_back("yd");
    shortCuts.emplace_back("krm");
    shortCuts.emplace_back("gen");
    shortCuts.emplace_back("pte");
    shortCuts.emplace_back("p");
    shortCuts.emplace_back("av");
    shortCuts.emplace_back("II");
    shortCuts.emplace_back("III");
    shortCuts.emplace_back("IV");
    shortCuts.emplace_back("VI");
    shortCuts.emplace_back("VII");
    shortCuts.emplace_back("VIII");
    shortCuts.emplace_back("IX");
    shortCuts.emplace_back("X");
    shortCuts.emplace_back("XI");
    shortCuts.emplace_back("XII");
    shortCuts.emplace_back("XIII");
    shortCuts.emplace_back("XIV");
    shortCuts.emplace_back("XV");
    shortCuts.emplace_back("XVI");
    shortCuts.emplace_back("XVII");
    shortCuts.emplace_back("XVIII");
    shortCuts.emplace_back("XIX");
    shortCuts.emplace_back("XX");
    shortCuts.emplace_back("tuğa");
    shortCuts.emplace_back("plt");
    shortCuts.emplace_back("tğm");
    shortCuts.emplace_back("tic");
    shortCuts.emplace_back("srv");
    shortCuts.emplace_back("bl");
    shortCuts.emplace_back("dipl");
    shortCuts.emplace_back("not");
    shortCuts.emplace_back("min");
    shortCuts.emplace_back("cul");
    shortCuts.emplace_back("san");
    shortCuts.emplace_back("rzv");
    shortCuts.emplace_back("or");
    shortCuts.emplace_back("kor");
    shortCuts.emplace_back("tüm");
    shortCuts.emplace_back("st");
    shortCuts.emplace_back("sn");
    shortCuts.emplace_back("fr");
    shortCuts.emplace_back("pl");
    shortCuts.emplace_back("ka");
    shortCuts.emplace_back("tk");
    shortCuts.emplace_back("ko");
    shortCuts.emplace_back("vs");
    shortCuts.emplace_back("yard");
    shortCuts.emplace_back("bknz");
    shortCuts.emplace_back("doç");
    shortCuts.emplace_back("gör");
    shortCuts.emplace_back("müz");
    shortCuts.emplace_back("oyn");
    shortCuts.emplace_back("m");
    shortCuts.emplace_back("s");
    shortCuts.emplace_back("kr");
    shortCuts.emplace_back("ms");
    shortCuts.emplace_back("hv");
    shortCuts.emplace_back("uz");
    shortCuts.emplace_back("re");
    shortCuts.emplace_back("ph");
    shortCuts.emplace_back("mc");
    shortCuts.emplace_back("ed");
    shortCuts.emplace_back("km");
    shortCuts.emplace_back("yb");
    shortCuts.emplace_back("bk");
    shortCuts.emplace_back("jr");
    shortCuts.emplace_back("bn");
    shortCuts.emplace_back("os");
    shortCuts.emplace_back("mrs");
    shortCuts.emplace_back("bld");
    shortCuts.emplace_back("sen");
    shortCuts.emplace_back("alm");
    shortCuts.emplace_back("sir");
    shortCuts.emplace_back("ord");
    shortCuts.emplace_back("dir");
    shortCuts.emplace_back("yay");
    shortCuts.emplace_back("man");
    shortCuts.emplace_back("brm");
    shortCuts.emplace_back("edt");
    shortCuts.emplace_back("dec");
    shortCuts.emplace_back("mah");
    shortCuts.emplace_back("cad");
    shortCuts.emplace_back("vol");
    shortCuts.emplace_back("kom");
    shortCuts.emplace_back("sok");
    shortCuts.emplace_back("apt");
    shortCuts.emplace_back("elk");
    shortCuts.emplace_back("mad");
    shortCuts.emplace_back("ort");
    shortCuts.emplace_back("cap");
    shortCuts.emplace_back("ste");
    shortCuts.emplace_back("exc");
    shortCuts.emplace_back("ef");
    return shortCuts;
}
