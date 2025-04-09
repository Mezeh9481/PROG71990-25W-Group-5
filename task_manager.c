#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task_manager.h"

void displayMenu() {
    printf("\n==== Task Manager ====\n");
    printf("1. Add New Task\n");
    printf("2. Delete Task\n");
    printf("3. Update Task\n");
    printf("4. View All Tasks\n");
    printf("5. Exit\n");
    printf("======================\n");
    printf("Enter your choice: ");
}



void handleUserChoice() {
    int choice;
    TaskList taskList;
    initTaskList(&taskList);

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
        case 1:
            addTask(&taskList);
            break;
        case 2:
            deleteTask(&taskList);
            break;
        case 3:
            updateTask(&taskList);
            break;
        case 4:
            displayAll(&taskList);  
            break;
        case 5:
            printf("Exiting Task Manager. Goodbye!\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}