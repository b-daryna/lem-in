# lem-in

The goal of this project is to find the quickest way to get n ants across the farm.

At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)

• We consider that all the ants are in the room ##start at the beginning of the game.

• At each turn you will only display the ants that moved.

• At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).

• You must display your results on the standard output in the following format:

number_of_ants

the_rooms

the_links

Lx-y Lz-w Lr-o ...

x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,

w, o represents the rooms’ names.
