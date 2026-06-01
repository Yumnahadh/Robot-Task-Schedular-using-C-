**Robot Task Executor with Raylib GUI**
Concepts included:
**1. Data Structures:**
**• Queues:** The concept of queue is used for entering the tasks and executing them 
in a FIFO order. 
**Functions used:**  
Enqueue( ), dequeue( ), getfront( ), pendingtasks( ), display( ), isEmpty( ) 
 
**• Stacks:**   
The concept of the stacks is used for the adding the urgent task by interrupting 
the queue and executing the urgent task first by executing them by LIFO order 
**Functions used:**
Push( ), gettop( ), pop( ), display_Urgent( ), isEmpty( ) 
**• LinkedList:** 
To storing the history of the tasks being performed and completed ones. 
**Functions used:** add_History( ), display_History ( ); 
**• Binary Search Tree**: 
 Trees are being used for searching the task completed in the list or not . 
**Function used**: insert( ), search( ), addtask( ), completed( ) 
**2. Classes And Objects:**  
Representing tasks, queues, stacks, and the robot system itself. 
**• Templates:**
Making the task executor generic for different task types. 
3. **GUI basics:** 
• Raylib: Visualizing the task queues and history for user interaction  
4.**Threading and Delay execution:** 
Using (std::this_thread::sleep_for) to simulate task execution 
delays, providing a realistic workflow demonstration. 
