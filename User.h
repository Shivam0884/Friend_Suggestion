#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    int id;
    string name;

    User(); 
    User(int id, string name);

};

#endif
