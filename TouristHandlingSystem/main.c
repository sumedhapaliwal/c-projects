/*
 * Name: Sumedha Paliwal (2410111058)
 * I confirm that this program is completely my own work and that
 * no part of it has been copied from anybody else or downloaded from the net.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char firstName[20], lastName[20];  // Passenger names
    int departureTime;                 // Departure time
    struct Node *next;                 // Pointer to next node
} Node;

Node *mainList = NULL, *tripList = NULL, *waitlist = NULL;
int maxCapacity, currentCount = 0;

// Add a passenger to the list in sorted order based on departure time
void addPassenger(Node **head, const char *firstName, const char *lastName, int departureTime) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        return;
    }

    strncpy(newNode->firstName, firstName, sizeof(newNode->firstName));
    strncpy(newNode->lastName, lastName, sizeof(newNode->lastName));
    newNode->departureTime = departureTime;
    newNode->next = NULL;

    Node *current = *head, *prev = NULL;

    while (current && current->departureTime < departureTime) {
        prev = current;
        current = current->next;
    }

    if (!prev) {
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

// Remove a passenger from the list
void removePassenger(Node **head, const char *firstName, const char *lastName) {
    Node *current = *head, *prev = NULL;

    while (current && (strcmp(current->firstName, firstName) != 0 || strcmp(current->lastName, lastName) != 0)) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        printf("Passenger not found.\n");
        return;
    }

    if (prev) {
        prev->next = current->next;
    } else {
        *head = current->next;
    }

    free(current);
}

// Rebuild trip and waitlist after changes
void rebuildTripAndWaitlist() {
    Node *temp;

    // Clear previous trip and waitlist
    while (tripList) {
        temp = tripList;
        tripList = tripList->next;
        free(temp);
    }

    while (waitlist) {
        temp = waitlist;
        waitlist = waitlist->next;
        free(temp);
    }

    Node *current = mainList;
    currentCount = 0;

    while (current) {
        if (currentCount < maxCapacity) {
            addPassenger(&tripList, current->firstName, current->lastName, current->departureTime);
            currentCount++;
        } else {
            addPassenger(&waitlist, current->firstName, current->lastName, current->departureTime);
        }
        current = current->next;
    }
}

// Display a list with a label
void displayList(Node *head, const char *label) {
    printf("%s:\n", label);
    while (head) {
        printf("Departure Time: %d, Name: %s %s\n", head->departureTime, head->firstName, head->lastName);
        head = head->next;
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("EASYTRIP.txt", "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int operation;
    char firstName[20], lastName[20];
    int departureTime;

    fscanf(file, "%d", &maxCapacity);

    while (fscanf(file, "%d", &operation) != EOF) {
        switch (operation) {
            case 1: // Add booking
                fscanf(file, "%s %s %d", firstName, lastName, &departureTime);
                addPassenger(&mainList, firstName, lastName, departureTime);
                rebuildTripAndWaitlist();
                break;

            case 2: // Remove booking
                fscanf(file, "%s %s", firstName, lastName);
                removePassenger(&mainList, firstName, lastName);
                rebuildTripAndWaitlist();
                break;

            case 3: // Show all bookings
                displayList(mainList, "Bookings");
                break;

            case 4: // Show trip list
                displayList(tripList, "Trip");
                break;

            case 8: // Show waitlist
                displayList(waitlist, "Waitlist");
                break;

            default:
                printf("Unknown operation: %d\n", operation);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
