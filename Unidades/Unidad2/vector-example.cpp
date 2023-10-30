#include <iostream>
#include <vector>

struct Patient {
    std::string Name;
    int Room;
    int Age;
};

Patient CreatePatient(const std::string& name, int room, int age) {
    Patient patient;
    patient.Name = name;
    patient.Room = room;
    patient.Age = age;
    return patient;
}

void AddPatient(std::vector<Patient>& patients, Patient newPatient) {
    patients.push_back(newPatient);
}

void PrintPatientList(const std::vector<Patient>& patients) {
    std::cout << "Patient List:\n";
    for (const Patient& patient : patients) {
        std::cout << "Name: " << patient.Name << ", Room: " << patient.Room << ", Age: " << patient.Age << "\n";
    }
}

int main() {
    std::vector<Patient> patients;

    // Adding patients to the list
    AddPatient(patients, CreatePatient("John Doe", 101, 35));
    AddPatient(patients, CreatePatient("Jane Smith", 102, 45));
    AddPatient(patients, CreatePatient("Mike Johnson", 103, 28));

    // Printing the patient list
    PrintPatientList(patients);

    return 0;
}
