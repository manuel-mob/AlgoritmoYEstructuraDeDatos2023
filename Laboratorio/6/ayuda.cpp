#include <iostream>
#include <string>
using namespace std;



//Estructuras
struct Node {
    int data;
    Node* next;
};

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
    newNode->data = 42;

    return 0;
}