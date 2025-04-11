#ifndef DISPLAY_H
#define DISPLAY_H
#include "task_list.h"

// Function to display a single item
void displayItem(Task* task);

// Function to display a range of items
void displayRange(TaskList* list, int start, int end);

// Function to display all items
void displayAll(TaskList* list);

#endif 
