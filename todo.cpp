#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct todolist
{
     int id;
     string task;
};

int ID;
void banner();
void addTask();
void showTask();
int searchTasK();
void deleteTask();


int main()
{
     system("cls");
     while (true)
     {
          banner();
          cout << "\n\t1. Add Task";
          cout << "\n\t2. Show Task";
          cout << "\n\t3. Search Task";
          cout << "\n\t4. Show Task";
          

          int choice;
          cout << "\n\tEnter Choice: ";
          cin >> choice;
          switch (choice)
          {
          case 1:
               addTask();
               break;
          case 2:
               showTask();
               break;
          case 3:
               searchTasK();
               break;
          case 4:
               deleteTask();
               break;

          default:
               break;
          }
     }
     return 0;
}

void banner()
{
     cout << "______________________________" << endl;
     cout << "\t  MY TODO";
     cout << "\n______________________________" << endl;
}

void addTask()
{
     system("cls");
     banner();
     todolist todo;
     cout << "Enter new Task" << endl;
     cin.get();
     getline(cin, todo.task);
     char save;
     cout << "Save?(y/n)";
     cin >> save;
     if (save == 'y')
     {
          ID++;
          ofstream fout;
          fout.open("todo.txt");
          fout << "\n"
               << ID;
          fout << "\n"
               << todo.task;
          fout.close();

          char more;
          cout << "Add more task? (y/n):";
          cin >> more;
          if (more == 'y')
          {
               addTask();
          }
          else
          {
               system("cls");
               cout << "Added Successfully!" << endl;
               return;
          }
     }
     system("cls");
}

void showTask()
{
     system("cls");
     banner();
     todolist todo;
     ifstream fin;
     fin.open("todo.txt");
     cout << "Task: " << endl;

     while (!fin.eof())
     {
          fin >> todo.id;
          fin.ignore();
          getline(fin, todo.task);
          if (todo.task != "")
          {
               cout << "\t" << todo.id << ": " << todo.task << endl;
          }
          else
          {
               cout << "\tEmpty!" << endl;
          }
     }
     fin.close();
     char exit;
     cout << "Exit? (y/n): ";
     cin >> exit;
     if (exit != 'y')
     {
          showTask();
     }
     system("cls");
}

int searchTasK()
{
     system("cls");
     banner();
     int id;
     cout << "Enter task id: ";
     cin >> id;
     todolist todo;
     ifstream fin("todo.txt");
     while (!fin.eof())
     {
          fin >> todo.id;
          fin.ignore();
          getline(fin, todo.task);
          if (todo.id == id)
          {
               system("cls");
               cout << "\t" << todo.id << ": " << todo.task << endl;
               return id;
          }
     }
     system("cls");
     cout << "Not Found" << endl;
     return 0;
}

void deleteTask()
{
     system("cls");
     int id = searchTasK();
     if (id != 0)
     {
          char del;
          cout << "\n\tDelete? (y/n)";
          cin >> del;
          if (del == 'y')
          {
               todolist todo;
               ofstream tempFile;
               tempFile.open("temp.txt");
               ifstream fin;
               fin.open("todo.txt");
               int index = 1;
               while (!fin.eof())
               {
                    fin >> todo.id;
                    fin.ignore();
                    getline(fin, todo.task);
                    if (todo.id != id)
                    {
                         tempFile << "\n"
                                  << index;
                         tempFile << "\n"
                                  << todo.task;
                         index++;
                         ID--;
                    }
               }
               fin.close();
               tempFile.close();
               remove("todo.txt");
               rename("temp.txt", "todo.txt");
               system("cls");
               cout << "\n\tDeleted Successfully" << endl;
          }
          else
          {
               system("cls");
               cout << "not Deleted" << endl;
          }
     }
}
