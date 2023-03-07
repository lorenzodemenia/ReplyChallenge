#include <iostream>
#include <vector>
#include <sys/time.h>
#include <set>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cassert>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()

template<typename A, typename B>
ostream& operator<<(ostream &os, pair<A,B> p) {
    os << "(" << p.X << "," << p.Y << ")";
    return os;
}
template<typename A, typename B, typename C>
ostream& operator<<(ostream &os, tuple<A,B,C> p) {
    os << "(" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << ")";
    return os;
}
template<typename T>
ostream& operator<<(ostream &os, vector<T> v) {
    os << "{";
    REP(i, v.S) {
        if (i) os << ", "; os << v[i];
    }
    os << "}";
    return os;
}
template<typename T>
ostream& operator<<(ostream &os, set<T> s) {
    vector<string> vs(ALL(s));
    return os << vs;
}
template<typename T>
string i2s(T x) {
    ostringstream o; o << x;
    return o.str();
}

vector<string> split_string(string s, char c = ' ') {
    vector<string> all;
    int start = 0, i;
    while (i = s.find(c, start), i >= 0) {
        if (i != start)
            all.push_back(s.substr(start, i - start));
        start = i + 1;
    }
    if (start < s.size())
        all.push_back(s.substr(start));

    return all;
}

vector<int> parse_elem(vector<string> filename, int row = 0){
    vector<string> val = split_string(filename.at(row));
    string temp;
    vector<int> res;
    REP(i,val.size()){
        res.push_back(stoi(val.at(i)));
    }
    return res;
}

vector<string> parse(string filename = "path dove vi scarica il file"){
    std::ifstream read(filename);
    string row;
    std::vector<string> parsed;
    if(read.is_open()){
        while(getline(read,row, "\n")){
            parsed.push_back(row);
        }
    }
    return parsed
}

