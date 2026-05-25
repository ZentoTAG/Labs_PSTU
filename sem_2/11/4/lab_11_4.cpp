#include <iostream>
#include <cstdarg>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node * next = nullptr;
};

struct Queue {
    Node * head = nullptr;
    Node * tail = nullptr;
    unsigned int size;
}; 


Queue * init(int size, ...) {
    if (size <= 0) {
        cout << "Error! Size < 0!" << endl;
        return nullptr;
    }
    else {
        va_list args;
        va_start(args, size);

        Queue * queue = new Queue;
        queue->size = size;
        
        Node * prev_node = new Node;
        queue->head = prev_node;
        queue->tail = prev_node;
        prev_node->data = va_arg(args, int);

        for (int i = 0; i < size - 1; i++) {
            Node * node = new Node;
            node->data = va_arg(args, int);

            prev_node->next = node;
            prev_node = node;
        }
        queue->tail = prev_node;
        va_end(args);
        return queue;
    }
}

void push(Queue * queue, int data) {
    Node * new_node = new Node;
    Node * cur_node = queue->head;
    new_node->data = data;
    queue->tail = new_node;

    while (cur_node->next != nullptr) {
        cur_node = cur_node->next; 
    }

    cur_node->next = new_node;
    queue->size++;
}

int pop(Queue * queue) {
    if (queue->size == 0) {
        cout << "Queue is empty, nothing is pop" << endl;
        return 0;
    }
    else {
        int data;
        Node * temp = queue->head;
        data = temp->data;
        queue->head = temp->next;

        delete temp;
        queue->size--;
        return data;
    }
}

void clear(Queue * queue) {
    while(queue->size > 0) {
        pop(queue);
    }
}

void queue_print(Queue * queue) {
    Node * temp = queue->head;
    if (temp == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << "[ " << temp->data << " ]" << endl;
        cout << "  V" << endl;
        temp = temp->next;
    }
    cout << endl;
}

void write_to_file(Queue * queue, string file_name) {
    ofstream w_file(file_name);
    if (w_file.is_open()) {
        w_file << queue->size << endl;

        if (queue->size == 0) {
            cout << "Queue is empty, nothng is writed in file" << endl;
            return; 
        }
        Node * temp = queue->head;

        while (temp != nullptr) {
            w_file << temp->data << endl;
            temp = temp->next;
        }
        w_file.close();
        cout << "Queue is writed" << endl;
    }
    else {
        cout << "File is not open!" << endl;
    }
}

Queue * restore_from_file(string file_name) {
    ifstream r_file(file_name);

    if (r_file.is_open()) {
        Queue * queue = new Queue;
        r_file >> queue->size;

        if (queue->size == 0) {
            return queue;
        }
        
        Node * prev_node = new Node;
        queue->head = prev_node;
        r_file >> prev_node->data;

        for (int i = 0; i < queue->size - 1; i++) {
            Node * node = new Node;
            r_file >> node->data;
            prev_node->next = node;
            prev_node = node;
        }
        cout << "Queue is restore" << endl;
        r_file.close();
        return queue;
    }
    else {
        cout << "File is not open!" << endl;
        return nullptr;
    }
}

int main() {
    Queue * a = init(4, 0, 1, 2, 5);
    queue_print(a);
    
    pop(a);
    queue_print(a);

    push(a, 6);
    queue_print(a);

    write_to_file(a, "write_file.txt");

    clear(a);
    queue_print(a);

    a = restore_from_file("write_file.txt");
    queue_print(a);

    clear(a);
    queue_print(a);
    
    return 0;
}