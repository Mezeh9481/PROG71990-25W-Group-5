#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task_list.h"

// Function to display the menu
void displayMenu();

// Function to handle user choices
void handleUserChoice();

// Function for searching tasks
void searchTask(TaskList* list);

void saveTasksToFile(TaskList* list, const char* filename);

void loadTasksToFile(TaskList* list, const char* filename);

#endif
