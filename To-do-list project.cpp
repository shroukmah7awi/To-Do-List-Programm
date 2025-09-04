#include <iostream>
#include <string>
using namespace std;

// TO-DO-LIST APP
// 4 functions

struct Task {
    int Number;
    bool isCompleted;
    string Title;
    Task* next;
};

Task* top = NULL;
int nextNumber = 1;

void addTasks(string title);
void viewTasks();
void completeTask(int number);
void deleteTask(int id);

int main() {
    cout << "----- TO - DO - LIST -----\n" << endl;

    // Add tasks
    int n;
    cout << "Enter Number Of Tasks: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string task;
        cout << "Enter Task " << i + 1 << ": ";
        getline(cin, task);
        addTasks(task);
    }

    cout << "\nTasks added successfully!\n" << endl;

    // View tasks
    cout << "CURRENT TASKS:\n";
    viewTasks();
    cout << "\n";

    // Complete task
    int nums;
    cout << "How Many Tasks You Have Completed? ";
    cin >> nums;

    for (int i = 0; i < nums; i++) {
        int num;
        cout << "Enter The Number Of Completed Task: ";
        cin >> num;
        completeTask(num);
    }
    cout << "\nTasks after completion:\n";
    viewTasks();
    cout << "\n";

    // Delete task
    char choice;
    cout << "Do you want to delete any task? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int delnum;
        cout << "Enter The Number Of Task To Delete: ";
        cin >> delnum;
        deleteTask(delnum);

        cout << "\nTasks After Deletion:\n";
        viewTasks();
    }
    else {
        cout << "No tasks deleted. Program finished.\n";
    }

    cout << "\nTHANK YOU\n";
    return 0;
}

void addTasks(string title) {
    Task* new_task = new Task;
    new_task->Title = title;
    new_task->isCompleted = false;
    new_task->Number = nextNumber++;
    new_task->next = NULL;

    if (top == NULL) {
        top = new_task;
    }
    else {
        Task* last = top;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_task;
    }
}

void viewTasks() {
    if (top == NULL) {
        cout << "There are no tasks!\n";
    }
    else {
        Task* current = top;
        while (current != NULL) {
            cout << "(" << current->Number << ") "
                << current->Title << " --> "
                << (current->isCompleted ? "Completed" : "Not Completed")
                << endl;
            current = current->next;
        }
    }
}

void completeTask(int number) {
    if (top == NULL) {
        cout << "No Tasks\n";
    }
    else {
        Task* com = top;
        while (com != NULL) {
            if (com->Number == number) {
                if (com->isCompleted) {
                    cout << "Task (" << number << ") is already completed.\n";
                }
                else {
                    com->isCompleted = true;
                    cout << "Task (" << number << ") marked as completed.\n";
                }
                return;
            }
            com = com->next;
        }
        cout << "Task with number (" << number << ") not found.\n";
    }
}

void deleteTask(int id) {
    if (top == NULL) {
        cout << "No Tasks to delete!\n";
        return;
    }

    Task* current = top;
    Task* previous = NULL;

    while (current != NULL && current->Number != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Task with number (" << id << ") not found.\n";
        return;
    }

    if (previous == NULL) { 
        top = current->next;
    }
    else {
        previous->next = current->next;
    }

    delete current; 
    cout << "Task (" << id << ") deleted successfully.\n";
}
