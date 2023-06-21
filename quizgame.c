#include <stdio.h>

#define BLACK   "\e[30m"
#define RED     "\x1b[33;4m"
#define GREEN   "\x1b[31;32m"
#define ORANGE "\x1b[31;3m"
#define BLUE    "\e[34;4m"
#define MAGENTA "\x1b[35;5m"   
#define CYAN    "\x1b[36;6m"  
#define WHITE   "\x1b[37;7m"
#define RESET   "\x1b[0m"   
 
int n,flg=0;  //n:no of players

void mainmenu();//QUIZ GAME,WELCOME,RULES AND INFORMATION //BHUSHAN

struct input//ARRAY OF STRUCTURE TO TAKE INPUT OF MAXIMUM 5 PARTICIPANTS
  {
  char name[43];
  int age;
  }inpt[10];//inpt is structure variable for inpt

int ipt();//ipt to take input from players and no. of players and returns no. of players

struct gameplay
  {
int ans[10];//All answers for all participants are stored for future modification
int scre;//score of individual participant will be stored.
  }game[10];//game is structure variable to store all information when player plays game.

int play(int ch);//Function which contains all the data of program like all Q and Answers.

int score(int flg);//score will be calculated in it.Input:flg(no. of Q answered correctly).Output:Score

void winner();//will first find max score then will declare all names scoring that points.

void scoreboard();//To show the final result of all participants more than 1.

int main(void)
{
 mainmenu(); //First participnts will see the mainmenu.
 n=ipt();//n is number of participants.
 
 if ( n == 0 )//in ip function if(n<1 || n>5) return 0;GAME WILL END
 {
 printf ( RED"\n\t\t\t\t\t# # WRONG INPUT # #\n\t\t\t\t\tBYE, SEE YOU LATER!" RESET);
 goto end;//goto is used
 }

  if(n==1)
  {
   play(n);//game will be played for 1 player and then score will be declared.
  }
  else
   {
    for(int i=0;i<n;i++)
    {
     printf("\n\nPlayer %s its your turn.\n\n",inpt[i].name);//will tell whose turn is there
     play(i+1);// it will go as 1,2,3,4,5.
    }
          scoreboard();//wil show scores along with name
          winner();// will declare winner or winners
    }
   
    end: //for goto end
    printf(GREEN"\nBYE,Have a nice day and STAY VACCINATED."RESET);//STAY VACCINATED
  
}

void mainmenu() //MAIN MENU FUNCTION
{
  printf(ORANGE"\n\t\t\t\t\t\t\t# "RESET);
  printf("# ");
  printf(GREEN"#"RESET);
  printf(WHITE"QUIZ GAME "RESET);

printf(ORANGE"# "RESET);
printf("#");
printf(GREEN" # "RESET);
printf(GREEN"\n\t\t\t----------------------------------------------------"RESET);

printf(ORANGE"\n\t\t\t\t\t\t\tWELCOME ALL PARTICIPANTS\n"RESET);

printf(GREEN"-------------------------"RESET);
printf(ORANGE"\n#"RESET"#"GREEN"#"RESET" RULES"ORANGE" #"RESET"#"GREEN"#\n"RESET);
printf(GREEN"-------------------------"RESET);
  printf(ORANGE"\n1) Welcome to 'Quiz Game' which has mcq type questions and each question has four options, only one of which is correct.\n2)"RESET" Maximum 5 Number of participants can participate and each participant has to solve 5 questions."ORANGE"\n3)"RESET" Each correctly answered question is rewarded as  coins."ORANGE" \n4) The value of  coins depends on the specific question.\n"RESET);
 printf(GREEN"--------------------------"RESET);
 printf("\n"CYAN"Que No.\t:\tReward(coins)"RESET"\n");
 printf(GREEN"--------------------------"RESET);
printf("\n"CYAN"Q1   \t: \t1\nQ2   \t: \t2\nQ3   \t: \t4\nQ4   \t: \t6\nQ5   \t: \t8");
printf(GREEN"\n--------------------------"RESET);
 printf(ORANGE"\n5)If someone gets the wrong answer, the game will end for him / her at that moment. \n6)"CYAN"50-50 Lifeline:"GREEN"There is a lifeline named 50-50 in which The  system would remove two wrong answers from the game, leaving the contestant one right and one wrong answer.\n "CYAN"To activate it :"GREEN"Enter "CYAN"'0' "RESET""GREEN"in the answer to the question for which you want to use lifeline."RED"\n Note:You can only use it once in your turn ."
RESET ORANGE"\n7)The contestant who earns more coins at the end will be declared as the winner."RESET) ;}
 
