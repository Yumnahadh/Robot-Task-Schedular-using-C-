#include<iostream>
#include<ctime>
#include<cstdlib>
#include<limits>
#include<chrono>
#include<thread>
#include<string>
using namespace std;
template<typename TASK> //templates being used in the program for user ease to add the type of data
class TaskExecutor
{
	public:
		int task_num;
		TASK info;
		TaskExecutor *next;
	TaskExecutor(int data,TASK i)//constructor is initialized here 
	{
		task_num=data;
		info=i;
		next=NULL;
	}
};
template<typename TASK>
class Queue 
{ //queue is made which will stores all the task in the queue form 
	public:
		TaskExecutor<TASK>*front; //2 pointers are made for the queue front and rear 
		TaskExecutor<TASK>*rear;
	public:
		Queue()
		{
			front=0; // at first both initialize 0 as at first the queue is empty from both ends 
			rear=0;	
		}
	void enqueue(int num, TASK info) // function made for adding task in queue
	{
		TaskExecutor<TASK>*temp=new TaskExecutor<TASK>(num,info); //new node is being made 
 		if(rear==NULL)
      {
  	    front=rear=temp;//both points to same node at first
	  }
	  else
	  {//queue is not empty here
	  	rear->next=temp; //attach new node in the end 
	  	rear=temp;
	  }
}
void pending_tasks()//function for pending tasks...
{
	if(front==NULL) 
	{
		cout<<"YAHOO!....NO PENDING TASK"<<endl;
	}
	else
	{
		TaskExecutor<TASK>*temp=front;
		while(temp!=NULL)  //if the queue is not empty , do all the empty task of it 
		{
			cout<<"The pending task are #"<<temp->task_num<<":"<<temp->info<<endl;//pending task displaying 
			temp=temp->next;
		}
	}
}
bool isEmpty()
{    //check condition for if front is empty....
	return front==NULL;
}
TASK getfront()
{  //if front is not empty,it returns the front pointing to info
	if(front!=NULL)
	{
		return front->info;
	}
}
void dequeue() //removing of the task being executed 
{   if(front==NULL)
    {
	return;
    }
	TaskExecutor<TASK>*temp=front;
	front=front->next;
	if(front==NULL)
	{
		rear=NULL;//update the rear
	}
	delete temp;//delete the previous front node 
	
}
	void display()
	  {
	  TaskExecutor<TASK> *temp1= front;
	  	while(temp1!=NULL)
	  	{	
	  	    cout<<"The Task #"<<temp1->task_num<<"Completed are:"<<temp1->info<<endl; //display the completed task 
	  		temp1=temp1->next;
		  }
		
	  }
};
class history //history being stored using linkelist concept 
{
private:
    struct Node{   //evaluating it with the structure
        string task;
        Node* next ;
        Node(string t)//initialized constructor
	{
            task = t;
            next = NULL;
        }
    };
    Node* Head;

public:
    history()  
	{
        Head = NULL;  //considering the head to be NULL 
    }
    
    void addHistory(string t) //same structure followed as linkedlist for adding number to list /history to list 
	{
        Node* temp = new Node(t);
        temp -> next = Head;
        Head = temp;
    }
    
