#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Guardian {
    std::string name;
    int powerLevel;
    std::string mainMaster;
    std::string village;
    std::vector<Guardian*> aprendices;
};

class GuardiansTree {
public:
    GuardiansTree() : root(nullptr) {}

    void insertGuardian(const std::string& name, const std::string& powerLevel, const std::string& mainMaster, const std::string& village) {
        Guardian* guardian = new Guardian;
        guardian->name = name;
        guardian->powerLevel = stoi(powerLevel);
        guardian->mainMaster = mainMaster;
        guardian->village = village;
        guardians.push_back(guardian);

        // If the mainMaster Guardian is found, add the guardian as an Aprendiz (apprentice)
        if (root == nullptr) {
            root = guardian;
            std::cout << "root" << std::endl;
        }
        else {
            Guardian* master = findGuardian(mainMaster);
            if(master != nullptr) {
                master->aprendices.push_back(guardian);
            }
        }
    }

    void loadGuardiansFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name, mainMaster, village;
            std::string powerLevel;
            std::getline(iss, name, ',');
            std::getline(iss, powerLevel , ',');
            std::getline(iss, mainMaster, ',');
            std::getline(iss, village);
            insertGuardian(name, powerLevel, mainMaster, village);
            
        }
        file.close();
    }

    void printGuardians() {
        printGuardian(root, 0);
    }

private:
    std::vector<Guardian*> guardians;
    Guardian* root;

    Guardian* findGuardian(const std::string& name) {
        for (Guardian* guardian : guardians) {
            if (guardian->name == name) {
                return guardian;
            }
        }
        return nullptr;
    }

    void updateTreeStructure() {
        for (Guardian* guardian : guardians) {
            if (guardian->mainMaster != "") {
                Guardian* master = findGuardian(guardian->mainMaster);
                if (master != nullptr) {
                    master->aprendices.push_back(guardian);
                }
            }
            else {
                root = guardian;
            }
        }
    }

    void printGuardian(Guardian* guardian, int indent) {
        if (guardian != nullptr) {
            std::cout << std::string(indent, ' ') << "- " << guardian->name << " (Power Level: " << guardian->powerLevel << ", Village: " << guardian->village << ")" << std::endl;
            for (Guardian* aprendiz : guardian->aprendices) {
                printGuardian(aprendiz, indent + 4);
            }
        }
    }
};

int main() {
    GuardiansTree tree;
    tree.loadGuardiansFromFile("guardians.csv");
    tree.printGuardians();
    return 0;
}
