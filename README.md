# Philosophers
##### I never thought philosophy would be so deadly

###### This is a project about threading processes and mutexes

:mag_right:\
    `The Philosophers project at 42 is a coding assignment that simulates the classic Dining Philosophers Problem
    to demonstrate concurrency control, resource management, and synchronization techniques.
    The project requires the use of C programming language and multithreading
    to implement a solution that prevents deadlocks and resource conflicts`
___
:bulb: ***Here are the things you need to know about  this assignment:***
<img height=400 src='https://imgs.search.brave.com/6xeZZXiOoPk1PJufJp-c8iyQ5c0pt74ue7hIhz2amDs/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly91cGxv/YWQud2lraW1lZGlh/Lm9yZy93aWtpcGVk/aWEvY29tbW9ucy83/LzdiL0FuX2lsbHVz/dHJhdGlvbl9vZl90/aGVfZGluaW5nX3Bo/aWxvc29waGVyc19w/cm9ibGVtLnBuZw'>
```
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying!
```
___
:bulb: Keywords:

Concurrent programming | Synchronization

:bulb: ***Types (pthread_mutex_t)***
```
    typedef union
    {
      struct __pthread_mutex_s __data;
      char __size[__SIZEOF_PTHREAD_MUTEX_T];
      long int __align;
    } pthread_mutex_t;

    struct __pthread_mutex_s
    {
      int __lock;
      unsigned int __count;
      int __owner;
    #ifdef __x86_64__
      unsigned int __nusers;
    #endif
      /* KIND must stay at this position in the structure to maintain
         binary compatibility with static initializers.  */
      int __kind;
    #ifdef __x86_64__
      short __spins;
      short __elision;
      __pthread_list_t __list;
    # define __PTHREAD_MUTEX_HAVE_PREV      1
    #else
      unsigned int __nusers;
      __extension__ union
      {
        struct
        {
          short __espins;
          short __eelision;
    # define __spins __elision_data.__espins
    # define __elision __elision_data.__eelision
        } __elision_data;
        __pthread_slist_t __list;
      };
    # define __PTHREAD_MUTEX_HAVE_PREV      0
    #endif
    };
```


