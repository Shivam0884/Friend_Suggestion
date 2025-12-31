#ifndef GRAPH_H
#define GRAPH_H

#include<unordered_map>
#include<string>
#include<vector>
#include"User.h"

using namespace std;

class Graph {
    private:
      unordered_map<int , User>users;
      unordered_map<int, vector<int>> adjList;

    public:
      void addUser(int id , string name);
      void addFriendship(int id1 , int id2);
      vector<int>getFriends(int userId);
      int getDegree(int userid);
      vector<pair<int , double>> suggestFriends(int userId);
      void saveToFile();
      void loadFromFile();
};

#endif