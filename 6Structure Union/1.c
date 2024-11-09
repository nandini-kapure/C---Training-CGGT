// 1. Program to manage a list of employees for a company where each employee record includes personal details, job information, and payroll data. Use structs to manage employee records. Include fields for personal information (name, ID, address), job details (position, department), and compensation. Define a union to handle different types of compensation, such as hourly wages, salaries, or commission-based pay. Allow adding, updating, and querying and filtering employee records on various criteria, and handle compensation calculations based on the type of compensation. Include functionality for generating payroll reports, department-wise breakdowns, and employee lists.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define MAX_DEPARTMENTS 5
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_POSITION_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 20

typedef union {
    float hourly_wage;
    float salary;
    float commission_rate;  
} Compensation;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    char address[MAX_ADDRESS_LENGTH];
    char position[MAX_POSITION_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    Compensation compensation;
    char compensation_type;
    float hours_worked; 
    float sales_made;   
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Max limit reached.\n");
        return;
    }

    Employee new_employee;
    
    printf("Enter employee name: ");
    fgets(new_employee.name, MAX_NAME_LENGTH, stdin);
    new_employee.name[strcspn(new_employee.name, "\n")] = '\0';  
    
    printf("Enter employee ID: ");
    scanf("%d", &new_employee.id);
    getchar(); 
    
    printf("Enter employee address: ");
    fgets(new_employee.address, MAX_ADDRESS_LENGTH, stdin);
    new_employee.address[strcspn(new_employee.address, "\n")] = '\0';  
    
    printf("Enter position: ");
    fgets(new_employee.position, MAX_POSITION_LENGTH, stdin);
    new_employee.position[strcspn(new_employee.position, "\n")] = '\0';  
    
    printf("Enter department: ");
    fgets(new_employee.department, MAX_DEPARTMENT_LENGTH, stdin);
    new_employee.department[strcspn(new_employee.department, "\n")] = '\0';  

    printf("Enter compensation type (H - Hourly, S - Salary, C - Commission): ");
    scanf(" %c", &new_employee.compensation_type);
    getchar();  // Consume leftover newline character
    
    switch (new_employee.compensation_type) {
        case 'H':
            printf("Enter hourly wage: ");
            scanf("%f", &new_employee.compensation.hourly_wage);
            printf("Enter hours worked: ");
            scanf("%f", &new_employee.hours_worked);
            break;
        case 'S':
            printf("Enter salary: ");
            scanf("%f", &new_employee.compensation.salary);
            break;
        case 'C':
            printf("Enter commission rate (in percentage): ");
            scanf("%f", &new_employee.compensation.commission_rate);
            printf("Enter total sales made: ");
            scanf("%f", &new_employee.sales_made);
            break;
        default:
            printf("Invalid compensation type. Employee not added.\n");
            return;
    }
    
    employees[employee_count++] = new_employee;
    printf("Employee added successfully.\n");
}

void update_employee() {
    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    getchar();  
    
    int found = 0;
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            found = 1;
            printf("Updating information for %s (ID: %d)\n", employees[i].name, employees[i].id);

            printf("Enter new position: ");
            fgets(employees[i].position, MAX_POSITION_LENGTH, stdin);
            employees[i].position[strcspn(employees[i].position, "\n")] = '\0';
            
            printf("Enter new department: ");
            fgets(employees[i].department, MAX_DEPARTMENT_LENGTH, stdin);
            employees[i].department[strcspn(employees[i].department, "\n")] = '\0';
            
            printf("Enter new compensation type (H - Hourly, S - Salary, C - Commission): ");
            scanf(" %c", &employees[i].compensation_type);
            getchar();  // Consume leftover newline character

            switch (employees[i].compensation_type) {
                case 'H':
                    printf("Enter new hourly wage: ");
                    scanf("%f", &employees[i].compensation.hourly_wage);
                    printf("Enter new hours worked: ");
                    scanf("%f", &employees[i].hours_worked);
                    break;
                case 'S':
                    printf("Enter new salary: ");
                    scanf("%f", &employees[i].compensation.salary);
                    break;
                case 'C':
                    printf("Enter new commission rate (in percentage): ");
                    scanf("%f", &employees[i].compensation.commission_rate);
                    printf("Enter new total sales made: ");
                    scanf("%f", &employees[i].sales_made);
                    break;
                default:
                    printf("Invalid compensation type.\n");
                    return;
            }
            printf("Employee information updated.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

float calculate_pay(Employee employee) {
    switch (employee.compensation_type) {
        case 'H':
            return employee.compensation.hourly_wage * employee.hours_worked;
        case 'S':
            return employee.compensation.salary;
        case 'C':
            return (employee.compensation.commission_rate / 100) * employee.sales_made;
        default:
            return 0;
    }
}

void generate_payroll_report() {
    printf("\nPayroll Report:\n");
    for (int i = 0; i < employee_count; i++) {
        float pay = calculate_pay(employees[i]);
        printf("Employee: %s, ID: %d, Pay: $%.2f\n", employees[i].name, employees[i].id, pay);
    }
}

void filter_by_department() {
    char department[MAX_DEPARTMENT_LENGTH];
    printf("Enter department to filter by: ");
    getchar(); 
    fgets(department, MAX_DEPARTMENT_LENGTH, stdin);
    department[strcspn(department, "\n")] = '\0';  

    printf("\nEmployees in Department '%s':\n", department);
    for (int i = 0; i < employee_count; i++) {
        if (strcmp(employees[i].department, department) == 0) {
            printf("Employee: %s, ID: %d, Position: %s\n", employees[i].name, employees[i].id, employees[i].position);
        }
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Update Employee\n");
        printf("3. Generate Payroll Report\n");
        printf("4. Filter Employees by Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                update_employee();
                break;
            case 3:
                generate_payroll_report();
                break;
            case 4:
                filter_by_department();
                break;
            case 5:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}
