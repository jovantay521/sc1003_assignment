#include <stdio.h>
#include <string.h>
#define MAX 5

// structures
struct room_structure
{
    int roomID;
    int status;
    char customerName[20];
} room_structure_default = {0, 0, "no occupants"};


// prototype
void listOccupiedRooms(struct room_structure rooms[MAX]);
void assignRoom(struct room_structure rooms[MAX]);
void removeRoom(struct room_structure rooms[MAX]);
void findCustomer(struct room_structure rooms[MAX]);
int strcicmp(char const *a, char const *b);


main()
{
    int user_choice = 0, ctr;
    struct room_structure rooms[MAX]; // array of rooms

    for (ctr = 0; ctr < MAX; ctr++) {
        rooms[ctr] = room_structure_default;
    }

    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");

    while (user_choice != 5)
    {
        printf("Enter your choice: \n");
        scanf(" %d", &user_choice);

        switch(user_choice) {
            case 1: listOccupiedRooms(rooms); break;
            case 2: assignRoom(rooms); break;
            case 3: removeRoom(rooms); break;
            case 4: findCustomer(rooms); break;
        }
    }

    return 0;
}

int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}

void listOccupiedRooms(struct room_structure rooms[MAX])
{
    int ctr, no_of_occupied_rooms = 0;

    printf("listOccupiedRooms():\n");
    for (ctr = 0; ctr <= 5; ctr++)
    {
        if (rooms[ctr].status == 1)
        {
            no_of_occupied_rooms++;
            printf("roomID: %d\n", rooms[ctr].roomID);
            printf("customer name: %s\n", rooms[ctr].customerName);
        }
    }

    if (!no_of_occupied_rooms)
    {
        printf("The hotel is empty\n");
    }


    return;
}

void assignRoom(struct room_structure rooms[MAX])
{
    int room_ID = 0, no_of_occupied_rooms = 0, ctr;
    char customer_name[20];

    printf("assignRoom():\n");

    // check if hotel is full
    for (ctr = 0; ctr <= 5; ctr++)
    {
        if (rooms[ctr].status == 1)
        {
            no_of_occupied_rooms++;
            if (no_of_occupied_rooms == MAX) {
                printf("The hotel is full\n");
                return;
            }
        }
    }


    while ((room_ID < 1) || (room_ID > 5) || (rooms[room_ID - 1].status == 1))
    {
        printf("Enter a roomID between 1 and 5: \n");
        // scanf("\n");
        scanf(" %d", &room_ID);
        if (rooms[room_ID - 1].status == 1) {
            printf("Occupied! Enter another roomID\n");
        }
    }

    // set roomID and status to occupied (1)
    rooms[room_ID - 1].roomID = room_ID;
    rooms[room_ID - 1].status = 1;

    // set customer name
    printf("Enter customer name: \n");
    scanf("\n");  // remove newline from buffer
    fgets(customer_name, 20, stdin);
    customer_name[strlen(customer_name)-1] = '\0';  // remove trailing newline
    strcpy(rooms[room_ID - 1].customerName, customer_name);
    printf("The room has been assigned successfully\n");
    return;
}

void removeRoom(struct room_structure rooms[MAX])
{
    int room_ID = 0, ctr, no_of_occupied_rooms = 0;
    
    printf("removeRoom():\n");
    
    // check for occupied rooms
    for (ctr = 0; ctr <= 5; ctr++)
    {
        if (rooms[ctr].status == 1)
        {
            no_of_occupied_rooms++;
        }
    }

    if (!no_of_occupied_rooms)
    {
        printf("All the rooms are empty\n");
        return;
    }

    while ((room_ID < 1) || (room_ID > 5) || rooms[room_ID - 1].status == 0)
    {
        printf("Enter a roomID between 1 and 5: \n");
        scanf(" %d", &room_ID);
        if (rooms[room_ID - 1].status == 0) {
            printf("Empty! Enter another roomID for removal\n");
        }
    }

    rooms[room_ID - 1] = room_structure_default;
    printf("Removal is successful\n");
    return;
}

void findCustomer(struct room_structure rooms[MAX])
{
    char customer_name[20];
    int match, i;
    
    printf("findCustomer():\n");
    
    printf("Enter customer name: \n");
    scanf("\n");  // remove newline
    fgets(customer_name, 20, stdin);
    customer_name[strlen(customer_name)-1] = '\0';
    
    for (i = 0; i < MAX; i++) {
        if ( strcicmp(customer_name, rooms[i].customerName) == 0 ) {
            printf("The target customer name is found\n");
            printf("roomID: %d\n", rooms[i].roomID);
            printf("customer name: %s\n", rooms[i].customerName);
            break;
        }

        else {
            if (i == MAX-1) {
                printf("The target customer name is not found\n");
                break;
            }
        }
    }

    return;
}
