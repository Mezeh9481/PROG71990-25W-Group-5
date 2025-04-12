# Task Manager - Test Cases
## Core Functionality Tests
### 1. Task Management
| Test Case | Steps | Expected Result |
|--------------------|------------------------------------|--------------------------------|
| Add valid task | 1. Choose "Add New Task"<br>2. Enter "Buy milk"<br>3. Enter "personal" | Task appears in list |
| Add empty task | Try adding task with empty name | Error: "Task name cannot be empty" |
| Mark task complete | 1. Add task<br>2. Mark as complete | Task shows as completed |
### 2. File Operations
| Test Case | Steps | Expected Result |
|--------------------|------------------------------------|--------------------------------|
| Save and load | 1. Add tasks<br>2. Save<br>3. Restart program | Tasks persist |
| Load corrupt file | Create malformed tasks.txt | Error handling (no crash) |
### 3. Task Modifications
| Test Case | Steps | Expected Result |
|--------------------|------------------------------------|--------------------------------|
| Update task | 1. Add task<br>2. Update its name | Task shows new name |
| Delete task | 1. Add task<br>2. Delete it | Task removed from list |
## Edge Cases
| Test Case | Steps | Expected Result |
|--------------------|------------------------------------|--------------------------------|
| Max tasks | Add until list is full | Error: "Task list is full" |
| Invalid ID | Try to update/delete ID=999 | Error: "Task not found" |
## User Interface
| Test Case | Steps | Expected Result |
|--------------------|------------------------------------|--------------------------------|
| Invalid menu input | Enter "11" at main menu | Error: "Invalid choice" |
| Empty list display | Display all with no tasks | Message: "No tasks available" |
