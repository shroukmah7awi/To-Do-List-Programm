using namespace std;
#include<iostream>
#include<string>

//TO-DO-LIST APP
//4 functions




struct Task
{
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

int main()
{
	cout << "====== TO - DO - LIST ======\n " << endl;

	//addTasks
	int n;
	cout << "Enter Nnmbers Of Tasks ? ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string task;
		cout << "Enter Task " << i + 1 << " : ";
		cin.ignore();
		getline(cin, task);
		addTasks(task);
	}


	cout << "\n" << "Tasks added successfully!" << endl;
	cout << "\n" << endl;

	//viewTasks
	cout << "CURRENT TASKS : " << endl;
	viewTasks();


	cout << "\n" << endl;


	//completeTask
	int nums;
	cout << "How Many Tasks You Have Completed ? ";
	cin >> nums;


	for (int i = 0; i < nums; i++)
	{
		int num;
		cout << "Enter The Number Of Completed Tasks ? ";
		cin >> num;
		completeTask(num);
	}
	cout << "\nTasks after completion:\n";
	viewTasks();


	//deleteTask
	char choice;
	cout << "Do you want to delete any task ?(y/n) ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		int delnum;
		cout << "Enter The Number Of Task To Delete ? ";
		cin >> delnum;
		deleteTask(delnum);

		cout << endl << "Tasks After Deletion: \n ";
		viewTasks();
	}
	else
	{
		cout << "No tasks deleted. Program finished.\n";
	}

	cout << "THANK YOU";
}




void addTasks(string title)
{
	Task* new_task, * last;
	new_task = new Task;
	new_task->Title = title;
	new_task->isCompleted = false;
	new_task->Number = nextNumber++;

	if (top == NULL)
	{
		top = new_task;
		new_task->next = NULL;
	}
	else
	{
		last = top;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new_task;
		new_task->next = NULL;
	}
}


void viewTasks()
{
	Task* current;
	if (top == NULL)
	{
		cout << "There is no tasks! ";
	}
	else
	{
		current = top;
		while (current != NULL)
		{
			cout << "(" << current->Number << ")" << ": " << current->Title << "  ";
			cout << " --> " << (current->isCompleted ? "Completed" : "Not Completed") << endl;
			current = current->next;
		}
	}
}


void completeTask(int number)
{
	Task* com;
	if (top == NULL)
	{
		cout << "No Tasks";
	}
	else
	{
		com = top;
		while (com != NULL)
		{
			if (com->Number == number)
			{
				if (com->isCompleted)
				{
					cout << number << " Completed" << endl;
				}
				else
				{
					com->isCompleted = true;
					cout << "Task (" << number << ") marked as completed\n";
				}
				return;
			}
			com = com->next;
		}
		cout << "Task with number (" << number << ") not found.\n";
	}
}


void deleteTask(int id)
{
	Task* curent, * previous;
	curent = top;
	previous = top;

	if (curent->Number == id)
	{
		top = curent->next;
		free(curent);
		return;
	}
	while (curent->Number != id)
	{
		previous = curent;
		curent = curent->next;
	}
	previous->next = curent->next;
	free(curent);
}