int ipt(){ //Function takes input and stores in structure input
  printf("\nNumber of participants = ");//n
  scanf("%d",&n);
  if(n<1||n>5)
  return 0;
  for(int i=0;i<n;i++)
  {
  printf(GREEN"\nEnter Name and Age of participant %d:\n",i+1); // DETAILS
  scanf("%s %d" , inpt[i].name , &inpt[i].age); // STRUCT
  printf(RESET);
  }
  return n;//IMPORTANT STEP
}

int score(int flg) //Takes number of questions answered correctly as argument.
{ 
  int sc=1;
  if(flg==0)
  return 0;
  for(int i=1;i<flg;i++)
   sc=sc+(2*i);
   return sc;
}

void winner()//displays winner
{
  int i=0,t=0;
  printf(ORANGE"\n______"RESET);
  printf(WHITE"\n\t\t\tWINNER"RESET);
  printf(GREEN"\n______"RESET);
  do{
  if(game[i].scre>=t)
   {
   t=game[i].scre;
   }
   i++;
  }while(i<n); //t is maximum score obtained among all.
i=0;
 do{
  if(game[i].scre==t)
   {
     printf("\nWinner is %s with %d coins\n",inpt[i].name,game[i].scre);//will show winner
   }
   i++;
 }while(i<n);
}

void scoreboard()// will show names with score of all
{
printf(ORANGE"\n_____"RESET);
printf(WHITE"\n\t\tSCOREBOARD"RESET);
printf(GREEN"\n______"RESET);
printf(ORANGE"\nName and Score:"RESET);
for(int i=0;i<n;i++)
printf("\n%s\t\t\t%d",inpt[i].name,game[i].scre);
}

int play(int ch)//ch:player no. n_____
{
  static int i=0;//after 0 next time when loop comes as choice ch ==1 that time i=1.
  int j=0,t=0;
 switch(ch)
 {
   case 1:
   printf(ORANGE"\nQ1 . National Animal of India is"RESET);
   printf("\n\t1:Tiger\t\t2:Lion\n\t3:Peacock\t4:Leapord");
       printf(GREEN"\n\tAns = "RESET);//for participant
       scanf("%d", &game[i].ans[j]);//take ans

       if (game[i].ans[j]==0)//for lifeline
      { 
       t++;//t=1 when lifeline is used once.Again one should not use it.So a parameter t.If t==1 and ans given is 0 then you ill be warned.  
       printf(CYAN"\nQ1 . National Animal of India is"RESET);
       printf("\n\t1:Tiger\t\t2:Lion");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);// take answer after lifeline
      }

       if(game[i].ans[j]==0)//Cannot use lifeline again.
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);//Warning 
       printf(GREEN"\n\n\tAns = "RESET);//Last time option to give answer.
       scanf("%d", &game[i].ans[j]);//take answer // j is used so that we can store all the ans of all the participants.
       }

      if(game[i].ans[j]==1)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);// score till Q1 is found if ans is right.
      printf("\n\tTotal no. of coins earned = %d\n",score(flg));//will display score till now
      }
   else //if ans goes wrong,correct answer will be shown and game will end
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.1"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ2 . Who was the first Chief Minister of Maharashtra?"RESET); 
       printf("\n\t1:Yashwantrao Chavan\t\t2:P. K. Sawant\n\t3:Vasantrao Naik\t\t\t4:Shankarrao Chavan");                    
       j++; //for next answer to be stored             
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ2 . Who was the first Chief Minister of Maharashtra? "RESET);
       printf("\n\t1:Yashwantrao Chavan\t\t4:Shankarrao Chavan");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==1)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
       game[i].scre=score(flg);
       printf("\n\tTotal no. of coins earned = %d\n",score(flg));
   
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.1"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
     
      return 0;
      }

