#include <iostream>

struct Patient {
    std::string Name;
    int Room;
    int Age;
    Patient* next;
};

Patient* CreatePatient(const std::string& name, int room, int age) {
    Patient* patient = new Patient;
    patient->Name = name;
    patient->Room = room;
    patient->Age = age;
    patient->next = nullptr;
    return patient;
}

void AddPatient(Patient*& head, const std::string& name, int room, int age) {
    Patient* newPatient = CreatePatient(name, room, age);
    newPatient->next = head;
    head = newPatient;
}

void PrintPatientList(const Patient* head) {
    std::cout << "Patient List:\n";
    const Patient* current = head;
    while (current != nullptr) {
        std::cout << "Name: " << current->Name << ", Room: " << current->Room << ", Age: " << current->Age << "\n";
        current = current->next;
    }
}

void DeletePatientList(Patient* head) {
    while (head != nullptr) {
        Patient* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Patient* head = nullptr;

    // Adding patients to the linked list
    AddPatient(head, "John Doe", 101, 35);
    AddPatient(head, "Jane Smith", 102, 45);
    AddPatient(head, "Mike Johnson", 103, 28);

    // Printing the patient list
    PrintPatientList(head);

    // Clean up the linked list
    DeletePatientList(head);

    return 0;
}
