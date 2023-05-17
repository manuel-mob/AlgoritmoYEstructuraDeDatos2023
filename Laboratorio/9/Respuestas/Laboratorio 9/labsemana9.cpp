#include <iostream>
#include <vector>

using namespace std;

class Rectangle{
	
public:
    // Constructor predeterminado
    Rectangle() : width_(0), height_(0) {}

    // Constructor
    Rectangle(float width, float height) : width_(width), height_(height) {}
    
    // Métodos públicos
    float getWidth() const { return width_; }
    float getHeight() const { return height_; }
    float getArea() const { return width_ * height_; }
    void setWidth(float width) {width_ = width;}
    void setHeight(float height) {height_ = height;}
    
private:
    // Atributos privados
    float width_;
    float height_;
};

class Point{
	
public:
    // Constructor predeterminado
    Point() : x_(0), y_(0) {}
	
    // Constructor
    Point(float x, float y) : x_(x), y_(y) {}
    
    // Métodos públicos para obtener y establecer los valores de x e y
    float getX() const { return x_; }
    float getY() const { return y_; }
    void setX(float x) { x_ = x; }
    void setY(float y) { y_ = y; }
    
    // Métodos para trabajar con polígonos
    void addVertex(Point p) { vertices_.push_back(p); }
    void clearVertices() { vertices_.clear(); }
    int getNumVertices() const { return vertices_.size(); }
    Point getVertex(int i) const { return vertices_[i]; }
    
private:
    // Atributos privados
    float x_;
    float y_;
    vector<Point> vertices_;
};

class Node{
public:
    int value;
    Node* next;
    
    Node(int val) : value(val), next(NULL) {}
    
};

class LinkedList{
private:
    Node* head;
    
public:
    LinkedList(){
        head = NULL;
    }
    
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* current = head;
            while (current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    bool search(int val){
        Node* current = head;
        while(current != NULL){
            if(current->value == val){
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    bool remove(int val){
        Node* current = head;
        Node* previous = NULL;
        
        while(current != NULL){
            if(current->value == val){
                if(previous == NULL){
                    head = current->next;
                }
                else{
                    previous->next = current->next;
                }
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }
    
    void print(){
        Node* current = head;
        while(current != NULL){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void insertNode(TreeNode* &node, int val){
        if(node == NULL){
            node = new TreeNode(val);
        }
        else if(val < node->value){
            insertNode(node->left, val);
        }
        else{
            insertNode(node->right, val);
        }
    }

    bool searchNode(TreeNode* node, int val){
        if(node == NULL) {
            return false;
        }
        else if(val == node->value){
            return true;
        }
        else if(val < node->value){
            return searchNode(node->left, val);
        }
        else{
            return searchNode(node->right, val);
        }
    }

    void printInorder(TreeNode* node){
        if(node != NULL){
            printInorder(node->left);
            cout << node->value << " ";
            printInorder(node->right);
        }
    }

public:
    BinaryTree() : root(NULL) {}

    void insert(int val) {
        insertNode(root, val);
    }

    bool search(int val) {
        return searchNode(root, val);
    }

    void print() {
        printInorder(root);
        cout << endl;
    }
};

int main(){
	
	// Ext 1
    // Crear un objeto Rectangle con ancho 10 y altura 15
    Rectangle r(10, 15);
    
    // Obtener los valores del ancho y altura
    cout << "Ancho: " << r.getWidth() << endl;
    cout << "Altura: " << r.getHeight() << endl;
    
    // Calcular y mostrar el área
    cout << "Area: " << r.getArea() << endl;
    
    cout << endl;
    
    //Ext 2
    float x, y;
    
    // Crear un objeto Point con coordenadas (7, 8)
    Point p(7, 8);
    
    // Obtener los valores de x e y
    x = p.getX();
    y = p.getY();
    cout << "Coordenadas: (" << x << ", " << y << ")" << endl;
    
    // Establecer el valor de x en 12 y el valor de y en 20
    p.setX(12);
    p.setY(20);
    x = p.getX();
    y = p.getY();
    cout << "Nuevas coordenadas: (" << x << ", " << y << ")" << endl;
    
    cout << endl;
    
    // Ext 3
    // Crear un objeto Point con coordenadas (9, 12)
    Point p1(9, 12);
    
    // Añadir vértices al polígono
    p1.addVertex(Point(10, 10));
    p1.addVertex(Point(20, 15));
    p1.addVertex(Point(15, 25));
    
    // Obtener el número de vértices y mostrarlos
    int numVertices = p1.getNumVertices();
    cout << "Numero de vertices: " << numVertices << endl;
    
    // Mostrar los vértices del polígono
    cout << "Vertices del poligono: ";
    for(int i=0; i<numVertices; i++) {
        Point v = p1.getVertex(i);
        cout << "(" << v.getX() << ", " << v.getY() << ") ";
    }
    cout << endl;
    
    // Eliminar los vértices del polígono
    p1.clearVertices();
    
    // Obtener el número de vértices y mostrarlos
    numVertices = p1.getNumVertices();
    cout << "Numero de vertices: " << numVertices << endl;
    
    cout << endl;
    
    // Ext 4
    LinkedList myList;
    
    // Insertar nodos
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    
    // Imprimir lista
    myList.print();
    
    // Buscar valor
    if (myList.search(10)) {
        cout << "Valor encontrado" << endl;
    }
    else {
        cout << "Valor no encontrado" << endl;
    }
    
    // Remover valor
    if (myList.remove(10)) {
        cout << "Valor removido" << endl;
    }
    else {
        cout << "Valor no encontrado" << endl;
    }
    
    // Imprimir lista actualizada
    myList.print();
    
    cout << endl;
    
    // Ext 5
    BinaryTree tree;
    
    // Insertar nodos al arbol
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
	
	// Imprimir recorrido el arbol en orden
    cout << "Recorrido en orden: ";
    tree.print();
	
	// Bucar valores
    cout << "Buscando 7: " << tree.search(7) << endl;
    cout << "Buscando 12: " << tree.search(12) << endl;
    
    return 0;
    
}
