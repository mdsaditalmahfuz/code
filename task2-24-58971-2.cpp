#include <iostream>
#include <queue>
#include <string>

// Patient class to store patient information
class Patient {
public:
    std::string name;
    std::string id;
    std::string disease;

    Patient(std::string pName, std::string pId, std::string pDisease) {
        name = pName;
        id = pId;
        disease = pDisease;
    }

    void displayPatientDetails() const {
        std::cout << "    Name: " << name << std::endl;
        std::cout << "    ID: " << id << std::endl;
        std::cout << "    Disease: " << disease << std::endl;
    }
};

// Hospital registration system using queue
class HospitalRegistrationSystem {
private:
    std::queue<Patient> patientQueue;
    std::string myName;

public:
    // Constructor to reject a specific name
    HospitalRegistrationSystem(std::string rejectName) : myName(rejectName) {}

    // Add a new patient to the queue
    void addPatient(const std::string& name, const std::string& id, const std::string& disease) {
        if (name == myName) {
            std::cout << "\nError: Patient with the name '" << name << "' cannot be added. This name is reserved/rejected.\n";
            return;
        }

        if (name.empty() || id.empty() || disease.empty()) {
            std::cout << "\nError: All fields must be filled.\n";
            return;
        }

        patientQueue.push(Patient(name, id, disease));
        std::cout << "\nPatient '" << name << "' added to the waiting list successfully.\n";
    }

    // Search for patients by disease
    void searchPatientByDisease(const std::string& searchDisease) const {
        if (patientQueue.empty()) {
            std::cout << "\nNo patients in the waiting list to search.\n";
            return;
        }

        std::cout << "\n--- Patients with Disease: " << searchDisease << " ---\n";

        std::queue<Patient> tempQueue = patientQueue;
        int patientsFound = 0;

        while (!tempQueue.empty()) {
            Patient currentPatient = tempQueue.front();

            if (currentPatient.disease == searchDisease) {
                currentPatient.displayPatientDetails();
                std::cout << "--------------------\n";
                patientsFound++;
            }

            tempQueue.pop();
        }

        if (patientsFound == 0) {
            std::cout << "No patients found with the disease: " << searchDisease << ".\n";
        }
    }

    // View all patients currently in the queue
    void viewAllPatients() const {
        if (patientQueue.empty()) {
            std::cout << "\nNo patients currently waiting in the queue.\n";
            return;
        }

        std::cout << "\n--- All Patients Currently in Queue ---\n";

        std::queue<Patient> tempQueue = patientQueue;
        int patientCount = 1;

        while (!tempQueue.empty()) {
            std::cout << "Patient " << patientCount++ << ":\n";
            tempQueue.front().displayPatientDetails();
            std::cout << "--------------------\n";
            tempQueue.pop();
        }
    }
};

// Main function to test the system
int main() {
    // Create the hospital registration system and reject name "RejectedName"
    HospitalRegistrationSystem hospital("RejectedName");

    // Add some patients
    hospital.addPatient("karim", "ID001", "Flu");
    hospital.addPatient("Rahim", "ID002", "Cold");
    hospital.addPatient("Sobuj", "ID003", "Flu");
    hospital.addPatient("RejectedName", "ID999", "sadit");  // Should be rejected

    // View all patients
    hospital.viewAllPatients();

    // Search for a specific disease
    hospital.searchPatientByDisease("Flu");

    return 0;
}

