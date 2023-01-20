#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include <conio.h>
#include<windows.h>


using namespace std;

class cell
{

    int x;
    int y;
    char type; // O-Obstacle, G-Gem,C-Champion
    char ObsType;
    char GemType;
public:
    cell()
    {
        x = 0;
        y = 0;
        type = '.';

    }

    char getType()
    {

        return this->type;

    }

    int getX()
    {

        return this->x;

    }

    int getY()
    {

        return this->y;

    }

    void setX(int x)
    {

        this->x = x;

    }

    void setY(int y)
    {

        this->y = y;

    }

    void setType(char type)
    {
        this->type= type;
    }

    char getObsType(){
    return this->ObsType;
    }
    void setObsType(char T){
    this->ObsType = T;
    }
    char getGemType(){
    return this->GemType;
    }
    void setGemType(char X){
    this->GemType=X;
    }

    bool isThief(){
   if(this->getObsType()=='T'){
    return true;
   }
   return false;

    }

    bool isBomb(){
   if(this->getObsType()=='B'){
    return true;
   }
   return false;

    }

    bool isCoin(){

    if(this->getGemType()=='C'){

        return true;
    }
    return false;
    }

    bool isPotion(){

    if(this->getGemType()=='P'){

        return true;
    }
    return false;
    }








};



class Champion:public cell
{
private:

    int health;
    int xCoor;
    int yCoor;
    int gemsScore;
    bool gameStarted;
    char Type;
    int RemainingAbilityCounter; // 2time counter
    bool AbilityFlag = false;
    bool AbilityInUse;

public:
   Champion()
    {
        health=100;
        xCoor=0;
        yCoor=0;
        gemsScore=0;
        RemainingAbilityCounter=2;
        gameStarted=false;
        AbilityInUse=false;
      cout<<"Constructor champion() is called"<<endl;

    }


    virtual void useAbility()
    {


    }

    bool getAbilityinUse(){
    return this->AbilityInUse;
    }
    void setAbilityInUse(bool idk){
    this->AbilityInUse= idk;
    }


    int getAbilityCounter()
    {
        return this->RemainingAbilityCounter;
    }
    void setAbilityCounter(int x)
    {
        this->RemainingAbilityCounter= x;
    }


    int getHealth()
    {
        return this->health;
    }
    int getxCoor()
    {
        return this->xCoor;
    }
    int getyCoor()
    {
        return this->yCoor;
    }
    int getGemsScore()
    {
        return this->gemsScore;
    }


    void setGemScore(int x)
    {
        this->gemsScore=x;
    }
    void setHealth(int x)
    {
        this->health=x;
    }



    void moveUp()
    {
        if(this->yCoor+1>9)
        {
            cout<<"out of bounds";
        }
        else
            this->yCoor++;
    }
    void moveDown()
    {
        if(this->yCoor-1<0)
        {
            cout<<"out of bounds";
        }
        else
            this->yCoor--;
    }
    void moveLeft()
    {
        if(this->xCoor-1<0)
        {
            cout<<"out of bounds";
        }
        else
            this->xCoor--;
    }
    void moveRight()
    {


        if(this->xCoor+1>9)
        {
            cout<<"out of bounds";
        }
        else
        {
            this->xCoor++;
        }
    }



    void gameover(bool flag, int HighScore)
    {
        if(this->health <= 0)
        {
            cout<<"GAME OVER , BETTER LUCK NEXT TIME (LOSER) " << endl ;
            exit(0);
        }
        if(flag)
        {
            cout<<"CONGRATS YOU DID IT!! YOU GOT A FINAL SCORE OF : " <<HighScore <<endl ;
            exit(0);
        }


    }





};


class Mario: public Champion
{
public:

   Mario(){

cout<<"MARIO"<<endl;
   }

    void useAbility()
    {
        this->setAbilityCounter(this->getAbilityCounter()-1);

this->setAbilityInUse(false);
        cout<<"Mario Ability is called!"<<endl;

    }




};


class Luigi:public Champion
{
public:

    Luigi(){

   }

    void useAbility()
    {

this->setAbilityCounter(this->getAbilityCounter()-1);

this->setAbilityInUse(false);




    }

};


