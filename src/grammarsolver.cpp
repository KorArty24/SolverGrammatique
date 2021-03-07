/*
 * File: grammarsolver.cpp
 * --------------------------
 * Name:
 * Section leader:
 * This file contains grammar generating code for CS106B.
 */

#include "grammarsolver.h"
#include "map.h"

using namespace std;
string  removeSpaces(string str);
string generateGrammar(string &s, Map<string,Vector<Vector<string>>> &rt);
Vector<string> constructterminals(string st);
/**
 * Generates grammar for a given symbol a certain number of times given
 * a BNF input file.
 *
 * This will be called by grammarmain.cpp.
 *
 * @param input - Input stream of BNF file.
 * @param symbol - Symbol to generate
 * @param times - Number of times grammar is generated
 * @return Vector of strings of size times with random generations of symbol
 */
Vector<string> grammarGenerate(istream& input, string symbol, int times) {
    // TODO: write this function
    Map<string,Vector<Vector<string>>> rulesTable;
    Vector<Vector<string>> _rules;
    Vector<string> vstr;
    while (true) {
    string line;
    getline(input,line);
    if (input.fail()) break;
    Vector<string> v1 = stringSplit(line, "::=");
    string key = v1.front();
    string value = v1.back();
    Vector<string> rules = stringSplit(value,"|");
    Vector<Vector<string>> result;
    for (string se: rules) {
        _rules.add(stringSplit(se, " "));
    }
    rulesTable.put(key,_rules);
    _rules.clear();
    }
   // string o=rulesTable.toString();
    //cout << rulesTable.toString();
    int n=0;
    for (int i=0; i<times; i++){
        vstr.add(generateGrammar(symbol, rulesTable));
    }
    return vstr;           // This is only here so it will compile
}
 string generateGrammar(string &s, Map<string,Vector<Vector<string>>> &rtable){

        if (!rtable.containsKey(s)) {return s;}
        int r=randomInteger(0,rtable.get(s).size()-1);
        string str;
        string result;
        for (int i=0; i<(rtable.get(s).get(r)).size(); i++){
            cout << i <<endl;
            str=rtable.get(s).get(r).get(i);
            result+=generateGrammar(str,rtable)+"";

        }

        return result;
    }