//##############################################
      printf(ORANGE"\nQ3 .India's first satellite Aryabhata was launched from?"RESET);
      printf("\n\t1:Soviet Union\t\t2: America\n\t3:India\t\t\t\t4:Israel");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
       t=1;
       printf(CYAN"\nQ3 .India's first satellite Aryabhata was launched from? "RESET);
       printf("\n\t1:Soviet Union\t\t3:India");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }
      
      if(game[i].ans[j]==1)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      
      }
   else 
      {
     printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.1"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ4 . Who among the following is known as 'Father of Indian Cinema'?"RESET);
       printf("\n\t1:.Dada Saheb Torne\t\t\t2:Dada Saheb Phalke\n\t3:Amitabh Bachchan\t\t\t4:Mani Sethna");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
        
       printf(CYAN"\nQ4 .Who among the following is known as 'Father of Indian Cinema? \n\t2: Dada Saheb Phalke\t\t4:Mani Sethna"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg)); 
      return 0;
      }
//##############################################
      printf(ORANGE"\nQ5 .Which indian state has the largest area"RESET);
      printf("\n\t1:. Maharashtra\t\t\t2:Madhya Pradesh\n\t3:Uttar Pradesh\t\t\t4:Rajasthan");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ5Which indian state has the largest area?"RESET);
       printf("\n\t1:Maharashtra\t\t4:Rajasthan");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==4)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.4"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
      break;
//#########################################################//
//#########################################################//
  case 2: i++; //For 2nd participant i==1 and starting again from j=0 with zero correct answers(flg=0)
          j=0;
          flg=0;
          printf(ORANGE"\nQ1 .What is the National Fruit of India?"RESET);
          printf("\n\t1:Pomegranate\t\t2:Apple\n\t3: Banana\t\t\t4:Mango");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if (game[i].ans[j]==0)
      { 
       t++;
       printf(CYAN"\nQ1 .What is the National Fruit of India?"RESET);
       printf("\n\t1:2.Apple\t\t4:Mango");       
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==4)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
     printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.4"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ2 . The minimum age of the voter in india?"RESET);
       printf("\n\t1:15\t\t\t2:18\n\t3:21\t\t\t4:25");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ2 .The minimum age of the voter in india?"RESET);
       printf("\n\t2:18\t\t3:21");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf("\n\tYou can use 50-50 only once in a game");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
       game[i].scre=score(flg);
       printf("\n\tTotal no. of coins earned = %d\n",score(flg));
   
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
     
      return 0;
      }

//##############################################
      printf(ORANGE"\nQ3 .Who was the first chairman of Indian Space Research Organisation(ISRO)?"RESET);
      printf("\n\t1:K kasturirangan\t\t2:Vikram Sarabhai\n\t3:Satish Dhawan\t\t\t4:Homi J Bhabha");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
       t=1;
       printf(CYAN"\nQ3 .Who was the first chairman of Indian Space Research Organisation(ISRO)?"RESET);
       printf("\n\t2:Vikram Sarabhai\t\t4:Homi J Bhabha");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }
      
      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ4 .Filmfare awards started from the year? "RESET);
       printf("\n\t1:1952\t\t\t2:1964\n\t3:1954\t\t\t4:1960");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ4 . Filmfare awards started from the year?"RESET);
       printf("\n\t2:1964\t\t3:1954");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==3)
      {
      printf("\n\tYou are Right!!");
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.3"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg)); 
      return 0;
      }
//##############################################
      printf(ORANGE"\nQ5 .What is the new name of Feroz Shah Kotla ground?"RESET);
      printf("\n\t1:Arun Jaitley Stadium\t\t\t\t 2:Sheila Dikshit Stadium\n\t3:Gautam Gambhir Stadium\t\t\t4:Ajit Wadekar Stadium");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ5 .What is the new name of Feroz Shah Kotla ground?"RESET);
       printf("\n\t1:Arun Jaitley Stadium\t\t2: Sheila Dikshit Stadium");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"GREEN);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==1)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.1"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
      break;
