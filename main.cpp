#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    int choice;

    cout << "Loading existing network (if any)...\n";
    g.loadFromFile();

    while (true) {
        cout << "\n========== Social Network Friend Suggestion ==========\n";
        cout << "1. Add User\n";
        cout << "2. Add Friendship\n";
        cout << "3. Suggest Friends (Advanced Ranking)\n";
        cout << "4. Save Network\n";
        cout << "5. Load Network\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter User ID: ";
            cin >> id;
            cout << "Enter User Name: ";
            cin >> name;
            g.addUser(id, name);
            cout << "User added successfully.\n";
        }
        else if (choice == 2) {
            int u, v;
            cout << "Enter two User IDs (u v): ";
            cin >> u >> v;
            g.addFriendship(u, v);
            cout << "Friendship added successfully.\n";
        }
        else if (choice == 3) {
            int userId;
            cout << "Enter User ID for suggestions: ";
            cin >> userId;

            auto suggestions = g.suggestFriends(userId);

            if (suggestions.empty()) {
                cout << "No friend suggestions available.\n";
            } else {
                cout << "\n--- Friend Suggestions (Ranked) ---\n";
                for (auto &p : suggestions) {
                    cout << "User ID: " << p.first
                         << " | Score: " << p.second
                         << " | Degree: " << g.getDegree(p.first)
                         << endl;
                }
            }
        }
        else if (choice == 4) {
            g.saveToFile();
            cout << "Network saved successfully.\n";
        }
        else if (choice == 5) {
            g.loadFromFile();
            cout << "Network loaded successfully.\n";
        }
        else if (choice == 6) {
            g.saveToFile();
            cout << "Network saved. Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
