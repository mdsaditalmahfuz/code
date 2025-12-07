#.include <iostream>
#include <cstring>
using namespace std;

// ---------------- Patient Management (Doubly Linked List) ----------------
struct Patient {
    char name[50];
    int age;
    char priority[10];
    char time[10];
    Patient* prev;
    Patient* next;
};

Patient* head = NULL;
Patient* tail = NULL;

Patient* undoStack[100];
int undoTop = -1;

void pushUndo(Patient* p) {
    undoTop = undoTop + 1;
    undoStack[undoTop] = p;
}

Patient* popUndo() {
    if (undoTop >= 0) {
        Patient* p = undoStack[undoTop];
        undoTop = undoTop - 1;
        return p;
    }
    return NULL;
}

void AddPatient(const char* name, int age, const char* priority, const char* time) {
    Patient* newPatient = new Patient;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->priority, priority);
    strcpy(newPatient->time, time);
    newPatient->prev = NULL;
    newPatient->next = NULL;

    if (head == NULL) {
        head = tail = newPatient;
    } else {
        tail->next = newPatient;
        newPatient->prev = tail;
        tail = newPatient;
    }

    pushUndo(newPatient);
    cout << "Patient " << name << " added." << endl;
}

void RemovePatient(const char* name) {
    Patient* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            if (current->prev != NULL) current->prev->next = current->next;
            if (current->next != NULL) current->next->prev = current->prev;
            delete current;
            cout << "Patient " << name << " removed." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Patient not found." << endl;
}

void UndoLastPatient() {
    Patient* last = popUndo();
    if (last != NULL) {
        RemovePatient(last->name);
        cout << "Undo Operation\nLast patient entry \"" << last->name << "\" removed." << endl;
    } else {
        cout << "No patient to undo." << endl;
    }
}

void DisplayPatients() {
    Patient* temp = head;
    while (temp != NULL) {
        cout << temp->name << ", Age: " << temp->age << ", Priority: " << temp->priority << ", Time: " << temp->time << endl;
        temp = temp->next;
    }
}

// ---------------- Doctor Allocation (BST) ----------------
struct Doctor {
    int id;
    char name[50];
    char specialization[30];
    Doctor* left;
    Doctor* right;
};

Doctor* root = NULL;

Doctor* AddDoctor(Doctor* node, int id, const char* name, const char* spec) {
    if (node == NULL) {
        Doctor* d = new Doctor;
        d->id = id;
        strcpy(d->name, name);
        strcpy(d->specialization, spec);
        d->left = NULL;
        d->right = NULL;
        cout << "Doctor Added: ID = " << id << ", Name = " << name << ", Specialization = " << spec << endl;
        return d;
    }
    if (id < node->id) {
        node->left = AddDoctor(node->left, id, name, spec);
    } else {
        node->right = AddDoctor(node->right, id, name, spec);
    }
    return node;
}

void SearchDoctorByID(Doctor* node, int id) {
    if (node == NULL) {
        cout << "Doctor not found." << endl;
        return;
    }
    if (node->id == id) {
        cout << "Doctor Found: ID = " << node->id << ", Name = " << node->name << ", Specialization = " << node->specialization << endl;
    } else if (id < node->id) {
        SearchDoctorByID(node->left, id);
    } else {
        SearchDoctorByID(node->right, id);
    }
}

void DisplayDoctorsInOrder(Doctor* node) {
    if (node != NULL) {
        DisplayDoctorsInOrder(node->left);
        cout << "ID = " << node->id << ", " << node->name << ", " << node->specialization << endl;
        DisplayDoctorsInOrder(node->right);
    }
}

// ---------------- Department Map (Adjacency List using arrays) ----------------
const int MAX_DEPTS = 10;
char departments[MAX_DEPTS][20];
int connections[MAX_DEPTS][MAX_DEPTS];
int totalDepartments = 0;

int getDeptIndex(const char* name) {
    for (int i = 0; i < totalDepartments; i++) {
        if (strcmp(departments[i], name) == 0) return i;
    }
    strcpy(departments[totalDepartments], name);
    totalDepartments++;
    return totalDepartments - 1;
}

