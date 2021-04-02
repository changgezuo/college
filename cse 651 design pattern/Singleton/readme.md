Singleton:
The singleton design pattern solves problems like:[6]

  ，How can it be ensured that a class has only one instance?
  ，How can the sole instance of a class be accessed easily?
  ，How can a class control its instantiation?
  ，How can the number of instances of a class be restricted?
  ，How can a global variable be accessed?
The singleton design pattern describes how to solve such problems:

  ，Hide the constructor of the class.
  ，Define a public static operation (getInstance()) that returns the sole instance of the class.