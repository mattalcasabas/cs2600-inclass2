// compile with "gcc employeemain.c employeetable.c employeeone.c"

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main() {
    // defined in employeeone.c or employeetwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);

    // defined in employeetable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;     // Declaration

    // example not found    
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if(matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1045 is not found in the record.\n");

    // example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is not found in the record.\n");

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    if(matchPtr != NULL)
        printf("Employee with phone number 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone number 213-555-1212 is not found in the record.\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if(matchPtr != NULL)
        printf("Employee with salary $7.80 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary $7.80 is not found in the record.\n");

    return EXIT_SUCCESS;        // found in stdlib.h

}