class Gem:public cell
{
public:
    int points;
    char GemType;




    Gem()
    {


        srand(time(0));
        this->points = rand() % (11 - 5) + 5;


    }


    void setPoints(int newPoints)
    {
        this->points = newPoints;

    }

    int getPoints()
    {
        return points;
    }

    void execute(Champion c)
    {

        cout<<"Gem execute is called ";
    }






};

class Potion : public Gem
{

public:
   char GemType = 'P';

    Potion()
    {

        cout<<"constructor potion is called()"<<endl;
        cout<<"Potion points : "<< this->points<<endl;


    }
    void execute(Champion* c)
    {
        if(c->getHealth()+ this->getPoints()>100){
            c->setHealth(100);
            cout<<"Potion executed with" << " "<<this->getPoints()<<" points"<<endl;

        }
        else{
            c->setHealth(c->getHealth()+this->getPoints());
        cout<<"Potion executed with" << " "<<this->getPoints()<<" points"<<endl;
        }






    }






};

class Coin : public Gem
{


public:
    char GemType = 'C';
    void execute(Champion* c)
    {

        cout<<"Coin executed with points = "<<this->getPoints()<<endl;

        c->setGemScore(c->getGemsScore() + this->points);


    }


};


class Obstacle : public cell
{

public:
    int dmgAmount;
    char ObsType;//BOMB OR THEIF

    Obstacle()
    {

        srand(time(0));
        this->dmgAmount = rand() % (6 - 1) + 1;

    }

    void execute(Champion* c)
    {


    }
    char getObsType(){
    return this->ObsType;
    }
    void setObsType(char T){
    this->ObsType = T;
    }
    bool isThief(){
   if(this->getObsType()=='T'){
    return true;
   }
   return false;

    }

    bool isBomb(){
   if(this->getObsType()=='B'){
    return true;
   }
   return false;

    }






};

class Bomb : public Obstacle
{
public:
    char ObsType = 'B';
    Bomb()
    {


    }

    void execute(Champion* c)
    {

        if((c->getHealth()-this->dmgAmount)<=0)
        {
           c->gameover(false,c->getGemsScore());
        }
        else if((c->getHealth()-this->dmgAmount)>0)
        {
            c->setHealth(c->getHealth()-this->dmgAmount);
            cout<<"Bomb executed with damage = "<<this->dmgAmount<<endl;

        }

    }


};

class Theif : public Obstacle
{
public:
     char ObsType = 'T';
    Theif()
    {


    }

    int getDmgAmount(){
    return this->dmgAmount;
    }

    void execute(Champion* c)
    {



         if((c->getGemsScore()-this->dmgAmount)<=0)
        {

            if(c->getGemsScore()>=0){

            while(c->getGemsScore()!=0 && this->dmgAmount!=0){

                c->setGemScore(c->getGemsScore()-1);
                this->dmgAmount--;
            }

            cout<<"Thief tried to steal you but found out that you are broke ahaha , he still took all you had sadly "<<endl;
            }


        }
        else if((c->getGemsScore()-this->dmgAmount)>0)
        {


            c->setGemScore(c->getGemsScore()-this->dmgAmount);
            cout<<"Theif executed with damage = "<<this->dmgAmount<<endl;
        }


    }





};








class Map
{

public:
    int rows = 10;
    int columns = 10;
    cell** board;
    int stolenGems;
    int totalGemCount = 40;

    Map()
    {
        board= new cell*[columns] ;
        for(int i = 0 ; i<rows; i++)
        {
            board[i] = new cell[10];
        }

        cout<<"Constructor map() called"<<endl;

        RandomizeMap();
    }
    int getTotalGemCount(){
    return this->totalGemCount;
    }
    void setGemCount(int x){
    this->totalGemCount = x;
    }


    int getStolenGems(){
    return this->stolenGems;
    }
    void setStolenGems(int stolen){
        this->stolenGems = stolen;
    }

    void freeMapUp(){

    for(int i = 9;i>=0;i--){
        for(int j = 0 ; j<10;j++){
            this->board[i][j].setType('.');
        }

    }
    }



