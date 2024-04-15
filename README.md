# minitalk

minitalk is an individual 42 school project where we have to create a communication program in the form of a client and server using UNIX signals.

## Status

* Success
* Grade: 125/100

## Rules

The server must be launched first and after being launched it must diplay its PID.

The client will take as parameters:
* The server PID.
* The string that should be sent.

The client must communicate to the server the string passed as a parameter and the server must display it. Communication should only be done using ```SIGUSR1``` and ```SIGUSR2``` UNIX signals.

### Bonus

* The server confirms receipt of each message by sending a signal to the client.
* Support Unicode characters.

## Project content

This project contains a **libft** folder which is a library that we had to create as the first 42 school project. This folder also includes files corresponding to the following 42 school project: **ft_printf** and **get_next_line**.

Compiling the project generates two executables: ```client``` and ```server```.

## Usage

Use ```make``` command to compile then run the server with:
```
./server
```
Next, run the client with:
```
./client <PID> <string to send>
```
***
Made by Thibaut Charpentier: <thibaut.charpentier42@gmail.com>
