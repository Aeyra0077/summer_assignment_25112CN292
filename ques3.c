#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 50

struct Ticket {
    int id;
    char name[50];
    int seat_num;
};

struct Ticket system_bookings[TOTAL_SEATS];
int seats[TOTAL_SEATS] = {0};
int booking_count = 0;
int next_id = 1001;

void display_menu() {
    printf("\n=== TICKET BOOKING SYSTEM ===\n");
    printf("1. View Available Seats\n");
    printf("2. Book a Ticket\n");
    printf("3. Cancel a Ticket\n");
    printf("4. View All Bookings\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void view_seats() {
    printf("\n--- Seating Arrangement ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            printf("[%2d:Available] ", i + 1);
        } else {
            printf("[%2d: BOOKED  ] ", i + 1);
        }
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

void book_ticket() {
    if (booking_count >= TOTAL_SEATS) {
        printf("\nError: All seats are fully booked!\n");
        return;
    }

    int choice_seat;
    printf("\nEnter preferred seat number (1-%d): ", TOTAL_SEATS);
    if (scanf("%d", &choice_seat) != 1) {
        printf("\nInvalid entry!\n");
        while (getchar() != '\n');
        return;
    }

    if (choice_seat < 1 || choice_seat > TOTAL_SEATS) {
        printf("\nError: Invalid seat number!\n");
        return;
    }

    if (seats[choice_seat - 1] == 1) {
        printf("\nError: Seat %d is already occupied!\n", choice_seat);
        return;
    }

    struct Ticket new_ticket;
    new_ticket.id = next_id++;
    new_ticket.seat_num = choice_seat;
    
    printf("Enter passenger name: ");
    while (getchar() != '\n');
    fgets(new_ticket.name, sizeof(new_ticket.name), stdin);
    new_ticket.name[strcspn(new_ticket.name, "\n")] = '\0';

    seats[choice_seat - 1] = 1;
    system_bookings[booking_count++] = new_ticket;

    printf("\nSuccess: Ticket booked successfully!\n");
    printf("Ticket ID: %d | Passenger: %s | Seat: %d\n", new_ticket.id, new_ticket.name, new_ticket.seat_num);
}

void cancel_ticket() {
    if (booking_count == 0) {
        printf("\nError: No active bookings found to cancel!\n");
        return;
    }

    int target_id;
    printf("\nEnter your Ticket ID to cancel: ");
    if (scanf("%d", &target_id) != 1) {
        printf("\nInvalid entry!\n");
        while (getchar() != '\n');
        return;
    }

    int target_index = -1;
    for (int i = 0; i < booking_count; i++) {
        if (system_bookings[i].id == target_id) {
            target_index = i;
            break;
        }
    }

    if (target_index == -1) {
        printf("\nError: Ticket ID %d not found in our records!\n", target_id);
        return;
    }

    int freed_seat = system_bookings[target_index].seat_num;
    seats[freed_seat - 1] = 0;

    for (int i = target_index; i < booking_count - 1; i++) {
        system_bookings[i] = system_bookings[i + 1];
    }
    booking_count--;

    printf("\nSuccess: Ticket ID %d has been canceled. Seat %d is now available.\n", target_id, freed_seat);
}

void view_bookings() {
    if (booking_count == 0) {
        printf("\nNo active bookings to show.\n");
        return;
    }

    printf("\n--- Current Passenger Bookings ---\n");
    printf("%-12s %-30s %-10s\n", "Ticket ID", "Passenger Name", "Seat No.");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < booking_count; i++) {
        printf("%-12d %-30s %-10d\n", system_bookings[i].id, system_bookings[i].name, system_bookings[i].seat_num);
    }
}

int main() {
    int selection;
    while (1) {
        display_menu();
        if (scanf("%d", &selection) != 1) {
            printf("\nInvalid choice. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (selection) {
            case 1:
                view_seats();
                break;
            case 2:
                book_ticket();
                break;
            case 3:
                cancel_ticket();
                break;
            case 4:
                view_bookings();
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid selection! Please pick an option from 1 to 5.\n");
        }
    }
    return 0;
}
