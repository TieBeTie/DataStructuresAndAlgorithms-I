#include <iostream>
#include <string>

struct Node

{
    char val;
    Node* next;

    // Constructor
    Node(std::string a)
    {
        for(int i = 0; i < a.size(); i++)
        {
            if('a' <= a[i] <= 'z' || 'A' <= a[i] <= 'Z' || '0' <= a[i] <= '9')
            {
                this->addElements(a[i]);
            }
        }
    }
    Node()
    {
        val = '\0';
        next = nullptr;
    }

    //Methods

    void addElements(char _val)
    {
        Node* temp = this;
        
        if(temp == nullptr)
        {
            temp = new Node();
            temp->val = _val;
            temp->next = nullptr;
            return;
        }
        
        if(temp->next == nullptr)
        {
            Node* newNode = new Node();
            newNode->val = _val;
            newNode->next = nullptr;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
        temp->addElements(_val);
        temp->~Node();
    }

    void printElements()
    {
        Node* temp = this;
        if(temp == nullptr || temp->val == '\0')
        {
            return;
        }
        if(temp->next == nullptr || temp->next->val == '\0')
        {
            std::cout << temp->val;
            return;
        }

        std::cout << temp->val;
        temp->next->printElements();
        temp->~Node();
    }

    Node* reverseList()
    {
        if(this->next == nullptr)
        {
            return this;
        }

        Node* temp = this->next->reverseList();
        this->next->next = this;
        Node* previous = nullptr;
        this->next = previous;
        previous->~Node();
        return temp;
    }
    
};



int main()
{
    std::string a;
    std::getline(std::cin, a);

    Node* head = new Node(a);
    Node* reversed = head->reverseList();
    head->~Node();
    reversed->printElements();

    return 0;
}