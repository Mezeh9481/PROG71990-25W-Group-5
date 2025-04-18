// PROG71990-25W - Section1 Group5 - GroupAssignment
// Author: Austin
// Co-author: Mario
#pragma once
#define MAX_TASKS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

// Task structure
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int completed;
} Task;

// Task List structure
typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskList;

// Function prototypes
void initTaskList(TaskList* list);
int isEmpty(const char* str);
void addTask(TaskList* list);
void deleteTask(TaskList* list);
void updateTask(TaskList* list);
void markTaskAsComplete(TaskList* list);