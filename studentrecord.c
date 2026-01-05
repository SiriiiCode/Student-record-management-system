/*
Project: Student record management
Language: C
Data Structure: Linked List
Author: Siri Hegde
*/

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

/* Insert student at end */
void insertStudent() {
    struct Student *newNode, *temp;
    newNode = (struct Student *)malloc(sizeof(struct Student));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &newNode->roll);
    printf("Enter name: ");
    scanf("%s", newNode->name);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Student inserted successfully\n");
}

/* Delete student by roll number */
void deleteStudent() {
    struct Student *temp = head, *prev = NULL;
    int roll;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    if (head->roll == roll) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student deleted successfully\n");
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Student deleted successfully\n");
    }
}

/* Search student by roll number */
void searchStudent() {
    struct Student *temp = head;
    int roll;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Student Found: Roll = %d, Name = %s\n",
                   temp->roll, temp->name);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found\n");
}

/* Display all students */
void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Roll: %d | Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\n--- STUDENT RECORD MENU ---\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: deleteStudent(); break;
            case 3: searchStudent(); break;
            case 4: displayStudents(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
