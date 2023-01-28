#include "mainwindow.h"
#include "menu.h"
#include "food.h"
#include "drink.h"

#include "library.h"
#include "manga.h"
#include "dvd.h"
#include "series.h"
#include "videogame.h"

#include <QApplication>
//#include <iostream>

int main(int argc, char *argv[]){

    Menu d;
    Food* banana = new Food("banana", "/home/leonardo/Downloads/lul.png", 13.0, true);
    Food* apple = new Food("apple", "/home/leonardo/Downloads/lul.png", 5.0);
    Food* donut = new Food("donut", "/home/leonardo/Downloads/lul.png", 7.0);
    Food* ap = new Food("ap", "/home/leonardo/Downloads/lul.png", 1.2);
    Drink* coca = new Drink("coca", "/home/leonardo/Downloads/lul.png", 2.6);
    Drink* ac = new Drink("ac", "/home/leonardo/Downloads/lul.png", 4.2);
    d.add(coca);
    d.add(banana);
    d.add(ap);
    d.add(donut);
    d.add(apple);
    d.add(ac);
    //d.sort();
    //std::cout << d;

    Library l;
    Manga* haikyu = new Manga("haikyu", "haikyu.png", "pallavolo" ,2, "bo", 134, 1, shounen);
    Manga* naruto = new Manga("naruto", "naruto.png", "samurai", 4, "qualcuno", 200, 1, shounen);
    Manga* onepiece = new Manga("onepiece", "onepiece.png", "pirati", 3, "oda", 160, 1, shounen);
    Dvd* avatar = new Dvd("avatar", "avatar.png", "persone blu", 1, "boh", 200);
    Dvd* avengers = new Dvd("avengers", "avengers.png", "heroes", 2, "marvel", 150);
    Series* friends = new Series("friends", "friends.png", "amici", 1, "sfs", 40, 80);
    Videogame* lol = new Videogame("lol", "lol.png", "touch grass", 1, "rito game", 3);
    Videogame* genshin = new Videogame("genshin", "genshin.png", "waifu", 8, "hoyoverse", 7);
    Videogame* osu = new Videogame("osu", "osu.png", "epilessia", 3, "ppy", 3);
    l.add(haikyu);
    l.add(naruto);
    l.add(onepiece);
    l.add(avatar);
    l.add(avengers);
    l.add(friends);
    l.add(lol);
    l.add(genshin);
    l.add(osu);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
