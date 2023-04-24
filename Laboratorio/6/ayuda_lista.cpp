#include <iostream>
#include <string>
using namespace std;

//Estructuras
struct Node {
    int data;
    Node* next;
};

void addToList(Node* head,Node* newNode) {
    if (head == NULL){
        head = newNode;
    }
    Node* current = head;
    while (current != NULL) {
        current = current->next;
    }
    current = newNode;
}

// void printList(Node* head) {
//     Node* curr = head;
//     while (curr != NULL) {
//         cout << curr->data << " ";
//         curr = curr->next;
//     }
//     cout << endl;
// }


struct Patient {
    string name;
    int age;
    double temperature;
};


//Declaracion de funciones
int consultarValorUsuario(){
    int valorUsuario;
    cout << "Ingresar Intero: ";
    cin >> valorUsuario;
    return valorUsuario;
}

int main() {

    //Salida estandar
    cout << "output text ";
    cout << "output text new line" << endl;

    //Entrada estandar
    int valor;
    cout << "Ingresar Intero: ";
    cin >> valor;
    cout << "Valor ingresado: " << valor << endl;

    //Desde una funcion
    valor =consultarValorUsuario();
    cout << "Valor ingresado: " << valor << endl;
    
    
    //Estructura
    Patient patient;
    patient.name = "Manuel";
    patient.age = 99;
    patient.temperature = 35.5;

    cout << "Paciente:" << patient.name <<", Edad:" << patient.age << ",Temp°:" <<patient.temperature << endl;
    
    //Lista
    Node* head = NULL;
    Node* newNode = new Node;
    // Agregando nodos
    for (int i = 0; i < 5; i++) {
        newNode->data = i;
        addToList(head, newNode);
    }

    // Print out the nodes in the list
    //printList(head);

    // Delete the nodes in the list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}