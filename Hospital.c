#include <stdio.h>
#include <string.h>

#define MAX 100

// Define the patient structure
struct Patient {
    int id;
    char name[100];
    int age;
    char disease[100];
};

struct Patient patients[MAX];
int count = 0;

// Function declarations
void addPatient();
void viewPatients();
void searchPatient();

int main() {
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient Record\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void addPatient() {
    if (count >= MAX) {
        printf("Patient limit reached!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &patients[count].id);
    getchar(); // consume newline

    printf("Enter Patient Name: ");
    fgets(patients[count].name, sizeof(patients[count].name), stdin);
    patients[count].name[strcspn(patients[count].name, "\n")] = 0;

    printf("Enter Patient Age: ");
    scanf("%d", &patients[count].age);
    getchar(); // consume newline

    printf("Enter Disease: ");
    fgets(patients[count].disease, sizeof(patients[count].disease), stdin);
    patients[count].disease[strcspn(patients[count].disease, "\n")] = 0;

    count++;
    printf("Patient record added successfully!\n");
}

void viewPatients() {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- List of Patients ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nPatient ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Disease: %s\n", patients[i].disease);
    }
}

void searchPatient() {
    int id;
    int found = 0;

    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            printf("\nPatient found:\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient with ID %d not found.\n", id);
    }
}