//#######################################################//
//#######################################################//
  case 3: i++;
          j=0;
          flg=0;
          

          printf(ORANGE"\nQ1 .What is the National River of India?"RESET);
          printf("\n\t\t1:The Narmada River\t\t\t2:The Krishna River\n\t\t3:The Ganga River \t\t\t4:The Brahmaputra River");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if (game[i].ans[j]==0)
      { 
       t++;
       printf(CYAN"\nQ1 .What is the National River of India?"RESET);
       printf("\n\t2:The Krishna River\t\t3:The Ganga River");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==3)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
     printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.3"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ2 .The minimum age to qualify for election to the Lok Sabha is?"RESET);
       printf("\n\t1:25\t\t\t2:21\n\t3:18\t\t\t4:35");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ2 .The minimum age to qualify for election to the Lok Sabha is?"RESET);
       printf("\n\t1:25\t\t2:21");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==1)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
       game[i].scre=score(flg);
       printf("\n\tTotal no. of coins earned = %d\n",score(flg));
   
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.1"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
     
      return 0;
      }

//##############################################
      printf(ORANGE"\nQ3 .Who is known as the father of indian nuclear programme?"RESET);
      printf("\n\t1:APJ Abdul Kalam\t\t2: Raja Ramanna\n\t3:Homi J Bhabha\t\t\t4:.Vikram Sarabhai");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
       t=1;
       printf(CYAN"\nQ3 .Who is known as the father of indian nuclear programme?"RESET);
       printf("\n\t1:APJ Abdual Kalam\t\t3:Homi J Bhabha");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }
      
      if(game[i].ans[j]==3)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.3"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ4 .Which of the following regional cinema referred to as Kollywood? "RESET);
       printf("\n\t1: Punjabi Cinema\t\t2:Tamil Cinema\n\t3:Kannada Cinema\t\t\t4:Malayalam Cinema");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ4 .Which of the following regional cinema referred to as Kollywood? "RESET);
       printf("\n\t2:Tamil Cinema\t\t3:Kannada Cinema");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg)); 
      return 0;
      }
//##############################################
      printf(ORANGE"\nQ5 .Who has won the Rajiv Gandhi Khel Ratna Award 2019? "RESET);
      printf("\n\t1:.Sakshi Malik\t\t2:Mirabai Chanu\n\t3:.Bajrang Punia\t\t\t4:.Rohit sharma");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ5 .Who has won the Rajiv Gandhi Khel Ratna Award 2019?"RESET);
       printf("\n\t3:Bajrang Punia\t\t4:Rohit sharma ");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==3)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.3"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
      break;
//########################################################//
//########################################################//    
  case 4: i++;
          j=0;
          flg=0;
          

   printf(ORANGE"\nQ1 .What is the National Bird of India?"RESET);
          printf("\n\t1:Peacock\t\t\t\t2:Kingfisher\n\t3:Bald Eagle \t\t\t4:Parrot");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if (game[i].ans[j]==0)
      { 
       t++;
       printf(CYAN"\nQ1 .What is the National Bird of India?"RESET);
       printf("\n\t1:Peacock\t\t4:Parrot");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==1)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.1"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ2 .Who is the first Deputy Prime Minister of India?"RESET);
       printf("\n\t1:G L Nanda\t\t\t\t2:Devi Lal\n\t3: Charan Singh\t\t\t4:Vallabhbhai Patel");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ2 .Who is the first Deputy Prime Minister of India? "RED);
       printf("\n\t3:Charan Singh  \t\t4:Vallabhbhai Patel");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==4)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
       game[i].scre=score(flg);
       printf("\n\tTotal no. of coins earned = %d\n",score(flg));
   
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.4"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
     
      return 0;
      }

//##############################################
      printf(ORANGE"\nQ3 .India's first supercomputer is known as?"RESET);
      printf("\n\t1: SAGA\t\t\t2:PARAM 8000 \n\t3: EKA \t\t\t4:PARAM YUVA");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
       t=1;
       printf(CYAN"\nQ3 .India's first supercomputer is known as?"RESET);
       printf("\n\t2:PARAM 8000\t\t4:PARAM YUVA");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }
      
      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      
      }
   else 
      {
     printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ4 .First Indian movie submitted for Oscar?"RESET);
       printf("\n\t1:The Guide\t\t2:Mother India\n\t3:Madhumati\t\t\t4: Amrapali");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ4 .First Indian movie submitted for Oscar?"RESET);
       printf("\n\t1:The Guide\t\t2:Mother India");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg)); 
      return 0;
      }
