#include <stdio.h>
#include <string.h>

/* Step Tracking Module */
void trackSteps(int *steps) {
    int today;
    printf("Enter Km walked today: ");
    scanf("%d", &today);
    *steps += today;
    printf("Total Km walked so far: %d\n", *steps);
}

/* Heart Rate Monitoring Module */
void checkHeartRate() {
    int rate;
    printf("Enter your heart rate: ");
    scanf("%d", &rate);

    if (rate > 100)
        printf("Warning: High Heart Rate!\n");
    else if (rate < 60)
        printf("Warning: Low Heart Rate!\n");
    else
        printf("Heart Rate Normal.\n");
}

/* Hydration Reminder Module */
void hydrationReminder(int hour) {
    if (hour % 2 == 0)
        printf("Reminder: Drink water!\n");
}

/* Routine Management Modules */
void setRoutineTimer(char routine[], int *timer, int *points) {
    printf("Enter routine name (e.g. study, exercise): ");
    scanf("%s", routine);

    printf("Set timer in minutes: ");
    scanf("%d", timer);

    printf("Routine '%s' set for %d minutes.\n", routine, *timer);
}

void completeRoutine(char routine[], int timer, int *points) {
    if (timer > 0) {
        int done;
        printf("Did you finish '%s' for %d minutes? (1=Yes / 0=No): ",
               routine, timer);
        scanf("%d", &done);

        if (done) {
            *points += 10;
            printf("Great job! You earned 10 points. Total points: %d\n",
                   *points);
        } else {
            printf("Try again next time!\n");
        }
    } else {
        printf("Set a routine first!\n");
    }
}

/* Main Program */
int main() {
    int steps = 0, choice, hour = 8, timer = 0, points = 0;
    char routine[20] = "";

    while (1) {
        printf("\n1. Track Steps\n");
        printf("2. Check Heart Rate\n");
        printf("3. Hydration Reminder\n");
        printf("4. Set Daily Routine\n");
        printf("5. Complete Routine\n");
        printf("6. Show Points\n");
        printf("0. Exit\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            trackSteps(&steps);
        } else if (choice == 2) {
            checkHeartRate();
        } else if (choice == 3) {
            hydrationReminder(hour);
            hour++;
        } else if (choice == 4) {
            setRoutineTimer(routine, &timer, &points);
        } else if (choice == 5) {
            completeRoutine(routine, timer, &points);
        } else if (choice == 6) {
            printf("Total reward points: %d\n", points);
        } else if (choice == 0) {
            printf("Lets meet soon for interesting tasks!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
