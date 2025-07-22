# Minitalk - UNIX Signal Communication

[![Build Status](https://github.com/mtelek/minitalk/actions/workflows/build.yml/badge.svg?cache_buster=1)](https://github.com/mtelek/minitalk/actions)
[![Code Size](https://img.shields.io/github/languages/code-size/mtelek/minitalk?style=flat-square)](https://github.com/mtelek/minitalk)
![Project Score](https://img.shields.io/badge/Mintalk-125%25-brightgreen)

## ✨ Description
Minitalk is a small data exchange program that demonstrates communication between a client and a server using UNIX signals (SIGUSR1 and SIGUSR2).  
The server receives and displays strings sent by the client, with the communication happening exclusively through signals.  
This project showcases low-level inter-process communication in a Unix environment.

## Key Features
- Client-server architecture using UNIX signals
- Efficient transmission of strings between processes
- Supports multiple consecutive client connections
- Fast performance (100+ characters per second)
- Server acknowledgment signals
- Unicode character support

## 🛠️ Installation & Compilation
1, Clone the repository
```bash
git clone git@github.com:mtelek/minitalk.git
cd minitalk
```
2, Compile the project
```bash
make
```
This will create two executables: server and client.

## 🚀 Usage
1, First, start the server in one terminal:
```bash
./server
```
The server will display its PID which you'll need for the client.  
2, In another terminal, use the client to send messages:
```bash
./client [server-pid] "your message here"
```
3, The server will display received messages in real-time.

## 🧪 Automated Testing
You can test the project using the [Minitalk-Tester](https://github.com/ThibaudM13/minitalk-Tester) by [ThibaudM13](https://github.com/ThibaudM13?tab=overview&from=2025-07-01&to=2025-07-23).  
This tester helps verify the functionality and performance of the implementation of the project.  

### Tester
<img src="Tester.png" width="500" />

### Server's output
<img src="Server_output.gif" width="500" />