//##############################################
      printf(ORANGE"\nQ5 .who has won the first medal in Tokyo Olympics 2020 for India?"RESET);
      printf("\n\t1:.P V sindhu\t\t2: Mirabai chanun\n\t3:Atanu Das\t\t\t4:Mary kom");                    
      
                          
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ5 .Who has won the first medal in Tokyo Olympics 2020 for India?"RESET);
       printf("\n\t1:P V Sindhu\t\t2:Mirabai Chanu");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
      break;
//#######################################################//
//#######################################################//
      case 5: i++;
          j=0;
          flg=0;
          

          printf(ORANGE"\nQ1 .What is the National Tree of India?"RESET);
          printf("\n\t1: Tamarind Tree\t\t2: Banyan Tree\n\t3:Neem Tree \t\t\t4:Peepal Tree");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if (game[i].ans[j]==0)
      { 
       t++;
       printf(ORANGE"\nQ1 .What is the National Tree of India?"RESET);
       printf("\n\t2:Banyan Tree\t\t3:Neem Tree");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!\n"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET); 
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ2 .In which state, the President's Rule was first imposed in India?"RESET);
       printf("\n\t1:Andhra Pradesh\t\t2:Bihar\n\t3: Assam \t\t\t\t4:Arunachal Pradesh");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ2 .In which state, the President's Rule was first imposed in India?"RESET);
       printf("\n\t1:Andhra Pradesh   \t\t2:Bihar");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==1)
      {
      printf("\n\tYou are Right!!\n");
      flg++;//flg gives no.of questions answered correctly.
       game[i].scre=score(flg);
       printf("\n\tTotal no. of coins earned = %d\n",score(flg));
   
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.1"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
     
      return 0;
      }

//##############################################
      printf(ORANGE"\nQ3 .ISRO was formed in?"RESET);
      printf("\n\t1:1963 \t\t\t\t2:1969 \n\t3: 1972 \t\t\t4:1985");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
       t=1;
       printf(CYAN"\nQ3 .ISRO was formed in?"RESET);
       printf("\n\t1:1963\t\t2:1969");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }
      
      if(game[i].ans[j]==2)
      {
      printf(ORANGE"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
//##############################################
       printf(ORANGE"\nQ4 .Who among the following made first Film Theatre of India? "RESET);
       printf("\n\t1:Lumiere Brothers \t\t\t2:Mani Sethna \n\t3:Dada Saheb Phalke\t\t\t4:Dhirendra Nath Ganguly ");                    
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ4 .Who among the following made first Film Theatre of India ? "RESET);
       printf("\n\t2:Mani Sethna t\t3:Dada Saheb Phalke");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      }
   else 
      {
      printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg)); 
      return 0;
      }
//##############################################
      printf(ORANGE"\nQ5 .Which one of the following ports is the oldest port in India? "RESET);
      printf("\n\t1:Mumbai Port\t\t\t2:Chennai Port  \n\t3:Kolkata Port\t\t\t4:.Vishakhapatnam Port");                    
      
                          
       j++;              
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);

       if(game[i].ans[j]==0 && t==0)
      {
        t=1;
       printf(CYAN"\nQ5 .Which one of the following ports is the oldest port in India? "RESET);
       printf("\n\t1:Mumbai Port\t\t2:Chennai Port");
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
      }

       if(game[i].ans[j]==0)
       {
       printf(RED"\n\tYou can use 50-50 only once in a game"RESET);
       printf(GREEN"\n\tAns = "RESET);
       scanf("%d", &game[i].ans[j]);
       }

      if(game[i].ans[j]==2)
      {
      printf(GREEN"\n\tYou are Right!!"RESET);
      flg++;//flg gives no.of questions answered correctly.
      game[i].scre=score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
   else 
      {
     printf(RED"\n\n\t\tWrong Answer"ORANGE"\ncorrect answer"RESET"==>"GREEN"option no.2"RESET);
      printf("\n\n\tTotal no. of coins earned = %d\n",score(flg));
      return 0;
      }
      break;        
  
  }
  
  return 0;
}