#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task_manager.h"
#include "display.h"

void displayMenu() {
    printf("\n==== Task Manager ====\n");
    printf("1. Add New Task\n");
    printf("2. Delete Task\n");
    printf("3. Update Task\n");
    printf("4. Display Single Task\n");
    printf("5. Display Task Range\n");
    printf("6. Display All Tasks\n"
    printf("7. Search Task\n");
    printf("8. Save Tasks\n");
    printf("9. Mark Task as complete\n");
    printf("10. Exit\n");
    printf("======================\n");
    printf("Enter your choice: ");
}



void handleUserChoice() {
    int choice;
    TaskList taskList;
    initTaskList(&taskList);
    loadTasksFromFile(&taskList, "tasks.txt");

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
        case 4: { // Display single task
            int id;
            printf("Enter Task ID to display: ");
            scanf("%d", &id);
            getchar();

            Task* target = NULL;
            for (int i = 0; i < taskList.count; i++) {
                if (taskList.tasks[i].id == id) {
                    target = &taskList.tasks[i];
                    break;
                }
            }
            displayItem(target);
            break;
        }
        case 5: { // Display range
            int start, end;
            printf("Enter start task number: ");
            scanf("%d", &start);
            printf("Enter end task number: ");
            scanf("%d", &end);
            getchar();

            // Adjust to 0-based internally
            displayRange(&taskList, start - 1, end - 1);
            break;
        }
        case 6: // Display all
            displayAll(&taskList);
            break;
        case 7:
            searchTask(&taskList);
            break;
        case 8:
            saveTasksToFile(&taskList, "tasks.txt");
            break;
        case 9:
            markTaskAsComplete(&taskList);
            break;
        case 10:
            printf("Exiting Task Manager. Goodbye!\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);
}
