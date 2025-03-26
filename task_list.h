#ifndef TASK_LIST_H
#define TASK_LIST_H

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 50

// Task structure
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Task;

// Task List structure
typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskList;

// Function prototypes
void initTaskList(TaskList* list);
void addTask(TaskList* list);
void deleteTask(TaskList* list);
void updateTask(TaskList* list);
void viewTasks(TaskList* list);

#endif
