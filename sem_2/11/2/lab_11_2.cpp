#include <iostream>
#include <cstdarg>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node * next = nullptr;
    Node * prev = nullptr;
};

struct List {
    Node * head = nullptr;
    unsigned int size;
}; 


List * init(int size, ...) {
    if (size <= 0) {
        cout << "Error! Size < 0!" << endl;
        return nullptr;
    }
    else {
        va_list args;
        va_start(args, size);

        List * list = new List;
        list->size = size;
        
        Node * prev_node = new Node;
        list->head = prev_node;
        prev_node->data = va_arg(args, int);

        for (int i = 0; i < size - 1; i++) {
            Node * cur_node = new Node;
            cur_node->data = va_arg(args, int);

            prev_node->next = cur_node;
            cur_node->prev = prev_node;

            prev_node = cur_node;
        }
        va_end(args);
        return list;
    }
}

void insert(List * list, unsigned int idx, int data) {
    if (idx < 0 || idx > list->size) {
        cout << "Elem is not inserted! idx " << idx << " is not correct!" << endl;
        return;
    }
    else {
        Node * new_node = new Node;
        new_node->data = data;

        if (idx == 0) {
            new_node->next = list->head;
            new_node->next->prev = new_node;
            list->head = new_node;
        }
        else {
            int pos = 1;
            Node * prev_node = list->head;
            Node * cur_node = prev_node->next;
            while (idx != pos) {
                prev_node = cur_node;
                cur_node = prev_node->next;
                pos++;
            }

            if (cur_node == nullptr) {
                prev_node->next = new_node;
                new_node->prev = prev_node;
            }
            else {
                prev_node->next = new_node;
                new_node->prev = prev_node;
                new_node->next = cur_node;
                cur_node->prev = new_node;
            }
        }
    }
    list->size++;
}

void del(List * list, unsigned int idx) {
    if (idx < 0 || idx >= list->size) {
        cout << "Index " << idx << " is out of list!" << endl;
        return;
    }
    if (idx == 0) {
        Node * temp = list->head;
        if (temp->next == nullptr) {
            delete temp;
            list->head = nullptr;
        }
        else {
            list->head = temp->next;
            list->head->prev = nullptr;
            delete temp;
        }
    }
    else {
        int pos = 1;
        Node * prev_node = list->head;
        Node * cur_node = prev_node->next;
        while (idx != pos) {
            prev_node = cur_node;
            cur_node = prev_node->next;
            pos++;
        }

        if (cur_node->next == nullptr) {
            prev_node->next = nullptr;
        }
        else {
            prev_node->next = cur_node->next;
            cur_node->next->prev = prev_node;
        }
        delete cur_node;
    }
    list->size--;
}

void clear(List * list) {
    while(list->size > 0) {
        del(list, 0);
    }
}

void list_print(List * list) {
    Node * temp = list->head;
    if (temp == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << " <- [ " << temp->data << " ] -> ";
        temp = temp->next;
    }
    cout << endl;
}

void write_to_file(List * list, string file_name) {
    ofstream w_file(file_name);
    if (w_file.is_open()) {
        w_file << list->size << endl;

        if (list->size == 0) {
            cout << "List is empty, nothng is writed in file" << endl;
            return; 
        }
        Node * temp = list->head;

        while (temp != nullptr) {
            w_file << temp->data << endl;
            temp = temp->next;
        }
        cout << "List is writed" << endl;
        w_file.close();
    }
    else {
        cout << "File is not open!" << endl;
    }
}

List * restore_from_file(string file_name) {
    ifstream r_file(file_name);

    if (r_file.is_open()) {
        List * list = new List;
        r_file >> list->size;

        if (list->size == 0) {
            return list;
        }
        
        Node * prev_node = new Node;
        list->head = prev_node;
        r_file >> prev_node->data;

        for (int i = 0; i < list->size - 1; i++) {
            Node * cur_node = new Node;
            r_file >> cur_node->data;
            prev_node->next = cur_node;
            cur_node->prev = prev_node;
            prev_node = cur_node;
        }
        cout << "List is restore" << endl;
        r_file.close();
        return list;
    }
    else {
        cout << "File is not open!" << endl;
        return nullptr;
    }
}

int main() {
    List * a = init(4, 0, 1, 2, 3);
    list_print(a);
    
    del(a, 2);
    list_print(a);

    insert(a, 1, -1);
    list_print(a);

    write_to_file(a, "write_file.txt");

    clear(a);
    list_print(a);

    a = restore_from_file("write_file.txt");
    list_print(a);

    clear(a);
    list_print(a);

    return 0;
}