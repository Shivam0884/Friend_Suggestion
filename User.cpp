#include "User.h"

User::User(){
    id = 0;
    name = "";
}

User::User(int id , string name){
   this->id = id;
   this->name = name;
}