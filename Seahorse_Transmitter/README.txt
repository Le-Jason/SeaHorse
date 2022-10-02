Main Purpose of Seahorse_Transmitter:
1) Create User Control of Seahorse

Main Files:
1) Recieve.h
    Purpose: Handle the main duties with the transmitter itself
        1) Initialize Recieve duties
        2) Change LED color on status
            1) When aircraft battery is low
            2) Error status of aircraft
            3) When transmitter battery is low
            4) Error status of transmitter
            5) Status of Current Power of trasnmitter

2) Transmit.h
    Purpose: Handle the main duties with transmitting the signal
        1) Initialize Transmit duties
        2) Output of transmitter
            1) Map output of controller to input of motor's on aircraft
            2) Switch logic if there is a different mode
        3) Deal with joystick controls

3) main.cpp
    Purpose: main file