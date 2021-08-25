# Push_Swap

Unlike most previous projects, this one is a bit unique in so far as i removed my use of the trusty libft, on the grounds that the norm has changed at 42 and i
have not yet modified my entire libft to match it. Thus i have created the Minilib, it's just a folder with the libft functions i use most, that has a
corresponding .h file, and .mk file for ease of use, it is compiled in with the rest of project as though it were regular srcs files.




Ok so Push Swap grabs all the ints with an atoi like function and stores them from the
Arg List sent as a parameter in a table of integers.
Then i put those ints in numbered linked list, a second numbered linked list is created
empty, they represent the Stacks, A and B.

Checker uses the same system of linked lists representing Stacks, and tables of ints, but
a different linked list to store the op codes gathered from the standard input.
