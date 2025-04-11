// PROG71990-25W - Section1 Group5 - GroupAssignment
// Author: Austin, Mario
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task_list.h"

// Initialize the task list by restting the task count
void initTaskList(TaskList* list) {
    list->count = 0;
}

// Add a new task to the list
void addTask(TaskList* list) {
    if (list->count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter task name: ");
    fgets(list->tasks[list->count].name, MAX_NAME_LENGTH, stdin);
    list->tasks[list->count].name[strcspn(list->tasks[list->count].name, "\n")] = '\0'; // Remove newline

    printf("Enter category (e.g., work, personal): ");
    fgets(list->tasks[list->count].category, MAX_CATEGORY_LENGTH, stdin);
    list->tasks[list->count].category[strcspn(list->tasks[list->count].category, "\n")] = '\0';

    list->tasks[list->count].completed = 0;
    list->tasks[list->count].id = list->count + 1;
    list->count++;
    printf("Task added successfully!\n");
}

//Function to mark tasks as complete
void markTaskAsComplete(TaskList* list) {
    int id;
    printf("Enter task ID to mark as complete:");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            list->tasks[i].completed = 1;
            printf("Task marked as complete.\n");
            return;
        }
    }
    printf("Task not found.\n");
}

// Delete a task from the list by its ID
void deleteTask(TaskList* list) {
    // Shows current tasks before prompting
    printf("Current tasks:\n");
    for (int i = 0; i < list->count; i++) {
        printf("ID: %d, Name: %s\n", list->tasks[i].id, list->tasks[i].name);
    }
    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            for (int j = i; j < list->count - 1; j++) {
                list->tasks[j] = list->tasks[j + 1];
            }
            list->count--;
            // Re-index IDs to keep them sequential
            for (int k = 0; k < list->count; k++) {
                list->tasks[k].id = k + 1;
            }
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task not found!\n");
}

// Update the name of an existing task
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
// Searches tasks by their name or ID
void searchTask(TaskList* list) {
    if (list->count == 0) {
        printf("No tasks available to search!\n");
        return;
    }
    char searchTerm[MAX_NAME_LENGTH];
    printf("Enter task name or ID to search: ");
    fgets(searchTerm, MAX_NAME_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Removes newline character
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if(_stricmp(list->tasks[i].name, searchTerm) == 0 || atoi(searchTerm) == list->tasks[i].id) {
            printf("Task found: ID %d, Name: %s\n", list->tasks[i].id, list->tasks[i].name);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Task not found\n");
    }
}

// Saves Tasks to file
void saveTasksToFile(TaskList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%d,%s,%s,%d\n",
            list->tasks[i].id,
            list->tasks[i].name,
            list->tasks[i].category,
            list->tasks[i].completed);
    }
    fclose(file);
    printf("Task saved\n");
}

// Function to load tasks from a file into task list structure
void loadTasksFromFile(TaskList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("No Previous task data found. Starting fresh. \n");
        return;
    }
    list->count = 0;
    while (fscanf(file, "%d,%99[^,],%49[^,],%d\n",
        &list->tasks[list->count].id,
        list->tasks[list->count].name,
        list->tasks[list->count].category,
        &list->tasks[list->count].completed) == 4) { 
        list->count++;
        if (list->count >= MAX_TASKS) {
            printf("Task list full while loading from file.\n");
            break;
        }
    }
    fclose(file);
            for (int i = 0; i < list->count; i++) {
                list->tasks[i].id = i + 1;
            }
            printf("Tasks loaded and re-indexed succesfully!\n");
        }