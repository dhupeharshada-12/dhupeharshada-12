#include <stdio.h>
#include <string.h>

#define MAX_VEHICLES 100

struct Vehicle {
    int vehicleID;
    char ownerName[50];
    char vehicleNumber[20];
    char serviceType[50];
    int serviceInterval;
    int daysSinceService;
    float serviceCost;
};

struct Vehicle vehicles[MAX_VEHICLES];
int totalVehicles = 0;

void addVehicle() {
    if (totalVehicles >= MAX_VEHICLES) {
        printf("\nRecord limit reached!\n");
        return;
    }

    struct Vehicle v;

    printf("\nEnter Vehicle ID: ");
    scanf("%d", &v.vehicleID);

    for (int i = 0; i < totalVehicles; i++) {
        if (vehicles[i].vehicleID == v.vehicleID) {
            printf("Vehicle ID already exists!\n");
            return;
        }
    }

    printf("Enter Owner Name: ");
    scanf(" %49[^\n]", v.ownerName);

    printf("Enter Vehicle Number: ");
    scanf(" %19s", v.vehicleNumber);

    printf("Enter Service Type: ");
    scanf(" %49[^\n]", v.serviceType);

    printf("Enter Service Interval (days): ");
    scanf("%d", &v.serviceInterval);

    if (v.serviceInterval <= 0) {
        printf("Invalid service interval!\n");
        return;
    }

    printf("Enter Days Since Last Service: ");
    scanf("%d", &v.daysSinceService);

    if (v.daysSinceService < 0) {
        printf("Invalid number of days!\n");
        return;
    }

    printf("Enter Service Cost: ");
    scanf("%f", &v.serviceCost);

    if (v.serviceCost < 0) {
        printf("Invalid service cost!\n");
        return;
    }

    vehicles[totalVehicles++] = v;

    printf("\nVehicle service record added successfully!\n");
}

void displayVehicles() {
    if (totalVehicles == 0) {
        printf("\nNo vehicle records available.\n");
        return;
    }

    printf("\n========== VEHICLE SERVICE RECORDS ==========\n");

    for (int i = 0; i < totalVehicles; i++) {
        printf("\nVehicle ID: %d", vehicles[i].vehicleID);
        printf("\nOwner: %s", vehicles[i].ownerName);
        printf("\nVehicle Number: %s", vehicles[i].vehicleNumber);
        printf("\nService Type: %s", vehicles[i].serviceType);
        printf("\nService Interval: %d days",
               vehicles[i].serviceInterval);
        printf("\nDays Since Service: %d",
               vehicles[i].daysSinceService);
        printf("\nService Cost: %.2f", vehicles[i].serviceCost);

        if (vehicles[i].daysSinceService >=
            vehicles[i].serviceInterval) {
            printf("\nStatus: Service Due");
        } else {
            printf("\nStatus: Service Not Due");
        }

        printf("\n---------------------------------------------\n");
    }
}

void searchVehicle() {
    int id;

    printf("\nEnter Vehicle ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < totalVehicles; i++) {
        if (vehicles[i].vehicleID == id) {
            printf("\nVehicle Found!");
            printf("\nOwner: %s", vehicles[i].ownerName);
            printf("\nVehicle Number: %s",
                   vehicles[i].vehicleNumber);
            printf("\nService Type: %s\n",
                   vehicles[i].serviceType);
            return;
        }
    }

    printf("\nVehicle not found!\n");
}

void updateService() {
    int id;

    printf("\nEnter Vehicle ID: ");
    scanf("%d", &id);

    for (int i = 0; i < totalVehicles; i++) {
        if (vehicles[i].vehicleID == id) {
            printf("Enter New Service Type: ");
            scanf(" %49[^\n]", vehicles[i].serviceType);

            printf("Enter New Service Cost: ");
            scanf("%f", &vehicles[i].serviceCost);

            if (vehicles[i].serviceCost < 0) {
                printf("Invalid cost!\n");
                return;
            }

            vehicles[i].daysSinceService = 0;

            printf("\nService record updated successfully!\n");
            return;
        }
    }

    printf("\nVehicle not found!\n");
}

void showServiceSummary() {
    int due = 0;
    int notDue = 0;
    float totalCost = 0;

    for (int i = 0; i < totalVehicles; i++) {
        totalCost += vehicles[i].serviceCost;

        if (vehicles[i].daysSinceService >=
            vehicles[i].serviceInterval) {
            due++;
        } else {
            notDue++;
        }
    }

    printf("\n====== SERVICE SUMMARY ======\n");
    printf("Total Vehicles: %d\n", totalVehicles);
    printf("Service Due: %d\n", due);
    printf("Service Not Due: %d\n", notDue);
    printf("Total Recorded Service Cost: %.2f\n", totalCost);
}

int main() {
    int choice;

    do {
        printf("\n====== SMART VEHICLE SERVICE MANAGER ======\n");
        printf("1. Add Vehicle Record\n");
        printf("2. Display All Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Update Service Record\n");
        printf("5. View Service Summary\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVehicle();
                break;

            case 2:
                displayVehicles();
                break;

            case 3:
                searchVehicle();
                break;

            case 4:
                updateService();
                break;

            case 5:
                showServiceSummary();
                break;

            case 6:
                printf("\nThank you for using Vehicle Service Manager!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
