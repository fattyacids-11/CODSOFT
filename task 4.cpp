#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100; 

struct Task {
    string description;
    bool completed;
};

void addTask(Task tasks[], int& taskCount, const string& description) {
    if (taskCount < MAX_TASKS) {
        tasks[taskCount] = {description, false};
        cout << "Task added successfully." << endl;
        taskCount++;
    } else {
        cout << "Cannot add more tasks. Task list is full." << endl;
    }
}

void viewTasks(const Task tasks[], int taskCount) {
    cout << "Tasks:" << endl;
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending] ";
        }
        cout << tasks[i].description << endl;
    }
}

void markTaskCompleted(Task tasks[], int taskCount, int index) {
    if (index >= 1 && index <= taskCount) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(Task tasks[], int& taskCount, int index) {
    if (index >= 1 && index <= taskCount) {
        for (int i = index - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0; 
    int choice;

    do {
        cout << "\n======= To-Do List Manager =======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); 
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, taskCount, description);
                break;
            }
            case 2: {
                viewTasks(tasks, taskCount);
                break;
            }
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, taskCount, index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(tasks, taskCount, index);
                break;
            }
            case 5: {
                cout << "Exiting program. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

