# Social Network Friend Suggestion System (C++)

## 📌 Overview
This project is a **graph-based social network simulation** implemented in **C++**, which suggests new friends to users based on **mutual connections**.  
It uses **Data Structures and Algorithms (DSA)** such as **Graphs, BFS traversal, Hash Maps, and Priority Queues** to generate realistic and ranked friend recommendations.

---

## 🎯 Features
- Add users and friendships dynamically
- Represent social network using **Adjacency List**
- Suggest friends using **BFS (friends-of-friends approach)**
- Rank suggestions using **priority queue and scoring mechanism**
- Save and load the social network using **file handling**
- Menu-driven console application

---

## 🧠 DSA Concepts Used
- Graph (Undirected)
- Breadth First Search (BFS)
- Hash Maps & Sets
- Priority Queue (Max Heap)
- File Handling
- Time & Space Complexity Analysis

---

## 🏗️ Project Architecture

- **User** → Node (Vertex)
- **Friendship** → Edge
- **Social Network** → Graph
- **Friend Suggestion** → BFS + Ranking

---

## ⚙️ How Friend Suggestion Works
1. BFS is applied from a given user up to **depth 2**
2. Level 1 → Direct friends  
3. Level 2 → Friends of friends (suggestion candidates)
4. Mutual friends are counted
5. A score is calculated:- score = (mutualFriends × weight) + degree
6. Suggestions are ranked using a **priority queue**

---

## 🗂️ File Persistence
- `users.txt` → stores user IDs and names
- `friends.txt` → stores friendship pairs

The network state is restored when the program is re-run.

---

## ▶️ How to Run

### Compile
```bash
g++ main.cpp Graph.cpp User.cpp -o app
./app

---

# 🧩 2️⃣ Project Diagram (VERY IMPORTANT)

## 🧩 Project Architecture

User (Node)
|
v
Graph (Adjacency List)
|
v
BFS Traversal (Depth = 2)
|
v
Priority Queue Ranking
|
v
Suggested Friends

---

## 🗺️ High-Level System Diagram

+---------------------+
| User |
| (ID, Name) |
+----------+----------+
|
| stored in
v
+----------------------------+

Graph Class
users (map<int, User>)
adjList (map<int, vector>)
+----------------------------+
       |
       |
       v


+----------------------------+

Friend Suggestion Engine
BFS (Level-based)
Mutual Friend Counting
Priority Queue Ranking
+----------------------------+
       |
       |
       v


+----------------------------+
| Suggested Friends List |
| (Ranked Output) |
+----------------------------+


---

## 🔍 BFS-Level Diagram (Most Important for Interview)


      User A
        |
  ----------------
  |              |


Friend B Friend C
| |

| | | |
User D User E User E User F

Level 0 → User A
Level 1 → B, C
Level 2 → D, E, F

Suggested Friends → D, E, F
Priority → E (more mutual friends)

## 🧠 Data Flow Diagram

User Input
|
v
Menu-driven Program
|
v
Graph Construction
|
v
BFS Traversal (Depth 2)
|
v
Scoring & Ranking
|
v
Output Suggestions
