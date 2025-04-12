# PROG71990-25F - Section1 Group5 - Group Assignment

Division of Labour

AUSTIN FOCUS:
- Adding a new task
- Deleting an existing task
- Updating an existing task

MAX FOCUS:
- Displaying a single task
- Displaying range for task
- Displaying all tasks

MARIO FOCUS:
- Searching for a task
- Saving accumulated data to file
- Loading accumulated data from disk

TESTS:

Test Case 1: Add a Task

Input:

1  
Homework
School

Expected Result:
Task “Homework” in category “School” is added and assigned ID 1. Message: “Task added successfully!”

Pass: Yes

Test Case 2: Display All Tasks

Input:
6

Expected Result:
List of all tasks appears showing ID, Name, Category, and Status.

Pass: Yes

Test Case 3: Mark Task as Complete

Input:
9  
1

Expected Result:
Task with ID 1 is marked as complete. Message: “Task marked as complete.”

Pass: Yes

Test Case 4: Display Single Task by ID

Input:
4  
1

Expected Result:
Task with ID 1 is displayed with full details.

Pass: Yes

Test Case 5: Display Range of Tasks

Input:
5  
1  
1

Expected Result:
Task with ID 1 is shown (since start and end are both 1).

Pass: Yes

Test Case 6: Update a Task

Input:
3  
1  
Finish Homework

Expected Result:
Task with ID 1 name is changed to “Finish Homework.” Message: “Task updated successfully!”

Pass: Yes

Test Case 7: Delete a Task

Input:
2  
1

Expected Result:
Task with ID 1 is removed. Remaining tasks are re-indexed. Message: “Task deleted successfully!”

Pass: Yes

Test Case 8: Search Task by Name

Input:
7  
Finish Homework

Expected Result:
Program finds and displays the task. Message: “Task found: ID X, Name: Finish Homework”

Pass: Yes

Test Case 9: Add Multiple Tasks and Display

Input:
1  
Call Mom  
Personal  
1  
Grocery Shopping  
Errands  
6

Expected Result:
Both tasks are added. Display shows both with IDs 1 and 2.

Pass: Yes

Test Case 10: Enter Invalid Menu Option

Input:
15

Expected Result:
Message: “Invalid choice, please try again.”

Pass: Yes
