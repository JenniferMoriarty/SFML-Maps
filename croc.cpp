//2D matrix in SFML
#include<iostream>
using namespace std;


#include "SFML/Graphics.hpp"

int main() {
    srand(time(NULL));
    //create 40x40 map, use nested loop to initalize with 0s
    int map[40][40];
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++)
            map[i][j] = 0;
    }


    int x, y, h, w, offset;

    //for (int m = 0; m < 10; m++) {
    // 
    offset = 0;
    //pick random center point (x and y)
    x = rand() % 40;
    y = rand() % 40;
    //pick a random height (b/t -10 and 10)
    h = rand() % 20 + 10;
    //print out contents of variables for testing.
    cout << "variables are " << x << " , " << y << " , and " << h << endl;


    //offset += rand() % 1 - 1;

    for (int i = y; i < y + h; i++) {
        offset += (rand() % 3 - 3);

        cout << "offset is " << offset << endl;
        for (int j = x; j < x + (rand() % 15 + 5); j++) { //set new random width each time
            //check to make sure we're not walking off the array
            if (i > 40 || j > 40) {
                cout << "too big, skipping," << endl;
                break;
            }
            else {

                map[j + offset][i] = 1; //set as grass block!
                cout << "setting " << i << " ,  " << j << " to grass block." << endl;
            }
        }
    }
    // }
    map[x][y] = 2;
    cout << "done with randomizer algorithm" << endl;

    //game set up (you'll need these two lines in every game)
    sf::RenderWindow renderWindow(sf::VideoMode(800, 800), "map"); //set up screen
    sf::Event event; //set up event queue


   //set up blocks
    sf::RectangleShape waterBlock(sf::Vector2f(20, 20));
    waterBlock.setFillColor(sf::Color::Blue);
    sf::RectangleShape grassBlock(sf::Vector2f(20, 20));
    grassBlock.setFillColor(sf::Color::Green);
    sf::RectangleShape desertBlock(sf::Vector2f(20, 20));
    desertBlock.setFillColor(sf::Color::Yellow);



    //###################GAME LOOP###############################################################

    while (renderWindow.isOpen()) {//keep window open until user shuts it down

        while (renderWindow.pollEvent(event)) { //look for events-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();

        }//end event loop---------------------------------------------------------------


        //render loop for map
        for (int i = 0; i < 40; i++) { //rows
            for (int j = 0; j < 40; j++) //columns
                if (map[i][j] == 0) { //water is default
                    waterBlock.setPosition(i * 20, j * 20);
                    renderWindow.draw(waterBlock);
                }
                else if (map[i][j] == 1) {//grass block
                    grassBlock.setPosition(i * 20, j * 20);
                    renderWindow.draw(grassBlock);
                }
        }


        renderWindow.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end game
