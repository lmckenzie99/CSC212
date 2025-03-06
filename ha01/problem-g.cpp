#include <iostream>
#include <vector>

int main() {
    int totalRooms, roomsBooked;
    std::cin >> totalRooms >> roomsBooked;

    std::vector<bool> booked(totalRooms + 1, false);  // To track booked rooms (1-based index)

    for (int i = 0; i < roomsBooked; i++) {
        int room;
        std::cin >> room;
        booked[room] = true;  // Mark the room as booked
    }

    // Find the first available room
    for (int i = 1; i <= totalRooms; i++) {
        if (!booked[i]) {
            std::cout << i; 
            return 0;
        }
    }

    // If all rooms are booked
    std::cout << "too late";
    return 0;
}

