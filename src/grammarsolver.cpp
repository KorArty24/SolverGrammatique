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
    for (string se: rules) {
        _rules.add(stringSplit(se, " "));
    }
    rulesTable.put(key,_rules);
    _rules.clear();
    }
    for (int i=0; i<times; i++){
        vstr.add(generateGrammar(symbol, rulesTable));
    }

    return vstr;           // This is only here so it will compile
}
 string generateGrammar(string &s, Map<string,Vector<Vector<string>>> &rt){

    if (!rt.containsKey(s)) {return s;}
        int r=randomInteger(0,rt.get(s).size());
        /*for (string st: rt.get(s).get(r))*/
        for (int i=0; i<(rt.get(s).get(r)).size(); i++){
            string strng=rt.get(s).get(r).get(i);
            return generateGrammar(strng,rt);
        }

        return "";//for (Vector<string> vs : rt.get(s)){}
    }




//string  removeSpaces(string str)
//{

//    int j=0;
//    string s;
//    for(int i=0;i<str.length();i++)
//        if(str[i]!=' ')
//         s.push_back(str[i]);


//    return s;
//}