    void placeGems()
    {

        srand(time(NULL));
        int PotionCondition = 20;
        int CoinCondition = 20;


        while(PotionCondition!=0)
        {
            int i = (rand() % 10) ;
            int j = (rand() % 10) ;

            if(board[i][j].getType() == '.' && (i!=0&&j!=0))
            {

                board[i][j].setType((char)4 );
                board[i][j].setGemType('P');
                PotionCondition--;

            }

        }

        while(CoinCondition!=0)
        {
            int i = (rand() % 10) ;
            int j = (rand() % 10) ;

            if(i==0&&j==0)
            {
                continue;
            }

            if(board[i][j].getType() == '.' )
            {

                board[i][j].setType((char)4 );
                board[i][j].setGemType('C');
                CoinCondition--;

            }

        }


    }

    void placeObstacles()
    {


        srand(time(NULL));
        int bombCondition = 10;
        int theifCondition = 10;



        while(bombCondition!=0)
        {
            int i = (rand() % 10) ;
            int j = (rand() % 10) ;


            if(board[i][j].getType() == '.' && (i!=0&&j!=0))
            {

                board[i][j].setType('O');
                board[i][j].setObsType('B');



                bombCondition--;

            }

        }

        while(theifCondition!=0)
        {
            int i = (rand() % 10) ;
            int j = (rand() % 10) ;
            if(i==0&&j==0)
            {
                continue;
            }

            if(board[i][j].getType() == '.' )
            {

                board[i][j].setType('O');
                board[i][j].setObsType('T');

                theifCondition--;

            }

        }



    }

    void placeChampion()
    {


        board[0][0] = Champion();
        board[0][0].setType('C');

    }

    void printMap()
    {

        for(int i = 9 ; i>=0; i--)
        {

            for(int j = 0; j<10; j++)
            {

                cout<<this->board[j][i].getType() ;


            }
            cout<<endl;

        }

        cout<<"8- To move up"<<endl;
        cout<<"6- To move right"<<endl;
        cout<<"5- To move down"<<endl;
        cout<<"4- To move left"<<endl;




    }

    void RandomizeMap()
    {

        freeMapUp();
        placeChampion();
        placeGems();
        placeObstacles();



    }


    void GemHelper(int x, int y ,Champion* c){


if(board[x][y].isCoin()){

                    Coin *x = new Coin();
                    x->execute(c);



                    }







                 else if(board[x][y].isPotion()){


                    Potion *x = new Potion();

                    x->execute(c);
                    c->setGemScore(c->getGemsScore()+1);


                 }

    }


    void ObstacleHelper(int x,int y ,Champion* c){


    if(board[x][y].isThief()){
            cout<<"ENTERED THIEF AREA"<<endl;

                    Theif *x = new Theif();


                    if(c->getGemsScore()-x->getDmgAmount()>0){
                             x->execute(c);
                             this->setGemCount(this->getTotalGemCount()-this->getStolenGems());
                        this->setStolenGems(this->getStolenGems()+x->getDmgAmount());


                    }
                    if(c->getGemsScore()-x->getDmgAmount()<=0){


                    if(c->getGemsScore()>0){

                     x->execute(c);
                           //this->setGemCount((this->getTotalGemCount()-this->getStolenGems()));

                         this->setStolenGems(this->getStolenGems()+c->getGemsScore());




                  }



                    }






                 }
                 else if(board[x][y].isBomb()){


                    Bomb *x = new Bomb();

                    x->execute(c);


                 }

    }


    void print_champ_info(Champion* c)
    {
        cout<<"-------------CHAMPION DETAILS------------"<<endl;
        cout<<"Health : "<<c->getHealth()<<endl;
        cout<<"Champion location is"<<"["<<c->getxCoor()<<","<<c->getyCoor()<<"]"<<endl;
        if(c->getType()=='L'){
            cout<<"Champion is Luigi"<<endl;
        }
        else if(c->getType()=='M'){
            cout<<"Champion is Mario"<<endl;
        }
        int GemCounter= 0;
        bool flag = false;

        for(int i = 0 ; i<10;i++){

            for(int j = 0 ; j<10;j++){
                if(this->board[i][j].getType()==(char)(4)){
                    GemCounter++;
                }
            }
        }

        cout<<"Gems remaining to collect : "<< GemCounter <<endl;
        cout<<"Gems collected by champion : "<<c->getGemsScore()<<endl;

        if(c->getAbilityCounter()>0){
            cout<<"PRESS X (Capital) FOR ACTIVATING YOUR ABILITY"<<endl;
        }
        cout<<"Remaining ability uses : "<<c->getAbilityCounter()<<endl;

//        cout<<"8- To move up"<<endl;
//        cout<<"6- To move right"<<endl;
//        cout<<"5- To move down"<<endl;
//        cout<<"4- To move left"<<endl;
cout<<"----------------------------------------"<<endl;
        if(GemCounter==0||c->getGemsScore()>=GemCounter){
                flag = true;
                system("cls");
            c->gameover(flag,c->getGemsScore());
        }







    }




