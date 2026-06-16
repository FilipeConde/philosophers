_This project has been created as part of the 42 curriculum by fconde-p_

# Description

The main goal of this project is to ~~make you cry hard~~ simulate the problem of the philosophers proposed by Edsger Dijkstra in 1965. It is an IT problem that verses about concurrency and threads or processes synchronization.

The problem tells us about a number of philosophers that have three basic needs: eat, think and sleep. Each one of them comes to the table witn one fork, but needs two of them to eat the food. So, as we can see, we do not have enough forks for all of them. While some of them eat, the remain should sleep or think. And so the forks must rotate between in a cycle of eat until fulfiled and then must be released to the left and right philosopher in order to keep the process. We set a time for them to do the eating action and a time that they can persist without start to eating again before starve. We must code a program that keeps all of them alive given the right conditions.

So... let's eat!

# Instructions

To compile the system do a `make` in the project folder.

To do a full clean, do a `make fclean` in the project folder.

Once compiled, run the `./philo` executable passing the arguments:

- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die` (in milliseconds): If a philosopher has not started eating within time_to_die milliseconds since the start of their last meal or the start of the simulation, they die.
- `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

Example:

> ./philo 1 800 200 200

Here, a philosopher must die. Remember, just one fork... no one can eat with jusr one fork (as it seems).

=P

# Resources

I read [this amazing article](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2) by Dean Ruina explaining nos just the problem of philosophers, but also the aplication of this concept in other contexts.

I also used AI to help me to do part of the algorithms since I was about to die! It certainly kept me from learning a few concepts in more depth, but beside this I had the opportunity to use ir in a mature way. When needed to hurry up the coding process, I used Claude Code. It was my first time using the Anthropic models and I liked the interface. I kept a consistent practice emulating a pair programming duo. I took the role of an architect or engineer and the AI took the operational coding role. Since I started this project with unit tests, it was amazing for me to see how strongly tighten was the coding. We got a straight forward path using guardrails based on my interactions instead of using skills and pre-prompts.

[This article](https://akitaonrails.com/2026/02/20/do-zero-a-pos-producao-em-1-semana-como-usar-ia-em-projetos-de-verdade-bastidores-do-the-m-akita-chronicles/) from Fabio Akita shows how to use AI as a mature software developer keeping good practices.