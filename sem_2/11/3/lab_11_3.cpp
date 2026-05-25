#include <iostream>
#include <cstdarg>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node * next = nullptr;
};

struct Stack {
    Node * top = nullptr;
    unsigned int size;
}; 


Stack * init(int size, ...) {
    if (size <= 0) {
        cout << "Error! Size < 0!" << endl;
        return nullptr;
    }
    else {
        va_list args;
        va_start(args, size);

        Stack * stack = new Stack;
        stack->size = size;
        
        Node * prev_node = new Node;
        stack->top = prev_node;
        prev_node->data = va_arg(args, int);

        for (int i = 0; i < size - 1; i++) {
            Node * node = new Node;
            node->data = va_arg(args, int);

            prev_node->next = node;
            prev_node = node;
        }
        va_end(args);
        return stack;
    }
}

void push(Stack * stack, int data) {
    Node * new_node = new Node;
    new_node->data = data;

    new_node->next = stack->top;
    stack->top = new_node;
    
    stack->size++;
}

int pop(Stack * stack) {
    if (stack->size == 0) {
        cout << "Stack is empty, nothing is pop" << endl;
        return 0;
    }
    else {
        int data;
        Node * temp = stack->top;
        data = temp->data;

        if (temp->next == nullptr) {
            delete temp;
            stack->top = nullptr;
        }
        else {
            stack->top = temp->next;
            delete temp;
        }
        stack->size--;
        return data;
    }
}

void clear(Stack * stack) {
    while(stack->size > 0) {
        pop(stack);
    }
}

void stack_print(Stack * stack) {
    Node * temp = stack->top;
    if (temp == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << "[ " << temp->data << " ]" << endl;
        cout << "  V" << endl;
        temp = temp->next;
    }
    cout << endl;
}

void write_to_file(Stack * stack, string file_name) {
    ofstream w_file(file_name);
    if (w_file.is_open()) {
        w_file << stack->size << endl;

        if (stack->size == 0) {
            cout << "Stack is empty, nothng is writed in file" << endl;
            return; 
        }
        Node * temp = stack->top;

        while (temp != nullptr) {
            w_file << temp->data << endl;
            temp = temp->next;
        }
        w_file.close();
        cout << "Stack is writed" << endl;
    }
    else {
        cout << "File is not open!" << endl;
    }
}

Stack * restore_from_file(string file_name) {
    ifstream r_file(file_name);

    if (r_file.is_open()) {
        Stack * stack = new Stack;
        r_file >> stack->size;

        if (stack->size == 0) {
            return stack;
        }
        
        Node * prev_node = new Node;
        stack->top = prev_node;
        r_file >> prev_node->data;

        for (int i = 0; i < stack->size - 1; i++) {
            Node * node = new Node;
            r_file >> node->data;
            prev_node->next = node;
            prev_node = node;
        }
        cout << "Stack is restore" << endl;
        r_file.close();
        return stack;
    }
    else {
        cout << "File is not open!" << endl;
        return nullptr;
    }
}

int main() {
    Stack * a = init(3, 0, 1, 2);
    stack_print(a);
    
    pop(a);
    stack_print(a);

    push(a, 5);
    stack_print(a);

    write_to_file(a, "write_file.txt");

    clear(a);
    stack_print(a);

    a = restore_from_file("write_file.txt");
    stack_print(a);

    clear(a);
    stack_print(a);
    
    return 0;
}