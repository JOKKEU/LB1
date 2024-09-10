#include <cstdint>
#include <iostream>
#include <string>

#define ERROR 1

typedef std::string surname_student;
typedef std::string name_student;
typedef uint8_t course_student;

struct table_student 
{
    name_student name;
    surname_student surname;
    course_student course;
};

struct node {
    node* next;
    table_student* ts;
    node() : ts(new table_student), next(nullptr) 
    {}
    ~node() { delete ts; }
};

struct linked_list
{
private:
    node* head;

public:
    linked_list() : head(nullptr)
    {}

    void set_value(node* tmp) 
    {
        std::cout << "Enter name for student\n";
        std::getline(std::cin, tmp->ts->name);
        std::cout << "Enter surname for student\n";
        std::getline(std::cin, tmp->ts->surname);
        std::cout << "Enter course for student\n";
        std::cin >> tmp->ts->course;


    }

    void append()
    {
        node* new_node = new node;
        set_value(new_node);

        if (head == nullptr) 
        {
            head = new_node;
        }
        else 
        {
            node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void start() 
    {
        while (true)
        {
            std::cout << "Enter '~' for break OR 'next' for next" << std::endl;
            std::string temp_string;
            std::getline(std::cin, temp_string);
            if (temp_string == "~") 
            {
                return;
            }
            else if (temp_string == "next")
            {
                append();
            }
            temp_string.clear();

        }
    }

    void finding_people_in_table() const 
    {
        std::string temp_name;
        std::string temp_surname;
        temp_name.clear();
        temp_surname.clear();
        
        std::cout << "Enter people name: ";
        std::getline(std::cin, temp_name);
        std::cout << "Enter people surname: ";
        std::getline(std::cin, temp_surname);

        node* temp = head;
        while (temp != nullptr)
        {
            if (temp->ts->name == temp_name && temp->ts->surname == temp_surname)
            {
                std::cout << "user found\n";
                return;
                temp = temp->next;
            }

        }
        std::cout << "user not found\n";
        return;
    }

    void print_list() const 
    {
        node* temp = head;
        while (temp != nullptr) 
        {
            std::cout << "Name: " << temp->ts->name << std::endl;
            std::cout << "Surname: " << temp->ts->surname << std::endl;
            std::cout << "Course: " << temp->ts->course << std::endl;
            std::cout << "\n";
            temp = temp->next;
        }
    }

    ~linked_list() 
    {
        while (head != nullptr) 
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    linked_list ln;
    while (true)
    {
        std::string operation;
        std::cout << "Enter |start| or |print| or |find|\n";
        std::getline(std::cin, operation);
        if (operation == "start") { ln.start(); }
        else if (operation == "find") { ln.finding_people_in_table(); }
        else if (operation == "print") {ln.print_list();}
        else {
            std::cout << "Error operation\n";
        }
        operation.clear();
    }

    return 0;
}
