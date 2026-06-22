#include <iostream>
using namespace std;

class Grid
{
protected:
    char grid[10][10];

public:
    Grid()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                grid[i][j]='.';
            }
        }

        // Obstacles
        grid[1][2]='X';
        grid[2][2]='X';
        grid[3][4]='X';
        grid[5][5]='X';
        grid[6][3]='X';

        // Destination
        grid[9][9]='D';
    }

    void display()
    {
        cout<<"\nGRID\n\n";

        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

class Robot : public Grid
{
protected:
    int x,y;
    int steps;

public:

    Robot()
    {
        x=0;
        y=0;
        steps=0;

        grid[x][y]='R';

        cout<<"Robot Initialized"<<endl;
    }

    virtual void move()
    {
        cout<<"Robot Moving"<<endl;
    }

    virtual ~Robot()
    {
        cout<<"\nSimulation Finished"<<endl;
    }
};

class SmartRobot : public Robot
{
public:

    void move()
    {
        while(x!=9 || y!=9)
        {
            grid[x][y]='.';

            // Move Right
            if(y<9 && grid[x][y+1]!='X')
            {
                y++;
                cout<<"Moving Right"<<endl;
            }

            // Otherwise Move Down
            else if(x<9 && grid[x+1][y]!='X')
            {
                x++;
                cout<<"Moving Down"<<endl;
            }

            // Obstacle Handling
            else
            {
                cout<<"Obstacle Found! Searching Alternate Path..."<<endl;

                if(x<9)
                    x++;
                else if(y<9)
                    y++;
            }

            steps++;

            if(x==9 && y==9)
            {
                grid[x][y]='R';
                break;
            }

            grid[x][y]='R';

            display();

            cout<<"--------------------------"<<endl;
        }

        cout<<"\nDestination Reached Successfully"<<endl;
        cout<<"Total Steps : "<<steps<<endl;
    }
};

int main()
{
    SmartRobot robot;

    cout<<"\nInitial Grid\n";

    robot.display();

    cout<<"\nRobot Starts...\n";

    robot.move();

    cout<<"\nFinal Grid\n";

    robot.display();

    return 0;
}
