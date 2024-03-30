# Philosophers

## Overview

This project is a simulation of the dining philosophers problem. The dining philosophers problem is a classic synchronization problem that models a situation where some philosophers are sitting at a table and they spend their time thinking and eating and sleeping. The philosophers share a common resources, table and forks and have to use them in a way that they don't starve and don't create a deadlock.

## Key Features

The project is implemented in `C` and uses `pthread` library for `thread` management in `Mandatory` part and `fork` for `process` management in `Bonus` part. The project has the following key features:
- Each philosopher is a separate thread/process depending on the part.
- Each philosopher has a `fork` on the left and a `fork` on the right.
- A philosopher can only eat if he has both `forks`.
- A fork can be `Mutex` or `Semaphore` depending on the part.
- Each philosopher has a state: `thinking`, `eating`, `sleeping`, `dead`.
- Each philosopher has a `time_to_die`, `time_to_eat`, `time_to_sleep` and `number_of_times_to_eat`.
- The simulation stops when a philosopher dies or when all philosophers have eaten `number_of_times_to_eat` times.

## Getting Started

To get a local copy of the project, perform the following steps:
```
git clone https://github.com/whoismtrx/42_Philosophers.git philosophers
cd philosophers
for Mandatory part:
cd philo
make
for Bonus part:
cd philo_bonus
make
```

## Usage

To run the simulation, execute the following command:
```
./philo 4 410 200 200 [5]
```
where:
- `4` is the number of philosophers.
- `410` is the time to die in milliseconds.
- `200` is the time to eat in milliseconds.
- `200` is the time to sleep in milliseconds.
- `[5]` is the number of times each philosopher must eat. If not provided, the simulation stops when a philosopher dies.

## Implementation

Philosophers is a project that requires a good understanding of synchronization and parallel computing. first we need to understand the dining philosophers problem and then implement a solution that satisfies the requirements of the project.
We need to create a simulation where philosophers are threads so basically we need to create a separate thread for each philosopher with its own routine. Each philosopher has a state and a set of actions that he can perform. The philosophers share a common resource, the table and forks, the table its the process itself and the forks are the mutexes that we used to lock and unlock the forks, so let's start philosopher routine. Routing is simple, philosopher will think, then try to take his left and right forks, if he can't take both of them he stay in the same state and try again, when he take both forks he will eat, then he will release the forks and sleep and then he will think again and so on. The simulation stops when a philosopher dies or when all philosophers have eaten `number_of_times_to_eat` times. you can create a thread who monitors the philosophers and check if they are alive and if they have eaten enough times.
The bonus part is the same as the mandatory part but instead of threads we use processes, so we need to create a separate process for each philosopher with its own routine. and because processes don't share memory we need to use `shared memory` to store the state of the philosophers and the forks. we can use `semaphores` to lock and unlock the forks.
the rest of the implementation is the same as the mandatory part.

## Resources
