#include<iostream>
using namespace std;
class todo{
public:
    void display(string tasks[],int count)
    {
    if (count==0)
        {
        cout << "No tasks to display.\n";
        }
    else
       {
        cout << "\nYour tasks are:\n";
        for (int i=0;i<count;++i)
        {
            cout<<i+1<<". "<<tasks[i]<<endl;
        }
      }
    }
};
int main()
{
    todo tsk;
    const int maxNo=100;
    string t[maxNo];
    int count=0;
    int ch;
    cout<<"Welcome to the Simple To-Do: List App!"<<endl;
    while(true)
    {
    cout<<"\nMenu:\n1.Add a new task \n2.Mark a task as completed \n3.Display tasks \n4.Exit";
    cout<<"\n\nPlease enter your choice(1-4):";
    cin>>ch;
    cin.get();
    switch(ch)
    {
        case 1:
            {
            if (count<maxNo)
                {
                string task;
                char more;

                do {
                    cout << "Enter task name: ";
                    getline(cin,task);

                    t[count]=task;
                    cout<<"\n Task \""<<t[count]<<"\" added";
                   count++;
                    cout<<"\nDo you want to add another task? (y/n): ";
                    cin>>more;
                    cin.get();  //clearing newline buffer
                } while((more=='y' || more=='Y') && count<maxNo);
               }
            else
            {
                cout <<"Task list is full.Unable to add more tasks.\n";
            }
            break;
            }
        case 2:
            {
            tsk.display(t,count);
            if(count>0)
                {
                    int tNo;
                    cout<<"\nEnter the number of the task you want to mark as completed: ";
                    cin>>tNo;
                    if (tNo>0 && tNo<=count)
                    {
                        t[tNo-1]+=" - Completed";
                        cout <<"\nTask \"" << t[tNo-1]<<"\" has been marked as completed.\n";
                    } else {
                        cout <<"\nInvalid task.Please enter valid number.\n";
                    }
                }
            break;
            }
        case 3:
            tsk.display(t,count);
            break;
        case 4:
            cout <<"Exiting the program.\n";
            return 0;
        default:
            cout<<"\nInvalid Choice.";
            break;
    }
    }
    return 0;
}