    void displayHistory()   //displaying the history 
	{   
        if(Head==NULL)
		{
            cout << "No completed tasks yet.";
            return;
        }
        
        Node* temp = Head;
        cout << "" << endl;
        while(temp!=NULL)         
		{
        cout<<temp->task<<endl;
        temp=temp->next;
		}
}
};
template<typename TASK>
class Urgent_task //urgent task being used by the stack concept 
{   public:
	TaskExecutor<TASK>*top; //urgent task has the top ka concept
	public:
		Urgent_task()
		{
			top=NULL; //at first the top is empty which means the stack is empty 
		}
	void push(int num,TASK info)
	{     //push the value to the stack 
			TaskExecutor<TASK>*temp=new TaskExecutor<TASK>(num, info);
		     temp->next=top;
	       	top=temp;//updating top 
	}
	TASK gettop()
	{
		return top->info;
	}
	void pop()  //deleting of the task being done (followed the concept of LIFO)
	{ 
	 if (top==NULL)
	{
		cout<<"NO URGENT TASK THERE:"<<endl;
		return;
	}
	
		TaskExecutor<TASK>*temp= top;
		top=top->next;
		delete temp; //delete the previous 
}
	void display_Urgent()
	  {
		if(top==NULL)
		{
			cout<<"NO URGENT TASK ";
			return ;
		}
		 TaskExecutor<TASK>*temp=top;
			while(temp!=NULL)                //displaying the urgent task
			{
			cout<<"THE URGENT TASK #"<<temp->task_num<<": "<<temp->info<<endl;
				temp=temp->next;
			}
			
		}
		bool isempty()
		{
			return top==NULL;
		}
	
};
class trees  //trees are being  made for the searching the task from the provided list
{
	public:
    int task_nn;
    string info;
    trees*left; //2 pointers are being made for the left and right side of the trees 
    trees*right;
    trees(int n, string inf)  //initialize constructor 
    {
    	task_nn=n;
    	info=inf;
    	left=right=NULL;
	}
};
class module //class module being made which depends on the trees class 
{
	trees*root;  
	public:
		module()
		{
			root=NULL;
		}
	trees*insert(trees*node,int n, string detail)  //inserting a node to a tree
	{
		if (node==NULL)
		{
			node=new trees(n,detail);  //if the node is NULL then assign it the constructor and the node is being inserted 
			return node;
		}
		if(n<node->task_nn)  //if the condition is lesser than the the main root , point it towards the left side of the tree
		{
			node->left=insert(node->left,n,detail);//recursive call being made 
		}
		else if(n>node->task_nn)//execute agar if condition not fullfills and value is greater than the required then set it to right side 
		{
			node->right=insert(node->right,n,detail);
		}
	return node;
	}
	bool search(trees*node,int data) //searching  function through trees are implemented 
	{  //will return either true or either false
		if(node==NULL)
		{              
			return false; //if it is empty , this will not work 
		}
		if(node->task_nn==data)
		return true;//if the value matches , it will pass true
		else if(data<node->task_nn) //if value is less , then it will search in left subtrees
		return search(node->left,data);
		else
		return search(node->right,data); //otherwise it will search in right subtree
		
	}
	void add_task(int n,string detail)
	{
		root=insert(root,n,detail);//recursive call to add the tasks
	}
	bool completed(int n)
	{
	return search(root,n);//search recursive call , it will true if it is completed
    }
};
int main() {
    Queue<string>Q1; // class Queue object here is Q1 with template <typename>be string
    Urgent_task<string>UT_1;//the object of urgent task being declared with string type as template 
    history H; //object of history class
    module M1;//object of module class
    int check;
    int task_n;
    int counter=1;//each task has unique number of task
    string details;
    cout<<"Please enter the number of tasks:";
    cin>>task_n;
    cin.ignore();//used for ignore reading leftover new lines 
    for(int i=0;i<task_n;i++)
    {
    	cout<<"Enter task #"<<(i+1)<<":"; //for loop is applied here to prompt user enter the task they want according to thier task numnber entered
    	getline(cin,details);
    	Q1.enqueue(counter++,details);	//enqueue is called here to add task in list
	}
	cout<<"\n";
	cout<<"The tasks are being added"; 
    int donetask=0;
     bool added= false;
     while(!Q1.isEmpty() ||!UT_1.isempty())
    {
	while(!UT_1.isempty())
	{ 
	 string ts=UT_1.gettop();
	 cout<<"Urgent task exeucting:"<<ts<<endl;
	 H.addHistory("Urgent completed"+ts); 
	 M1.add_task(UT_1.top->task_num,ts);
	 UT_1.pop();
	 std::this_thread::sleep_for(std::chrono::seconds(2));
	
	 
	}
	if(!Q1.isEmpty())
	{ 
	string t=Q1.getfront();
	cout<<endl;
	cout<<"Executing pending task:"<<t;
	H.addHistory("Pending done: "+t);
	M1.add_task(Q1.front->task_num,t);
	Q1.dequeue();
	donetask++;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	if((donetask==2 )&& (!added))
	{ cout<<"\n";
		cout<<"URGENT TASK ARRIVED........."<<endl;
		UT_1.push(123," OBSTACLE OCCURS, STOP ");
		UT_1.push(124, " TAKE A TURN ");
		UT_1.push(125," LOW BATTERY ");
		added=true;
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}
}
cout<<"\nENTER TASK TO BE CHECKED:";
cin>>check;
if(M1.completed(check))
{
	cout<<"TASK"<<check<<"is completed"<<endl;
}
else
{  char ch;
	cout<<"TASK"<<check<<"not found"<<endl;
}

cout<<"DISPLAYED HISTORY:"<<endl;
H.displayHistory();
return 0;
}
