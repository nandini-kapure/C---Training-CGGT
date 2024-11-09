// 3. Program to manage various types of vehicles, each with different attributes and maintenance requirements. Use structs to define vehicle records (vehicle ID, type, and maintenance information) and unions to handle vehicle-specific attributes (e.g., fuel type for cars, cargo capacity for trucks). Track maintenance schedules and history for each vehicle. Implement functions to add new vehicles, update vehicle details, and schedule maintenance. Create reports for maintenance schedules, fleet utilization, and vehicle performance. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_VEHICLES 100
#define MAX_MAINTENANCE_DESC_LENGTH 100
#define MAX_VEHICLE_TYPE_LENGTH 20

// Define union to store vehicle-specific attributes
typedef union {
    char fuel_type[20];      // Fuel type for cars
    float cargo_capacity;     // Cargo capacity for trucks (in tons)
    int engine_cc;            // Engine displacement for bikes (in cc)
} VehicleAttributes;

// Define struct to handle maintenance information
typedef struct {
    char schedule_date[11];               // Maintenance date in format "YYYY-MM-DD"
    char description[MAX_MAINTENANCE_DESC_LENGTH]; // Maintenance description
} MaintenanceRecord;

// Define struct to store vehicle information
typedef struct {
    int vehicle_id;
    char vehicle_type[MAX_VEHICLE_TYPE_LENGTH]; // "Car", "Truck", "Bike"
    VehicleAttributes attributes;
    MaintenanceRecord maintenance;
    char last_maintenance_date[11];
} Vehicle;

// Array to store fleet of vehicles
Vehicle *fleet = NULL;
int fleet_size = 0;
int max_fleet_size = 10;

// Function to add a new vehicle to the fleet
void add_vehicle() {
    if (fleet_size >= max_fleet_size) {
        max_fleet_size *= 2;
        fleet = realloc(fleet, max_fleet_size * sizeof(Vehicle));
    }

    Vehicle new_vehicle;
    
    printf("Enter vehicle ID: ");
    scanf("%d", &new_vehicle.vehicle_id);
    getchar(); // Consume newline character

    printf("Enter vehicle type (Car/Truck/Bike): ");
    fgets(new_vehicle.vehicle_type, MAX_VEHICLE_TYPE_LENGTH, stdin);
    new_vehicle.vehicle_type[strcspn(new_vehicle.vehicle_type, "\n")] = '\0';

    if (strcmp(new_vehicle.vehicle_type, "Car") == 0) {
        printf("Enter fuel type (Petrol/Diesel/Electric): ");
        fgets(new_vehicle.attributes.fuel_type, sizeof(new_vehicle.attributes.fuel_type), stdin);
        new_vehicle.attributes.fuel_type[strcspn(new_vehicle.attributes.fuel_type, "\n")] = '\0';
    } 
    else if (strcmp(new_vehicle.vehicle_type, "Truck") == 0) {
        printf("Enter cargo capacity in tons: ");
        scanf("%f", &new_vehicle.attributes.cargo_capacity);
    } 
    else if (strcmp(new_vehicle.vehicle_type, "Bike") == 0) {
        printf("Enter engine displacement (cc): ");
        scanf("%d", &new_vehicle.attributes.engine_cc);
    } 
    else {
        printf("Invalid vehicle type!\n");
        return;
    }

    printf("Enter maintenance schedule date (YYYY-MM-DD): ");
    getchar(); // Consume newline character
    fgets(new_vehicle.maintenance.schedule_date, sizeof(new_vehicle.maintenance.schedule_date), stdin);
    new_vehicle.maintenance.schedule_date[strcspn(new_vehicle.maintenance.schedule_date, "\n")] = '\0';

    printf("Enter maintenance description: ");
    fgets(new_vehicle.maintenance.description, sizeof(new_vehicle.maintenance.description), stdin);
    new_vehicle.maintenance.description[strcspn(new_vehicle.maintenance.description, "\n")] = '\0';

    strcpy(new_vehicle.last_maintenance_date, "Not yet maintained");

    fleet[fleet_size++] = new_vehicle;
    printf("Vehicle added successfully.\n");
}

