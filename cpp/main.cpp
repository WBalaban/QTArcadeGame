#include <QApplication>
#include <memory>
#include "gamewindow.h"

Gamewindow * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //std::shared_ptr<Gamewindow> game(new Gamewindow());

    game = new Gamewindow();  // smart pointery, testy, polimorfizm
    game->show();
    return a.exec();
}