    void updateMap(int x, int y, int Oldx, int Oldy,bool AbilityUsed,Champion* c ,string DirectionL)

    {
        system("cls");


        if(c->getType()=='M'&&AbilityUsed){


            c->useAbility();

             if(DirectionL == "RIGHT")              //clear right
            {

               c->moveRight();
               c->moveRight();
               x = c->getxCoor();
               y=c->getyCoor();

              if(board[x][y].getType()=='O'){
                               ObstacleHelper(x,y,c);

              }
              else if(board[x][y].getType()==(char)(4)){
                GemHelper(x,y,c);
              }
               board[x][y].setType('C');
               board[Oldx][Oldy].setType('.');


            }
            else if(DirectionL == "LEFT")         //clear left
            {

                c->moveLeft();
               c->moveLeft();
               x = c->getxCoor();
               y=c->getyCoor();


             if(board[x][y].getType()=='O'){
                               ObstacleHelper(x,y,c);

              }
              else if(board[x][y].getType()==(char)(4)){
                GemHelper(x,y,c);
              }

               board[x][y].setType('C');
               board[Oldx][Oldy].setType('.');

               }


            else if (DirectionL == "DOWN")         //clear down
            {

                 c->moveDown();
               c->moveDown();
               x = c->getxCoor();
               y=c->getyCoor();

                if(board[x][y].getType()=='O'){
                               ObstacleHelper(x,y,c);

              }

else if(board[x][y].getType()==(char)(4)){
                GemHelper(x,y,c);
              }

               board[x][y].setType('C');
               board[Oldx][Oldy].setType('.');

               }


            else if (DirectionL == "UP")         //clear up
            {

              c->moveUp();
               c->moveUp();
               x = c->getxCoor();
               y=c->getyCoor();
                if(board[x][y].getType()=='O'){
                               ObstacleHelper(x,y,c);

              }
              else if(board[x][y].getType()==(char)(4)){
                GemHelper(x,y,c);
              }
               board[x][y].setType('C');
               board[Oldx][Oldy].setType('.');


            }


        }




        if(c->getType()=='L' && AbilityUsed)
        {

            c->useAbility();





            if(DirectionL == "RIGHT")              //clear right
            {

                for(int i = Oldx; i<=9; i++)
                {

                    if(board[i][Oldy].getType()=='O')
                    {
                        board[i][Oldy].setType('.');
                    }

                }
                board[Oldx][Oldy].setType('C');
            }
            else if(DirectionL == "LEFT")         //clear left
            {

                for(int i = Oldx; i>=0; i--)
                {

                    if(board[i][Oldy].getType()=='O')
                    {
                        board[i][Oldy].setType('.');
                    }
                }

            }

            else if (DirectionL == "DOWN")         //clear down
            {

                for(int i = Oldy; i>=0; i--)
                {

                    if(board[Oldx][i].getType()=='O')
                    {
                        board[Oldx][i].setType('.');
                    }
                }


            }
            else if (DirectionL == "UP")         //clear up
            {

                for(int i = Oldy; i<=9; i++)
                {

                    if(board[Oldx][i].getType()=='O')
                    {
                        board[Oldx][i].setType('.');
                    }
                }


            }


        }

        if(!AbilityUsed){



        if(board[x][y].getType() == (char)(4))
        {
            //c->setGemScore(c->getGemsScore()+1);
            GemHelper(x,y,c);
            board[x][y].setType('C');
            board[Oldx][Oldy].setType('.');
        }
        else if(board[x][y].getType()=='O')
        {

            ObstacleHelper(x,y,c);
            board[x][y].setType('C');
            board[Oldx][Oldy].setType('.');
        }
        else if(board[x][y].getType()=='.')
        {
            board[x][y].setType('C');
            board[Oldx][Oldy].setType('.');
        }

        }

        print_champ_info(c);
    }


        };