void AddDepartmentEdge(const char* from, const char* to) {
    int fromIndex = getDeptIndex(from);
    int toIndex = getDeptIndex(to);
    connections[fromIndex][toIndex] = 1;
}

void DisplayAdjacencyList() {
    cout << "Department Connections" << endl;
    for (int i = 0; i < totalDepartments; i++) {
        cout << departments[i] << " -> ";
        for (int j = 0; j < totalDepartments; j++) {
            if (connections[i][j] == 1) {
                cout << departments[j] << ", ";
            }
        }
        cout << endl;
    }
}

// ---------------- Billing System ----------------
char postfixExpr[100][10];
int postfixSize = 0;

int getPrecedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void InfixToPostfix(const char* expr) {
    char opStack[100];
    int top = -1;
    char number[10];
    int nIndex = 0;
    postfixSize = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch >= '0' && ch <= '9') {
            number[nIndex++] = ch;
        } else {
            if (nIndex > 0) {
                number[nIndex] = '\0';
                strcpy(postfixExpr[postfixSize++], number);
                nIndex = 0;
            }
            if (ch == ' ') continue;
            if (ch == '(') opStack[++top] = ch;
            else if (ch == ')') {
                while (top >= 0 && opStack[top] != '(') {
                    char op[2] = {opStack[top--], '\0'};
                    strcpy(postfixExpr[postfixSize++], op);
                }
                top--;
            } else {
                while (top >= 0 && getPrecedence(opStack[top]) >= getPrecedence(ch)) {
                    char op[2] = {opStack[top--], '\0'};
                    strcpy(postfixExpr[postfixSize++], op);
                }
                opStack[++top] = ch;
            }
        }
    }
    if (nIndex > 0) {
        number[nIndex] = '\0';
        strcpy(postfixExpr[postfixSize++], number);
    }
    while (top >= 0) {
        char op[2] = {opStack[top--], '\0'};
        strcpy(postfixExpr[postfixSize++], op);
    }
}

int EvaluatePostfix() {
    int valStack[100];
    int top = -1;
    for (int i = 0; i < postfixSize; i++) {
        if (postfixExpr[i][0] >= '0' && postfixExpr[i][0] <= '9') {
            valStack[++top] = atoi(postfixExpr[i]);
        } else {
            int b = valStack[top--];
            int a = valStack[top--];
            char op = postfixExpr[i][0];
            if (op == '+') valStack[++top] = a + b;
            else if (op == '-') valStack[++top] = a - b;
            else if (op == '*') valStack[++top] = a * b;
            else if (op == '/') valStack[++top] = a / b;
        }
    }
    return valStack[top];
}

void CalculateBill(const char* expression) {
    cout << "Bill Expression: " << expression << endl;
    InfixToPostfix(expression);
    cout << "Postfix: ";
    for (int i = 0; i < postfixSize; i++) cout << postfixExpr[i] << " ";
    cout << endl;
    int result = EvaluatePostfix();
    cout << "Final Bill Amount: " << result << endl;
}

int main() {
    AddPatient("Nabil", 45, "High", "10:30AM");
    AddPatient("Saif", 30, "Medium", "10:35AM");
    AddPatient("Riyad", 60, "Low", "10:40AM");

    UndoLastPatient();

    root = AddDoctor(root, 102, "Dr. Sifat", "Cardiology");
    root = AddDoctor(root, 89, "Dr. Tomal", "Neurology");
    root = AddDoctor(root, 155, "Dr. Tamim", "Oncology");

    SearchDoctorByID(root, 102);
    cout << "Doctors (In-Order Traversal by ID)" << endl;
    DisplayDoctorsInOrder(root);

    AddDepartmentEdge("ICU", "Emergency");
    AddDepartmentEdge("ICU", "GeneralWard");
    AddDepartmentEdge("Emergency", "OPD");

    DisplayAdjacencyList();

    CalculateBill("(200 + 3 * 150) - 50");

    return 0;
}

