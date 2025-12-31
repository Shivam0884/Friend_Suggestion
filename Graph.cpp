#include "Graph.h"
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <fstream>


int Graph :: getDegree(int userid){
    return adjList[userid].size();
}
void Graph::addUser(int id , string name){
    users[id] = User(id , name);
}

void Graph::addFriendship(int id1 , int id2){
    adjList[id1].push_back(id2);
    adjList[id2].push_back(id1);
}

vector<int> Graph::getFriends(int userId){
    return adjList[userId];
}

//Save file
void Graph ::saveToFile(){

    //save users
    ofstream userFile("users.txt");
    for(auto &u : users){
        userFile << u.first << " " << u.second.name << endl;
    }
    userFile.close();
    
    //save friendship
    ofstream friendsFile("friends.txt");
    unordered_set<string> written;

    for(auto &p : adjList){
        auto u = p.first;

        for(auto v : p.second){
          string key1 = to_string(u) + "-" + to_string(v);
          string key2 = to_string(v) + "-" + to_string(u);

          if(!written.count(key1) && !written.count(key2)){
            friendsFile << u << "-" << v << endl;
            written.insert(key1);
          }
        }
    }
    friendsFile.close();
}


//Load file
void Graph::loadFromFile(){
    users.clear();
    adjList.clear();

    ifstream userFile("users.txt");
    int id;
    string name;

    while(userFile >> id >> name){
        addUser(id , name);
    }
    userFile.close();

    // Load friendships
    ifstream friendsFile("friends.txt");
    int u, v;

    while (friendsFile >> u >> v) {
        addFriendship(u, v);
    }

    friendsFile.close();
}


//suggest friends
vector<pair<int , double>> Graph :: suggestFriends(int userid){
    queue<int> q;
    unordered_map<int , int> level;
    unordered_map<int , int> mutualCount;

    q.push(userid);
    level[userid] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto i : adjList[curr]){
            if(level.find(i) == level.end()){
                level[i] = level[curr] + 1;

                if(level[i] <= 2){
                    q.push(i);
                }
            }

            if(level[curr] == 1 && level[i] == 2){
                mutualCount[i]++;
            }
        }
    }

    priority_queue<pair<double , int>> pq;

    for(auto &p : mutualCount){
        int candidate = p.first;
        int mutuals = p.second;
        int degree = getDegree(candidate);

        double score = mutuals * 10 + log(degree + 1);
        pq.push({score, candidate});
    }

    vector<pair<int, double>> result;
    while(!pq.empty()){
        result.push_back({pq.top().second , pq.top().first});
        pq.pop();
    }
    return result;

}