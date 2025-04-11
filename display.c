#include <stdio.h>
#include "display.h"
#include "task_list.h"

// Display a single task (task viewing)
void displayItem(TaskList* list) {
    if (list->count == 0) {
        printf("No tasks available!\n");
        return;
    }
    printf("\nTask List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("ID: %d | Name: %s | Category: %s | Status: %s \n",
            list->tasks[i].id,
            list->tasks[i].name,
            list->tasks[i].category,
            list->tasks[i].completed ? "Completed" : "Incomplete");
    }
}

// Display all tasks
void displayAll(TaskList* list) {
    if (list->count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\nTask List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("ID: %d | Name: %s | Category: %s | Status: %s \n",
            list->tasks[i].id,
            list->tasks[i].name,
            list->tasks[i].category,
            list->tasks[i].completed ? "Completed" : "Incomplete");
    }
}

// Display tasks within a range
void displayRange(TaskList* list, int start, int end) {
    if (start < 0 || end >= list->count || start > end) {
        printf("Invalid range. Please enter numbers between 1 and %d.\n", list->count);
        return;
    }

    printf("\nDisplaying tasks %d to %d:\n", start + 1, end + 1); // show 1-based to user
    for (int i = start; i <= end; i++) {
        printf("%d. %s\n", list->tasks[i].id, list->tasks[i].name);
    }
}
