#include <stdio.h>
#include "display.h"

void displayItem(Task* task) {
    if (task == NULL) {
        printf("Task not found!\n");
        return;
    }
    printf("\nTask ID: %d\n", task->id);
    printf("Task Name: %s\n", task->name);
}

void displayRange(TaskList* list, int start, int end) {
    if (start < 0 || end >= list->count || start > end) {
        printf("Invalid range.\n");
        return;
    }

    printf("\n==== Task List (Range) ====\n");
    for (int i = start; i <= end; i++) {
        printf("%d. %s\n", list->tasks[i].id, list->tasks[i].name);
    }
}

void displayAll(TaskList* list) {
    if (list->count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n==== Task List ====\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", list->tasks[i].id, list->tasks[i].name);
    }
}