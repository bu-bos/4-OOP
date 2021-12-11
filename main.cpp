#include <iostream>
using namespace std;
struct Node{
    int value;
    Node *next;
};

class Stack {
private:
    Node *head;
public:
    Stack() {
        head = nullptr;
    }

    int pop() {
        Node *current = head;
        if (head == nullptr) {
            cout << "stack is empty";
            system("pause");
            return 1;
        } else {
            head = head->next;
            return current->value;
        }
    }

    int pop_all() {
        while (head->next != nullptr) {
            head = head->next;
        }
        cout << "first element of the stack - " << head->value << endl;
        head = nullptr;
    }


    int get_top() {
        Node *current = head;
        if (head == nullptr) {
            cout << "stack is empty";
            system("pause");
            return 1;
        } else
            return current->value;
    }

    void add_top(int a) {
        Node *current = head;
        Node *nd = new Node;
        nd->value = a;
        head = nd;
        nd->next = current;
    }


    int change(int a) {
        int tmp;
        Node *current = head;
        if (current == nullptr) {
            cout << "stack is empty";
            system("pause");
            return 1;
        } else {
            tmp = current->value;
            current->value = a;
            cout << "top element changed from " << tmp << " to " << a << endl;
        }
    }

    void print_all() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        free(current);
    }
};
//add_top(value); - добавить элемент в вершину стека
//get_top(); - получение верхнего элемента стека, возвращает верхний элемент
//pop(); - удаление верхнего элемента стека, возвращает удаленный элемент
//pop_all() - удаление всех элементов стека, выводит первый элемент стека
//change(value) - изменение верхнего элемента стека на значение "value", выводит измененный элемент
//print_all() - выводит стек
int main() {
    Stack sv;
    int count, val;
    cout << "put the number of items on the stack:";
    cin >> count;
    cout << "enter the " << count << " elements of the stack:" << endl;
    for (int i = 1; i <= count; i++) {
        cin >> val;
        sv.add_top(val);
    }

    //cout << sv.get_top() << endl;
    //cout << sv.pop() << endl;
    //sv.pop_all();
    //sv.change(12121212);
    sv.print_all();
}