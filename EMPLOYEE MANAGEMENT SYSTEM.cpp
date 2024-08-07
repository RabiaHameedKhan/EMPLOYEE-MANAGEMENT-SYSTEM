#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

// Global variables
char emp_department[100];
char emp_name[100];
char emp_designation[100];
double emp_salary;
char emp_id[100];

// Counters for each department
int hrCount = 1;
int financeCount = 1;
int salesCount = 1;
int softwareCount = 1;

// Function for department
void department() {
    if (strcmp(emp_designation, "hr") == 0 || strcmp(emp_designation, "hr manager") == 0) {
        strcpy(emp_department, "HR");
    } else if (strcmp(emp_designation, "accountant") == 0 || strcmp(emp_designation, "accountant manager") == 0) {
        strcpy(emp_department, "Finance");
    } else if (strcmp(emp_designation, "sales director") == 0 || strcmp(emp_designation, "business developer") == 0) {
        strcpy(emp_department, "Sales");
    } else if (strcmp(emp_designation, "web developer") == 0 || strcmp(emp_designation, "software developer") == 0) {
        strcpy(emp_department, "Software");
    } else {
        cout << "Enter a valid designation" << endl;
        emp_department[0] = '\0'; 
    }
}

// Function to select designation
void selectDesignation() {
    cout << "Please select your Designation:" << endl;
    cout << "\n1. HR" << endl;
    cout << "2. HR Manager" << endl;
    cout << "3. Accountant" << endl;
    cout << "4. Accountant Manager" << endl;
    cout << "5. Sales Director" << endl;
    cout << "6. Business Developer" << endl;
    cout << "7. Web Developer" << endl;
    cout << "8. Software Developer" << endl;
    cout << "\nEnter the number corresponding to your designation: ";
    int choice;
    cin >> choice;
    // To ignore the newline character after entering the number
    cin.ignore(); 

    switch (choice) {
        case 1:
            strcpy(emp_designation, "hr");
            break;
        case 2:
            strcpy(emp_designation, "hr manager");
            break;
        case 3:
            strcpy(emp_designation, "accountant");
            break;
        case 4:
            strcpy(emp_designation, "accountant manager");
            break;
        case 5:
            strcpy(emp_designation, "sales director");
            break;
        case 6:
            strcpy(emp_designation, "business developer");
            break;
        case 7:
            strcpy(emp_designation, "web developer");
            break;
        case 8:
            strcpy(emp_designation, "software developer");
            break;
        default:
            cout << "\nInvalid choice. Please enter a valid number." << endl;
            emp_designation[0] = '\0'; 
            break;
    }
}

// Function for salary
void salary() {
    if (strcmp(emp_department, "HR") == 0) {
        emp_salary = 50000;
    } else if (strcmp(emp_department, "Finance") == 0) {
        emp_salary = 60000; 
    } else if (strcmp(emp_department, "Sales") == 0) {
        emp_salary = 70000; 
    } else if (strcmp(emp_department, "Software") == 0) {
        emp_salary = 80000; 
    } else {
        emp_salary = 0; 
    }
}

// Function for converting number into string of characters
void intToString(int num, char* str) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num != 0) {
            str[i++] = '0' + (num % 10);
            num /= 10;
        }
    }
    str[i] = '\0';

    // Reversing the str characters into ascending order coutning by swapping the first and last variable
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to generate employee id with department name and ascending order counting
void generateEmployeeID(const char* department, int count, char* empID) {
    // Copy department abbreviation
    strcpy(empID, department);
    
    // Finding the length of the current empID
    int len = strlen(empID);
    
    // Adding underscore
    empID[len] = '_';
    len++;
    empID[len] = '\0';
    
    // Converting count to string
    char countStr[20]; 
    intToString(count, countStr);
    
    strcat(empID, countStr);
}

// Function to generate employee ID
void id() {
    if (strcmp(emp_department, "HR") == 0) {
        generateEmployeeID(emp_department, hrCount++, emp_id);
    } else if (strcmp(emp_department, "Finance") == 0) {
        generateEmployeeID(emp_department, financeCount++, emp_id);
    } else if (strcmp(emp_department, "Sales") == 0) {
        generateEmployeeID(emp_department, salesCount++, emp_id);
    } else if (strcmp(emp_department, "Software") == 0) {
        generateEmployeeID(emp_department, softwareCount++, emp_id);
    }
}

// Function to generate info
void information() {
    // Open the file in append mode
    FILE *fp = fopen("employee.txt", "a");
    if (fp == NULL) {
        cerr << "File could not be opened for writing." << endl;
        return;
    }

    // Write employee information to the file
    fprintf(fp, "------------------------------------\n");
    fprintf(fp, "Employee Name: %s", emp_name);
    fprintf(fp, "Employee ID: %s\n", emp_id);
    fprintf(fp, "Employee Designation: %s\n", emp_designation);
    fprintf(fp, "Employee Department: %s\n", emp_department);
    fprintf(fp, "Employee Salary: %.2f\n", emp_salary);
    fprintf(fp, "------------------------------------\n");

    // Close the file
    fclose(fp);

    //  print data to console
    cout << "------------------------------------" << endl;
    cout << "\n\nEmployee Information" << endl;
    cout << "\nEmployee Name: " << emp_name;
    cout << "Employee ID: " << emp_id << endl;
    cout << "Employee Designation: " << emp_designation << endl;
    cout << "Employee Department: " << emp_department << endl;
    cout << "Employee Salary: " << emp_salary << endl;
    cout << "------------------------------------" << endl;
}

// Main function
int main() {
    cout << "\n\t\t...................Welcome to Employee Management System!..................." << endl;
    char addAnother[10];
    
    do {
        cout << "\nPlease Enter your name: ";
        fgets(emp_name, sizeof(emp_name), stdin);
        
        selectDesignation();
        
        if (emp_designation[0] != '\0') {
            department();
            salary();
            id();
            information();
        }

        // Asking for other inputs    
        cout << "\nDo you want to add another employee? (yes/no): ";
        fgets(addAnother, sizeof(addAnother), stdin);
        addAnother[strcspn(addAnother, "\n")] = '\0'; // Remove the newline character that sometimes ocur from using fgets
    
    } while (strcmp(addAnother, "yes") == 0);

    // Displaying a thank you message
    if (strcmp(addAnother, "no") == 0) {
        cout << "\n\n.............Thank you for using the Employee management system!..............." << endl;
    }
    
    return 0;
}

