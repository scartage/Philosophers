# Philosophers

This project consists of two parts: a mandatory part and an optional bonus part. Both parts must follow these rules:

- Global variables are prohibited!
- Your program(s) must accept the following arguments:
  - `number_of_philosophers`: the number of philosophers, but also the number of forks.
  - `time_to_die` (in milliseconds): if a philosopher doesn't start eating within `time_to_die` milliseconds from the start of their last meal or from the beginning of the simulation, they will die.
  - `time_to_eat` (in milliseconds): the time it takes for a philosopher to eat. During this time, they will have the forks occupied.
  - `time_to_sleep` (in milliseconds): the time it takes for a philosopher to sleep.
  - `[number_of_times_each_philosopher_must_eat]` (optional argument): if all philosophers eat at least `number_of_times_each_philosopher_must_eat` times, the simulation will stop. If not specified, the simulation will stop with the death of a philosopher.

- Each philosopher will be assigned a number from 1 to `number_of_philosophers`.
- Philosopher number 1 will sit next to philosopher number `number_of_philosophers`. Any other philosopher number N will sit between philosopher number N-1 and philosopher number N+1.

## Logs

Any change in a philosopher's state must have the following format:
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Replace `timestamp_in_ms` with the current timestamp in milliseconds and X with the philosopher's number.

The printed state must not be broken or altered by the state of other philosophers.

You cannot have more than 10ms between the death of a philosopher and the moment you print their death.

## Specific rules for the mandatory part

- Each philosopher must be a thread.
- There is a fork between each philosopher. Therefore, if there are several philosophers, each philosopher must have a fork to their left and another to their right. If there is only one philosopher, there will only be one fork on the table.
- To prevent philosophers from duplicating forks, you must protect the states of the forks with a mutex for each one.
