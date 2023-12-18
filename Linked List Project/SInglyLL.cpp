#include<iostream>
#include<stdlib.h>

using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    node* head = NULL;

    void insert(int data)
    {
        system("cls");
        
        node* new_node = new node(data);
        
        if(!head)
        {
            head = new_node;
            return;
        }

        if(!head->next)
        {
            head->next = new_node;
            return;
        }

        node* temp = head;

        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    void display()
    {
        system("cls");
        
        if(!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        node* temp = head;

        while(temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteAtEnd()
    {
        system("cls");
        
        if(!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        node* temp = head;

        while(temp->next->next)
        {
            temp = temp->next;
        }

        node* to_be_deleted = temp->next;
        temp->next = NULL;

        delete to_be_deleted;

        cout << endl << "Deletion complete." << endl << endl;
    }

    void deleteFront()
    {
        system("cls");
        
        if(!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        node* to_be_deleted = head;
        head = head->next;

        delete to_be_deleted;

        cout << endl << "Deletion complete." << endl << endl;
    }

    void deleteByVal(int val)
    {
        system("cls");
        
        if(!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        node* temp = head;

        while(temp->next->next && temp->next->data != val)
        {
            temp = temp->next;
        }

        if(!temp->next->next && temp->next->data != val)
        {
            cout << "Value is not present in the list" << endl;
            return ;
        }

        node* to_be_deleted = temp->next;
        temp->next = temp->next->next;

        delete to_be_deleted;

        cout << endl << "Deletion complete." << endl << endl;
    }

    void deleteByIndex(int i)
    {
        system("cls");
        
        if(!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        if(!head->next)
        {
            head = NULL;
            cout << endl << "Deletion complete." << endl << endl;
            return ;
        }

        if(i == 1)
        {
            node* to_be_deleted = head;
            head = head->next;

            delete to_be_deleted;

            cout << endl << "Deletion complete." << endl << endl;

            return;
        }

        node* temp = head;
        int cnt = 1;

        while(temp->next->next && cnt < i)
        {
            temp = temp->next;
            cnt++;
        }

        if(!temp->next->next)
        {
            if(cnt+1 < i)
            {
                cout << "Index is greater than the list's size" << endl;
                return ;
            }
            else    {
                node* to_be_deleted = temp->next;
                temp->next = NULL;

                cout << endl << "Deletion complete." << endl << endl;

                delete to_be_deleted;
            }
        }

        node* to_be_deleted = temp->next;
        temp = temp->next;

        delete to_be_deleted;

        cout << endl << "Deletion complete." << endl << endl;
        
    }

    void updateValue(int key_val, int up_val)
    {
        system("cls");
        
        if(!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        if(head->data == key_val)
        {
            head->data = key_val;
        }

        node* temp = head;

        while(temp && temp->data != key_val)
        {
            temp = temp->next;
        }

        if(!temp)
        {
            cout << "Value is not present in the list" << endl;
            return ;
        }

        temp->data = up_val;

        cout << "Updation complete" << endl << endl;
    }

    void updateByIndex(int i, int up_val)
    {
        system("cls");
        
        if(!head)
        {
            cout << "List is empty" << endl;
            return ;
        }

        int cnt = i;
        node* temp = head;

        while(temp && cnt > 1)
        {
            temp = temp->next;
            cnt--;
        }

        if(!temp)
        {
            cout << "Value is not present in the list" << endl;
            return ;
        }

        temp->data = up_val;

        cout << "Updation complete" << endl << endl;

    }

};


int main()
{
    LinkedList LL;
    
    while (true)
    {
        cout << "0. Exit" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Updation" << endl;
        cout << "3. Deletion" << endl;
        cout << "4. Display" << endl << endl;

        int ch;
        cout << "Enter your choice - ";
        cin >> ch;

        //system("cls");

        switch(ch)
        {
            case 0:
                exit(false);
                break;
            
            case 1:
                //cout << "Under construction..................." << endl;

                cout << "Enter element - ";
                int val;
                cin >> val;
                LL.insert(val);
                cout << "Insertion complete." << endl << endl;
                
                break;
            
            case 2:
                //cout << "Under construction..................." << endl;

                cout << "Select\n1. If you want to upgrade value by it's value itself\n2. If you want to upgarde value by index(1 based index)" << endl;
                int c;
                cout << "Your choice : ";
                cin >> c;

                switch(c)
                {
                    case 1:
                        cout << "Enter the key value : ";
                        int key_val;
                        cin >> key_val;
                        
                        cout << "Enter the upgrade value : ";
                        int up_val;
                        cin >> up_val;
                        
                        LL.updateValue(key_val, up_val);
                        break;

                    case 2:
                        cout << "Enter the index (1 based) : ";
                        int i;
                        cin >> i;

                        cout << "Enter the upgrade value : ";
                        cin >> up_val;
                        
                        LL.updateByIndex(i, up_val);
                        break;

                    default :
                        cout << "Enter a vailid choice" << endl;
                }

                break;
            
            case 3:
                //cout << "Under construction..................." << endl;

                cout << "Select\n1. Delete front\n2. Delete end\n3. Delete by index\n4. Delete by value\n";
                cout << "Your choice : ";
                cin >> c;

                switch(c)
                {
                    case 1 :
                        LL.deleteFront();
                        break;

                    case 2 :
                        LL.deleteAtEnd();
                        break;

                    case 3 :
                        cout << "Enter index (1 based) : ";
                        int idx;
                        cin >> idx;
                        LL.deleteByIndex(idx);
                        break;

                    case 4 :
                        cout << "Enter value : ";
                        int val;
                        cin >> val;
                        LL.deleteByVal(val);
                        break;

                    default :
                        cout << "Enter valid choice" << endl;
                }
                break;
            
            case 4:
                //cout << "Under construction..................." << endl;

                cout << "OUTPUT -" << endl;
                LL.display();
                cout << endl << endl;

                break;
            
            default :
                cout << "Enter a valid choice" << endl;
        }//cout << "hii";
    }
    return 0;
}