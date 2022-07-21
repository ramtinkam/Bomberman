#include "home.h"

home::home()
{
    player1Text = new textField(100,150);
    player2Text = new textField(100,150);
    lives = new textField(100,150);
    auto label1 = new label;
    auto label2 = new label;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(0,0,1920,1080,this);
    label1->setPos(640,520);
    label1->setPlainText("player1:");
    label2->setPos(1280,520);
    label2->setPlainText("player2:");
    player1Text->setPos(640,540);
    player2Text->setPos(1280,540);
    lives->setPos(960,540);



    QFile file{"setting.txt"};
    if(!file.exists()){
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out<<"player\nguest\n3";
        file.flush();
        file.close();
    }
    file.open(QIODevice::ReadOnly);


    QTextStream in(&file);

    QString a=in.readLine();
    player1Text->setPlainText(a);
    player2Text->setPlainText(in.readLine());
    lives->setPlainText(in.readLine());

    file.close();


    scene->addItem(label1);
    scene->addItem(label2);
    scene->addItem(player1Text);
    scene->addItem(player2Text);
    scene->addItem(lives);
    scene->setBackgroundBrush(QColor("gray"));
    auto Button = new button;
    Button->setPos(860,800);
    scene->addItem(Button);
    setScene(scene);
    connect(Button,&button::pressed,this,&home::gameStart);
}

void home::gameStart()
{
    auto name1 = player1Text->toPlainText();
    auto name2 = player2Text->toPlainText();
    double live = lives->toPlainText().toDouble();
    close();
    QFile file{"setting.txt"};
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<name1<<"\n"<<name2<<"\n"<<live;
    file.flush();
    file.close();
    auto game = new Game;
    game->control->player1->name=name1;
    game->control->player2->name=name2;
    game->control->player1->health=live;
    game->control->player2->health=live;
    game->control->player1->playerInfo->setPlainText(game->control->player1->name+": "+QString::number(game->control->player1->health,'f'));
    game->control->player2->playerInfo->setPlainText(game->control->player2->name+": "+QString::number(game->control->player2->health,'f'));
    game->show();

}
