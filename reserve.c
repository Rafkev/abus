#include <stdio.h>
#include <stdbool.h>

#define NUM_SEATS 10

bool seats[NUM_SEATS] = {false};

void displaySeats() {
    printf("\nBus Seats:\n");
    for (int i = 0; i < NUM_SEATS; i++) {
        printf("Seat %d: %s\n", i + 1, seats[i] ? "Booked" : "Available");
    }
}

void bookSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > NUM_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (seats[seatNumber - 1]) {
        printf("Seat %d is already booked.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = true;
        printf("Seat %d booked successfully.\n", seatNumber);
    }
}

void cancelBooking(int seatNumber) {
    if (seatNumber < 1 || seatNumber > NUM_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (!seats[seatNumber - 1]) {
        printf("Seat %d is not booked.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = false;
        printf("Booking for seat %d canceled successfully.\n", seatNumber);
    }
}

int main() {
    int choice;
    int seatNumber;

    do {
        printf("\n\nBus Reservation System\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                printf("Enter seat number to book: ");
                scanf("%d", &seatNumber);
                bookSeat(seatNumber);
                break;
            case 3:
                printf("Enter seat number to cancel booking: ");
                scanf("%d", &seatNumber);
                cancelBooking(seatNumber);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
