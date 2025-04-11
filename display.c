#include <stdio.h>
#include "display.h"
#include "task_list.h"

// Display a single task (task viewing)
void displayItem(Task* task) {
    if (task == NULL) {
        printf("Task not found!\n");
        return;
    }
    printf("\nTask ID: %d\n", task->id);
    printf("Task Name: %s\n", task->name);
}

// Display all tasks
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