void gameStarted(Map* m,Champion* c){

int oldx;
int oldy;
cout<<"GAME STARTED";





        //c->startGame();
	    system("cls");
		m->printMap();

		//m.print_mov();






    while(c->getHealth()!=0){



    char AbilityButtonListener;
    int ASCII;
    AbilityButtonListener=getch();
    ASCII=AbilityButtonListener;
    if(ASCII==88){
            if(c->getAbilityCounter()>0){

           cout<<"ABILITY ACTIVATED"<<endl;
            char AbilityKeyPress;
            int direction;
            AbilityKeyPress=getch();
            direction=AbilityKeyPress;
      c->setAbilityInUse(true);
      if(direction== 56){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;



		//c->moveUp();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c,"UP");
		//system("cls");
		m->printMap();




}
else if(direction==53){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;
		//c->moveDown();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c,"DOWN");
		//system("cls");
		m->printMap();






}
else if(direction==54){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;
		//c->moveRight();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c,"RIGHT");
		//system("cls");
		m->printMap();

}
else if(direction==52){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;
		//c->moveLeft();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c,"LEFT");
		//system("cls");
		m->printMap();




}
else{

    cout<<"wrong input,do better";
}
            }

            else{
                cout<<"YOU CAN ONLY USE SPECIAL ABILITY TWICE"<<endl;
            }



      }

else if (ASCII!=88){



char key_press;
int Direction;

    //key_press=getch();
    Direction=ASCII;


if(Direction== 56){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;



		c->moveUp();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c," ");
	//	system("cls");
		m->printMap();




}
else if(Direction==53){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;
		c->moveDown();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c," ");
		//system("cls");
		m->printMap();






}
else if(Direction==54){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;
		c->moveRight();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c," ");
		//system("cls");
		m->printMap();

}
else if(Direction==52){
		oldx = c->getxCoor() ;
		oldy = c->getyCoor() ;
		c->moveLeft();
		m->updateMap(c->getxCoor(),c->getyCoor() , oldx , oldy,c->getAbilityinUse(),c," ");
		//system("cls");
		m->printMap();




}
else{

    cout<<"wrong input,do better";
}






}
}
}


void mapChoice(Map* m,Champion* c){

system("cls");
m->printMap();
cout<<"Would you like to randomize the map again 1 for yes 0 for no"<<endl;
char x;
int y;
here :

	do {



    x=getch();
    y=x;
while(y==49){
	  system("cls");



    m->RandomizeMap();
    m->printMap();


     cout<<"Would you like to randomize the map again 1 for yes 0 for no"<<endl;
    x=getch();
    y=x;



}


if(y==48){
gameStarted(m,c);

}

}

while(y == 49 || y == 48);
goto here;

}

void helper(Map* m , Champion* c){
int oldx ;
int oldy ;






}

void chooseChamp(Map m){

    Map *mapPtr;
    mapPtr=&m;

cout << "Welcome to the game" << endl;
    cout << " You have two champions to choose from  press M for Mario and L for Luigi" << endl;
    char x;
    int y;
here :
    do {


        x=getch();
        y=x;
        if(y==109){
            Mario *ptr;
            Mario M;
            ptr = &M;
            ptr->setType('M');

            mapChoice(mapPtr,ptr); // helper function for Mario  it will make applying the abilities less messy and easier to debug and trace
        }else if(y==108){

            Luigi *ptr;
            Luigi L;
            ptr = &L;
            ptr->setType('L');

            mapChoice(mapPtr,ptr);
             // helper for Luigi bc he has a different ability will ake in error in printing the map
        }
        else{
            cout<<"wrong input,do better";
        }
    } while (y != 109 && y != 108);
    //goto here;



}





int main()
{
    Map m;




     chooseChamp(m);

    m.printMap();





}






