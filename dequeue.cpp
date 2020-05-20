//
// Created by fred on 25/01/19.
//

#include <iostream>
#include <deque>

#include <unordered_map>

using namespace std;

void showdq(deque <int> g)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
//    deque <int> gquiz;
//    gquiz.push_back(10);
//    gquiz.push_front(20);
//    gquiz.push_back(30);
//    gquiz.push_front(15);
//    cout << "The deque gquiz is : ";
//    showdq(gquiz);
//
//    cout << "\ngquiz.size() : " << gquiz.size();
//    cout << "\ngquiz.max_size() : " << gquiz.max_size();
//
//    cout << "\ngquiz.at(2) : " << gquiz.at(2);
//    cout << "\ngquiz.front() : " << gquiz.front();
//    cout << "\ngquiz.back() : " << gquiz.back();
//
//    cout << "\ngquiz.pop_front() : ";
//    gquiz.pop_front();
//    showdq(gquiz);
//
//    cout << "\ngquiz.pop_back() : ";
//    gquiz.pop_back();
//    showdq(gquiz);

    std::unordered_map<string, int> umap;
    umap.insert(make_pair("Fred", 28));
    umap.insert(make_pair("Jason",21));

    string key = "Fred";
    if (umap.find(key) == umap.end()){
        cout << key << " not found\n\n";
    } else {
        cout << "found it" << endl;
    }
    std::unordered_map<string, int >:: iterator itr;
    for (itr = umap.begin(); itr != umap.end(); itr++)
    {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stroes the value part
        cout << itr->first << "  " << itr->second << endl;
    }
    return 0;
}
