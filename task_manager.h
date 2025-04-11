// PROG71990-25W - Section1 Group5 - GroupAssignment
// Author: Austin
//Co-authors: Mario
#pragma once
#include "task_list.h"

// Displays the menu options to the user
void displayMenu();

// Handles user input and executes appropriate task operations 
void handleUserChoice();

// Allows user to search for tasks by name or ID
void searchTask(TaskList* list);

// Saves the current task list to a file
void saveTasksToFile(TaskList* list, const char* filename);

// Loads tasKs from a file into the task list
void loadTasksFromFile(TaskList* list, const char* filename);
