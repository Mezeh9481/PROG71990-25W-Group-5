#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task_list.h"

// Initialize the task list
void initTaskList(TaskList* list) {
    list->count = 0;
}

// Add a new task
void addTask(TaskList* list) {
    if (list->count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter task name: ");
    fgets(list->tasks[list->count].name, MAX_NAME_LENGTH, stdin);
    list->tasks[list->count].name[strcspn(list->tasks[list->count].name, "\n")] = '\0'; // Remove newline

    list->tasks[list->count].id = list->count + 1;
    list->count++;
    printf("Task added successfully!\n");
}

// Delete a task by ID
void deleteTask(TaskList* list) {
    int id, i;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            for (int j = i; j < list->count - 1; j++) {
                list->tasks[j] = list->tasks[j + 1];
            }
            list->count--;
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task not found!\n");
}

// Update an existing task
void updateTask(TaskList* list) {
    int id;
    printf("Enter task ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            printf("Enter new task name: ");
            fgets(list->tasks[i].name, MAX_NAME_LENGTH, stdin);
            list->tasks[i].name[strcspn(list->tasks[i].name, "\n")] = '\0'; // Remove newline
            printf("Task updated successfully!\n");
            return;
        }
    }
    printf("Task not found!\n");
}

// View all tasks
void viewTasks(TaskList* list) {
    if (list->count == 0) {
        printf("No tasks available!\n");
        return;
    }
    printf("\nTask List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", list->tasks[i].id, list->tasks[i].name);
    }
}