// Function to update a vehicle's details
void update_vehicle() {
    int vehicle_id;
    printf("Enter vehicle ID to update: ");
    scanf("%d", &vehicle_id);

    int found = 0;
    for (int i = 0; i < fleet_size; i++) {
        if (fleet[i].vehicle_id == vehicle_id) {
            found = 1;
            printf("Updating details for Vehicle ID %d (%s)\n", fleet[i].vehicle_id, fleet[i].vehicle_type);

            printf("Enter new maintenance schedule date (YYYY-MM-DD): ");
            getchar(); // Consume newline character
            fgets(fleet[i].maintenance.schedule_date, sizeof(fleet[i].maintenance.schedule_date), stdin);
            fleet[i].maintenance.schedule_date[strcspn(fleet[i].maintenance.schedule_date, "\n")] = '\0';

            printf("Enter new maintenance description: ");
            fgets(fleet[i].maintenance.description, sizeof(fleet[i].maintenance.description), stdin);
            fleet[i].maintenance.description[strcspn(fleet[i].maintenance.description, "\n")] = '\0';

            printf("Enter last maintenance date (YYYY-MM-DD): ");
            fgets(fleet[i].last_maintenance_date, sizeof(fleet[i].last_maintenance_date), stdin);
            fleet[i].last_maintenance_date[strcspn(fleet[i].last_maintenance_date, "\n")] = '\0';

            printf("Vehicle details updated.\n");
            break;
        }
    }

    if (!found) {
        printf("Vehicle with ID %d not found.\n", vehicle_id);
    }
}

// Function to display maintenance schedule for all vehicles
void display_maintenance_schedule() {
    printf("\nMaintenance Schedule:\n");
    for (int i = 0; i < fleet_size; i++) {
        printf("Vehicle ID: %d, Type: %s\n", fleet[i].vehicle_id, fleet[i].vehicle_type);
        printf("Scheduled Maintenance Date: %s\n", fleet[i].maintenance.schedule_date);
        printf("Maintenance Description: %s\n", fleet[i].maintenance.description);
        printf("Last Maintenance Date: %s\n\n", fleet[i].last_maintenance_date);
    }
}

// Function to generate fleet performance report
void generate_performance_report() {
    printf("\nFleet Performance Report:\n");
    for (int i = 0; i < fleet_size; i++) {
        printf("Vehicle ID: %d, Type: %s\n", fleet[i].vehicle_id, fleet[i].vehicle_type);
        if (strcmp(fleet[i].vehicle_type, "Car") == 0) {
            printf("Fuel Type: %s\n", fleet[i].attributes.fuel_type);
        } else if (strcmp(fleet[i].vehicle_type, "Truck") == 0) {
            printf("Cargo Capacity: %.2f tons\n", fleet[i].attributes.cargo_capacity);
        } else if (strcmp(fleet[i].vehicle_type, "Bike") == 0) {
            printf("Engine Displacement: %d cc\n", fleet[i].attributes.engine_cc);
        }
        printf("Last Maintenance Date: %s\n\n", fleet[i].last_maintenance_date);
    }
}

int main() {
    fleet = malloc(max_fleet_size * sizeof(Vehicle));
    int choice;

    while (1) {
        printf("\nFleet Management System\n");
        printf("1. Add Vehicle\n");
        printf("2. Update Vehicle\n");
        printf("3. Display Maintenance Schedule\n");
        printf("4. Generate Performance Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_vehicle(); break;
            case 2: update_vehicle(); break;
            case 3: display_maintenance_schedule(); break;
            case 4: generate_performance_report(); break;
            case 5: 
                printf("Exiting system.\n");
                free(fleet);
                return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
