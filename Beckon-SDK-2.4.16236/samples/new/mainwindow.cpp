#include "mainwindow.h"
#include "blockitem.h"
#include "hiscoresdialog.h"
#include "Shadow/ISensor.h"
#include "Shadow/IMotionSensor.h"
#include "GestureDemo.h"

using namespace std;
using namespace Omek;

//#include <ctime>

const bool CHEAT = false;
//const bool CHEAT = true;

// chosen as the standard full screen landscape resolution of Nokia 5800, X6, N97, N8, etc
// other resolutions will be scaled
const int scene_w_c = 640;
const int scene_h_c = 360;

//const int scene_w_c = 502;
//const int scene_h_c = 288;
/*const int scene_w_c = 2*502;
const int scene_h_c = 2*288;*/

const int bat_w_c = 64;
const int bat_h_c = 16;
/*const int bat_w_c = 490;
const int bat_h_c = 270;*/

const int ball_w_c = 16;
const int ball_h_c = ball_w_c;

const int ball_initial_sp_x_c = 4;
const int ball_initial_sp_y_c = 6;
const int max_ball_sp_x_c = 10;
const int bullet_sp_c = 8;
const int bat_sp_x_c = 24;

const int max_hiscore_entries_c = 10;


OptionsGamestate::OptionsGamestate(MainWindow *mainWindow) :
        Gamestate(mainWindow)
{
}

OptionsGamestate::~OptionsGamestate() {
    qDebug("~OptionsGamestate");
}

void OptionsGamestate::clickedStart() {
    qDebug("start");
    Gamestate *gamestate = new PlayingGamestate(mainWindow);
    mainWindow->setGamestate(gamestate);
    //gamestate->start();
    //this->deleteLater();
}

void OptionsGamestate::clickedHiscores() {
    qDebug("hiscores");
    /*QString text = "Hi-Scores\n\n";
    text += "\tName\tScore\tLevel\n\n";
    int c=0;
    foreach(Hiscore hiscore, mainWindow->getHiscores()) {
        text += QString::number(c) + "\t" + hiscore.getName() + "\t" + hiscore.getScore() + "\t" + hiscore.getLevel();
        c++;
    }
    QMessageBox::about(mainWindow, tr("Hi-Scores"), text);*/
    HiscoresDialog hiscoresDialog(mainWindow);
    hiscoresDialog.showFullScreen();
    hiscoresDialog.exec();
}

void OptionsGamestate::clickedAbout() {
    qDebug("about");
    QString text = tr("QBall\n\nby Mark Harman");
    QMessageBox::about(mainWindow, tr("About QBall"), text);
}

void OptionsGamestate::clickedHelp() {
    qDebug("help");
    QDesktopServices::openUrl(QUrl(tr("http://homepage.ntlworld.com/mark.harman/comp_qball.html")));
}

void OptionsGamestate::clickedExit() {
    qDebug("exit");
    qApp->exit();
}

void OptionsGamestate::start() {
    QWidget *centralWidget = new QWidget(mainWindow);
    centralWidget->setContextMenuPolicy(Qt::NoContextMenu); // explicitly forbid usage of context menu so actions item is not shown menu
    mainWindow->setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout();
    centralWidget->setLayout(layout);

    QLabel *titleLabel = new QLabel(tr("QBall"));
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    QPushButton *startButton = new QPushButton(tr("Start a new game"));
    layout->addWidget(startButton);
    connect(startButton, SIGNAL(clicked()), this, SLOT(clickedStart()));
    //this->initButton(prevButton);

    QPushButton *hiscoresButton = new QPushButton(tr("Hi-Scores"));
    layout->addWidget(hiscoresButton);
    connect(hiscoresButton, SIGNAL(clicked()), this, SLOT(clickedHiscores()));

    QPushButton *aboutButton = new QPushButton(tr("About"));
    layout->addWidget(aboutButton);
    connect(aboutButton, SIGNAL(clicked()), this, SLOT(clickedAbout()));

    QPushButton *helpButton = new QPushButton(tr("Online help"));
    layout->addWidget(helpButton);
    connect(helpButton, SIGNAL(clicked()), this, SLOT(clickedHelp()));

    QPushButton *exitButton = new QPushButton(tr("Exit"));
    layout->addWidget(exitButton);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(clickedExit()));
}

void OptionsGamestate::stop() {
    delete mainWindow->centralWidget();
    mainWindow->setCentralWidget(NULL);
}

void OptionsGamestate::registerScore(int score, int level) {
    if( score <= 0 )
        return;
    if( mainWindow->getHiscores().size() >= max_hiscore_entries_c ) {
        // check we get onto the board
        Hiscore lastHiscore = mainWindow->getHiscores().at(max_hiscore_entries_c-1);
        if( score < lastHiscore.getScore() ||
            ( score == lastHiscore.getScore() && level <= lastHiscore.getLevel() ) ) {
            return;
        }
    }
    //QWidget *enterHiscoreWindow = new QWidget(mainWindow);
    QDialog *enterHiscoreWindow = new QDialog(mainWindow);
    QVBoxLayout *layout = new QVBoxLayout();
    enterHiscoreWindow->setLayout(layout);

    QLineEdit *nameEdit = NULL;
    {
        QString text = "You scored " + QString::number(score) + "!  Enter your name:";
        QLabel *scoreLabel = new QLabel(text);
        layout->addWidget(scoreLabel);
    }
    /*{
        QLabel *label = new QLabel("Enter your name:");
        layout->addWidget(label);
    }*/
    {
        nameEdit = new QLineEdit("");
        layout->addWidget(nameEdit);
        /*QHBoxLayout *h_layout = new QHBoxLayout();
        layout->addLayout(h_layout);
        QLabel *nameLabel = new QLabel(tr("Enter Name:"));
        h_layout->addWidget(nameLabel);
        nameEdit = new QLineEdit("");
        h_layout->addWidget(nameEdit);*/
    }
    layout->addStretch();
    {
        QPushButton *okayButton = new QPushButton("Okay");
        layout->addWidget(okayButton);
        connect(okayButton, SIGNAL(clicked()), enterHiscoreWindow, SLOT(accept()));
    }

    enterHiscoreWindow->showFullScreen();
    enterHiscoreWindow->exec();

    QString name = nameEdit->text();
    qDebug("Entered name: %s", name.toStdString().c_str());
    Hiscore hiscore(name, score, level);
    this->mainWindow->addHiscore(hiscore);

    delete enterHiscoreWindow;
}

PlayingGamestate::PlayingGamestate(MainWindow *mainWindow) :
        Gamestate(mainWindow),
        gameTime(0),
        scene(NULL), view(NULL),
        paused(false),
        itemBat(NULL), itemBall(NULL),
        itemScore(NULL), itemLives(NULL), itemLevel(NULL),
        itemPause(NULL), itemQuit(NULL),
        //hitSound(NULL),
        ball_sp_x(0), ball_sp_y(0),
        bat_has_target(false), bat_target_x(0),
        score(0), lives(3), level(1),
        level_complete(false),
        has_message(false), message_pauses(false), message_start_time(0), itemMessage(NULL),
        bonus_fireball(false), bonus_fireball_start_time(0), bonus_bullets(false), bonus_bullets_start_time(0), bullets_fire_start_time(0)
{
    //level = 4;
}

PlayingGamestate::~PlayingGamestate() {
}

void PlayingGamestate::start() {
    scene = new QGraphicsScene(mainWindow);
    scene->setSceneRect(0, 0, scene_w_c, scene_h_c);
    //scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    view = new QGraphicsView(scene, mainWindow);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setBackgroundBrush(QBrush(Qt::black)); // n.b., even though black is default, this is needed to avoid bug on Nokia 5800 where background isn't updated!
    view->setFrameStyle(QFrame::NoFrame);
    view->setFocusPolicy(Qt::NoFocus); // so clicking doesn't take focus away from the main window

    /*QRadialGradient backgroundGrad(QPointF(scene_w_c/2, scene_h_c/2), scene_h_c/2);
    backgroundGrad.setColorAt(0, QColor(127, 0, 0));
    backgroundGrad.setColorAt(1, QColor(31, 0, 0));
    scene->setBackgroundBrush(QBrush(backgroundGrad));*/

    QPixmap backgroundPixmap(scene_w_c, scene_h_c);
    backgroundPixmap.fill(Qt::black);
    QPainter backgroundPainter(&backgroundPixmap);
    backgroundPainter.setPen(QPen(Qt::NoPen));
    const int n_stars_c = 128;
    for(int i=0;i<n_stars_c;i++) {
        int xpos = rand() % scene_w_c;
        int ypos = rand() % scene_h_c;
        int bright = rand() % 256;
        /*backgroundPainter.setPen(QPen(QColor(bright, bright, bright/2)));
        backgroundPainter.drawPoint(xpos, ypos);*/
        const int point_w_c = 2;
        QRadialGradient pointGrad(QPointF(0, 0), point_w_c);
        pointGrad.setColorAt(0, QColor(bright, bright, bright));
        pointGrad.setColorAt(1, QColor(bright, bright, 0));
        backgroundPainter.setBrush(QBrush(pointGrad));
        backgroundPainter.drawRect(xpos, ypos, point_w_c, point_w_c);
    }
    scene->setBackgroundBrush(QBrush(backgroundPixmap));

    view->setCacheMode(QGraphicsView::CacheBackground);

    mainWindow->setCentralWidget(view);
    //view->showMaximized();
    view->showFullScreen();
    qDebug("Is transformed? %d", view->isTransformed());
    //view->fitInView(0, 0, scene_w_c-4, scene_h_c-2, Qt::KeepAspectRatio);
    //view->fitInView(0, 0, scene_w_c-1, scene_h_c-1, Qt::IgnoreAspectRatio);
    //view->scale(((float)view->width())/((float)scene_w_c), ((float)view->height())/((float)scene_h_c));
    this->resizeEvent(NULL);
    qDebug("Is transformed? %d", view->isTransformed());
    //view->resize(200, 200);
    qDebug("view size: %d x %d", view->width(), view->height());
    //qDebug("scene size: %d x %d", scene->width(), scene->height());
    /*QGraphicsTextItem *textItem = scene->addText(QString::number(view->width()) + ", " + QString::number(view->height()));
    textItem->setPos(16, 16);
    textItem->setDefaultTextColor(Qt::white);*/

    //scene->addRect(0, 0, mainWindow->width()-1, mainWindow->height()-1, QPen(Qt::white));
    scene->addRect(0, 0, scene->width()-1, scene->height()-1, QPen(Qt::white));
    //scene->addLine(0, 0, 0, 100, QPen(Qt::white));
    //scene->addLine(scene->width(), 0, scene->width(), 100, QPen(Qt::white));
    //scene->addLine(scene->width()-1, 0, scene->width()-1, 100, QPen(Qt::white));

    //itemBall = scene->addEllipse(0, 0, ball_w_c, ball_h_c, QPen(Qt::white), QBrush(Qt::white, Qt::SolidPattern));
    itemBall = scene->addEllipse(0, 0, ball_w_c, ball_h_c, QPen(Qt::NoPen), QBrush(Qt::white));
    setBallColor();

    QLinearGradient linearGradBat(0, 0, 0, bat_h_c);
    linearGradBat.setColorAt(0, Qt::white);
    linearGradBat.setColorAt(1, Qt::gray);
    //itemBat = scene->addRect(0, 0, bat_w_c, bat_h_c, QPen(Qt::NoPen), QBrush(Qt::white));
    itemBat = scene->addRect(0, 0, bat_w_c, bat_h_c, QPen(Qt::NoPen), QBrush(linearGradBat));

    initBallAndBat(false);

    initLevel();

    itemScore = scene->addText("");
    itemScore->setZValue(1.0);
    QFont font = itemScore->font();
    qDebug("font size: %d", font.pointSize());
#if defined(Q_WS_QWS)
    font.setPointSize(20);
#else
    font.setPointSize(8);
#endif
    itemScore->setFont(font);
    itemScore->setPos(16, 16);
    itemScore->setDefaultTextColor(Qt::yellow);
    this->changeScore(0); // initialise text

    itemLives = scene->addText("");
    itemLives->setZValue(1.0);
    itemLives->setFont(font);
    itemLives->setPos(176, 16);
    itemLives->setDefaultTextColor(Qt::yellow);
    this->changeLives(0); // initialise text

    itemLevel = scene->addText("");
    itemLevel->setZValue(1.0);
    itemLevel->setFont(font);
    itemLevel->setPos(296, 16);
    itemLevel->setDefaultTextColor(Qt::yellow);
    this->changeLevel(0); // initialise text

    itemQuit = scene->addText("QUIT");
    itemQuit->setZValue(1.0);
    itemQuit->setFont(font);
    itemQuit->setPos(16, 64);
    itemQuit->setDefaultTextColor(Qt::white); // needed for Windows

    itemPause = scene->addText("PAUSE");
    itemPause->setZValue(1.0);
    itemPause->setFont(font);
    itemPause->setPos(16, 112);
    itemPause->setDefaultTextColor(Qt::white); // needed for Windows

    //hitSound = new QSound(":/sounds/pulse808bd.wav", this);
    //hitSound = new QSound(":/sounds/77245__StudioCopsey__Power_Up.wav", this);

}

void PlayingGamestate::stop() {
    delete scene;
    scene = NULL;
    delete mainWindow->centralWidget();
    view = NULL;
    mainWindow->setCentralWidget(NULL);
}

void PlayingGamestate::setBallColor() {
    QRadialGradient radialGrad(QPointF(0, 0), ball_w_c);
    radialGrad.setColorAt(0, Qt::white);
    if( this->bonus_fireball )
        radialGrad.setColorAt(1, QColor(255, 127, 0));
    else
        radialGrad.setColorAt(1, Qt::red);
    itemBall->setBrush(QBrush(radialGrad));
}

void PlayingGamestate::initBallAndBat(bool lost_life) {
    itemBall->setPos((scene_w_c-ball_w_c)/2, 225);
    ball_sp_x = ball_initial_sp_x_c;
    if( rand() % 2 == 1 )
        ball_sp_x = - ball_initial_sp_x_c;
    ball_sp_y = ball_initial_sp_y_c;

    itemBat->setPos((scene_w_c-bat_w_c)/2, scene_h_c - 2*bat_h_c);
    bat_has_target = false;

    if( lives == 1 && lost_life )
        this->setMessage("Last Ball!", true);
    else
        this->setMessage("Get Ready!", true);
}

const int n_blocks_x = 8;
const int n_blocks_y = 6;
const int x_offset = (scene_w_c - n_blocks_x * block_w_c)/2;
const int y_offset = block_h_c;

int PlayingGamestate::indexHash(qreal x, qreal y) {
    Q_ASSERT( x >= x_offset && x < x_offset + n_blocks_x * block_w_c );
    Q_ASSERT( y >= y_offset && y < y_offset + n_blocks_y * block_h_c );
    int n_x = (x - x_offset) / block_w_c;
    int n_y = (y - y_offset) / block_h_c;
    Q_ASSERT( n_x >= 0 && n_x < n_blocks_x );
    Q_ASSERT( n_y >= 0 && n_y < n_blocks_y );
    int index = n_y * n_blocks_x + n_x;
    return index;
    //return 0;
}

BlockItem *PlayingGamestate::blockAt(qreal x, qreal y) {
    if( x < x_offset || x >= x_offset + n_blocks_x * block_w_c )
        return NULL;
    if( y < y_offset || y >= y_offset + n_blocks_y * block_h_c )
        return NULL;
    int index = indexHash(x, y);
    BlockItem *blockItem = blocksHashMap[index];
    return blockItem;
}

void PlayingGamestate::initLevel() {
    //level = 12;
    this->bonus_fireball = false;
    setBallColor(); // reset ball color
    this->bonus_bullets = false;
    // delete any bullets
    foreach(QGraphicsItem *bullet, bullets) {
        delete bullet;
    }
    bullets.clear();

    // delete any left-over blocks (brick)
    foreach(QGraphicsItem *block, blocks) {
        delete block;
    }
    blocks.clear();
    blocksHashMap.clear();

    // setup new level
    QString levelData = "";
    const int max_levels_c = 12;
    int mlevel = (level-1) % max_levels_c;
    if( mlevel == 0 ) {
        levelData += "bbbbbbbb";
        levelData += "rrrpgrrr";
        levelData += "rrrrrrrr";
        levelData += "   w    ";
        levelData += "        ";
        levelData += "        ";
    }
    else if( mlevel == 1 ) {
        levelData += " b bb b ";
        levelData += "bbbbbbbb";
        levelData += "rorrrrwr";
        levelData += "rrrrrrrr";
        levelData += "        ";
        levelData += "        ";
    }
    else if( mlevel == 2 ) {
        levelData += " w bb g ";
        levelData += "   bb   ";
        levelData += "rrrbbrrr";
        levelData += "rrrbbrrr";
        levelData += "   bb   ";
        levelData += " p    p ";
    }
    else if( mlevel == 3 ) {
        levelData += "        ";
        levelData += "bbbbbbbb";
        levelData += "rrrpgrrr";
        levelData += "orrrrrro";
        levelData += "xxxxxxxx";
        levelData += "        ";
    }
    else if( mlevel == 4 ) {
        levelData += "bbbbbbbb";
        levelData += "rrrrrrrr";
        levelData += " w   o  ";
        levelData += " p   p  ";
        levelData += "rrrrrrrr";
        levelData += "bbbbbbbb";
    }
    else if( mlevel == 5 ) {
        levelData += "b      b";
        levelData += "b  xx  b";
        levelData += "b  gp  b";
        levelData += "bb rr bb";
        levelData += " b    b ";
        levelData += " bbprbb ";
    }
    else if( mlevel == 6 ) {
        levelData += " b   bb ";
        levelData += " xx  xx ";
        levelData += "    r   ";
        levelData += "    x  r";
        levelData += " r     x";
        levelData += " x      ";
    }
    else if( mlevel == 7 ) {
        levelData += " b b b b";
        levelData += "b brbrb ";
        levelData += " brbobrb";
        levelData += "b brbrb ";
        levelData += " b b b b";
        levelData += "b b b b ";
    }
    else if( mlevel == 8 ) {
        levelData += "prbrbrbg";
        levelData += "brbrbrbr";
        levelData += "brbrbrbr";
        levelData += "brbrbrbr";
        levelData += "wrbrbrbo";
        levelData += "xrxrxrxr";
    }
    else if( mlevel == 9 ) {
        levelData += " p    p ";
        levelData += " r pp r ";
        levelData += " w pp w ";
        levelData += " r pp r ";
        levelData += " w pp w ";
        levelData += " p    p ";
    }
    else if( mlevel == 10 ) {
        levelData += "rorororo";
        levelData += "orororor";
        levelData += "pppppppp";
        levelData += "bbbbbbbb";
        levelData += "rrrrrrrr";
        levelData += "xxxxxxxx";
    }
    else if( mlevel == 11 ) {
        levelData += "xrrrxorr";
        levelData += "xrxbxbxr";
        levelData += "xrxoxbxr";
        levelData += "xrxgxbxr";
        levelData += "xpxbbbxr";
        levelData += "xoxxxxxr";
    }
    /*else if( mlevel ==  ) {
        levelData += "        ";
        levelData += "        ";
        levelData += "        ";
        levelData += "        ";
        levelData += "        ";
        levelData += "        ";
    }*/
    qDebug("levelData length: %d", levelData.length());
    Q_ASSERT(levelData.length() == n_blocks_x * n_blocks_y);

    QLinearGradient linearGradRed(0, 0, block_w_c, block_h_c);
    linearGradRed.setColorAt(0, Qt::red);
    linearGradRed.setColorAt(1, Qt::darkRed);
    QLinearGradient linearGradBlue(0, 0, block_w_c, block_h_c);
    linearGradBlue.setColorAt(0, Qt::blue);
    linearGradBlue.setColorAt(1, Qt::darkBlue);
    QLinearGradient linearGradGreen(0, 0, block_w_c, block_h_c);
    linearGradGreen.setColorAt(0, Qt::green);
    linearGradGreen.setColorAt(1, Qt::darkGreen);
    QLinearGradient linearGradPurple(0, 0, block_w_c, block_h_c);
    linearGradPurple.setColorAt(0, QColor(255, 0, 255));
    linearGradPurple.setColorAt(1, QColor(127, 0, 127));
    QLinearGradient linearGradOrange(0, 0, block_w_c, block_h_c);
    linearGradOrange.setColorAt(0, QColor(255, 165, 0));
    linearGradOrange.setColorAt(1, QColor(127, 82, 0));
    QLinearGradient linearGradBrown(0, 0, block_w_c, block_h_c);
    linearGradBrown.setColorAt(0, QColor(150, 75, 0));
    linearGradBrown.setColorAt(1, QColor(75, 37, 0));
    QLinearGradient linearGradYellow(0, 0, block_w_c, block_h_c);
    linearGradYellow.setColorAt(0, Qt::yellow);
    linearGradYellow.setColorAt(1, Qt::darkYellow);
    QLinearGradient linearGradWhite(0, 0, block_w_c, block_h_c);
    linearGradWhite.setColorAt(0, Qt::white);
    linearGradWhite.setColorAt(1, Qt::gray);

    //const int x_offset = 0;
    //const int y_offset = 0;
    for(int y=0,c=0;y<n_blocks_y;y++) {
        int ypos = y_offset + y * block_h_c;
        for(int x=0;x<n_blocks_x;x++,c++) {
            QChar ch = levelData.at(c);
            if( ch == ' ' ) {
                // skip
            }
            else {
                int xpos = x_offset + x * block_w_c;
                //QGraphicsItem *block = scene->addRect(0, 0, block_w_c-2, block_h_c-2, QPen(Qt::NoPen), QBrush(Qt::red));
                //QGraphicsItem *block = scene->addRect(0, 0, block_w_c, block_h_c, QPen(Qt::NoPen), QBrush(linearGrad));
                BlockItem *itemBlock = NULL;
                if( ch == 'r' ) {
                    itemBlock = new BlockItem(QBrush(linearGradRed));
                }
                else if( ch == 'b' ) {
                    itemBlock = new BlockItem(QBrush(linearGradBlue));
                    itemBlock->setScore(10);
                }
                else if( ch == 'g' ) {
                    itemBlock = new BlockItem(QBrush(linearGradGreen));
                    itemBlock->setScore(0);
                    itemBlock->setBlockType(BlockItem::BLOCKTYPE_EXTRALIFE);
                }
                else if( ch == 'p' ) {
                    itemBlock = new BlockItem(QBrush(linearGradPurple));
                    itemBlock->setScore(20);
                    itemBlock->setBlockType(BlockItem::BLOCKTYPE_FASTBALL);
                }
                else if( ch == 'o' ) {
                    itemBlock = new BlockItem(QBrush(linearGradOrange));
                    itemBlock->setScore(0);
                    itemBlock->setBlockType(BlockItem::BLOCKTYPE_FIREBALL);
                }
                else if( ch == 'x' ) {
                    itemBlock = new BlockItem(QBrush(linearGradBrown));
                    itemBlock->setScore(0);
                    itemBlock->setBlockType(BlockItem::BLOCKTYPE_BRICK);
                }
                else if( ch == 'y' ) {
                    itemBlock = new BlockItem(QBrush(linearGradYellow));
                    itemBlock->setScore(100);
                    itemBlock->setBlockType(BlockItem::BLOCKTYPE_EXPLOSION);
                }
                else if( ch == 'w' ) {
                    itemBlock = new BlockItem(QBrush(linearGradWhite));
                    itemBlock->setScore(100);
                    itemBlock->setBlockType(BlockItem::BLOCKTYPE_BULLETS);
                }
                Q_ASSERT( itemBlock != NULL );
                itemBlock->setPos(xpos, ypos);
                scene->addItem(itemBlock);
                blocks.push_back(itemBlock);
                Q_ASSERT( this->blockAt(xpos, ypos) == NULL );
                blocksHashMap.insert(this->indexHash(xpos, ypos), itemBlock);
                Q_ASSERT( this->blockAt(xpos, ypos) != NULL );
                //qDebug("type: %d", itemBlock->type());
            }
        }
    }

}

void PlayingGamestate::setMessage(const QString &text, bool message_pauses) {
    if( has_message ) {
        delete itemMessage;
    }
    has_message = true;
    this->message_pauses = message_pauses;
    itemMessage = scene->addText(text);
    QFont font = itemMessage->font();
    font.setPointSize(24);
    itemMessage->setFont(font);
    itemMessage->setPos((scene->width() - itemMessage->boundingRect().width())/2, (scene->height() - itemMessage->boundingRect().height())/2);
    itemMessage->setDefaultTextColor(Qt::green);
    itemMessage->setZValue(1.0);
    message_start_time = gameTime;
    //message_time.start();
}

void PlayingGamestate::updateScene() {
    if( paused ) {
        return;
    }
    //return;

    gameTime += time_per_frame_c;

    if( this->has_message ) {
        //if( this->message_time.elapsed() > 1500 ) {
        if( gameTime - this->message_start_time > 1500 ) {
            delete this->itemMessage;
            this->has_message = false;
            if( lives <= 0 ) {
                qDebug("game over");
                OptionsGamestate *gamestate = new OptionsGamestate(mainWindow);
                mainWindow->setGamestate(gamestate);
                gamestate->registerScore(this->score, this->level);
            }
            else if( level_complete ) {
                qDebug("level complete");
                level_complete = false;
                this->changeLevel(1);
                this->initBallAndBat(false);
                this->initLevel();
                this->changeScore(100);
            }
        }
        if( this->message_pauses )
            return;
    }

    const int bonus_time_c = 10000;
    //if( this->bonus_fireball && this->bonus_fireball_time.elapsed() > bonus_time_c ) {
    if( this->bonus_fireball && gameTime - this->bonus_fireball_start_time > bonus_time_c ) {
        this->bonus_fireball = false;
        setBallColor(); // reset ball color
    }
    //if( this->bonus_bullets && this->bonus_bullets_time.elapsed() > bonus_time_c ) {
    if( this->bonus_bullets && gameTime - this->bonus_bullets_start_time > bonus_time_c ) {
        this->bonus_bullets = false;
    }

    // move ball
    //itemBall->moveBy(ball_sp_x, ball_sp_y);

    // collide with boundaries
    QPointF pos = itemBall->pos();
    if( pos.x() + ball_w_c >= scene->width() ) {
        itemBall->setPos(scene->width()-1-ball_w_c, pos.y());
        ball_sp_x = - ball_sp_x;
        //hitSound->play();
    }
    else if( pos.x() < 0 ) {
        itemBall->setPos(0, pos.y());
        ball_sp_x = - ball_sp_x;
        //hitSound->play();
    }
    if( pos.y() < 0 ) {
        itemBall->setPos(pos.x(), 0);
        ball_sp_y = - ball_sp_y;
        //hitSound->play();
    }
    pos = itemBall->pos(); // update in case pos changed

    // lose life
    if( pos.y() + ball_h_c >= scene->height() ) {
        if( CHEAT ) {
            itemBall->setPos(pos.x(), scene->height()-1-ball_h_c);
            ball_sp_y = - ball_sp_y;
        }
        else {
            this->changeLives(-1);
            if( lives > 0 ) {
                this->initBallAndBat(true);
            }
            else {
                this->setMessage("Game Over!", true);
            }
        }
    }

    // collide with bat
    // check speed to see if moving towards bat
    // check y range of bat
    if( ball_sp_y > 0 && (pos.y() + ball_h_c >= itemBat->pos().y()) &&
        (pos.y() + ball_h_c <= itemBat->pos().y() + bat_h_c) ) {
        // check x range of bat
        if( pos.x() + ball_w_c >= itemBat->pos().x() && pos.x() <= itemBat->pos().x() + bat_w_c ) {
            qDebug("ball hits bat");
            //hitSound->play();
            ball_sp_y = - ball_sp_y;
            /*int r = rand() % 3;
            if( r == 0 ) {
                ball_sp_x--;
            }
            else if( r == 1 ) {
                ball_sp_x++;
            }*/
            const float side_frac_c = 0.3f;
            if( pos.x() + ball_w_c/2 <= itemBat->pos().x() + side_frac_c*bat_w_c ) {
                // hit left side
                qDebug("hit left side");
                ball_sp_x--;
            }
            else if( pos.x() + ball_w_c/2 >= itemBat->pos().x() + (1.0f-side_frac_c)*bat_w_c ) {
                // hit right side
                qDebug("hit right side");
                ball_sp_x++;
            }
            ball_sp_x = qMin(ball_sp_x, max_ball_sp_x_c);
            ball_sp_x = qMax(ball_sp_x, -max_ball_sp_x_c);
            if( ball_sp_x == 0 ) {
                // avoid directly going up/down
                ball_sp_x = ((rand() % 2) == 0) ? -1 : 1;
            }
            itemBall->setPos(pos.x(), itemBat->pos().y() - bat_h_c);
            pos = itemBall->pos(); // update
        }
    }

    bool deleted_any_blocks = false;
    // collide with blocks
    QList<QGraphicsItem *> collideBall = scene->collidingItems(itemBall);
    if( collideBall.size() > 0 ) {
        //qDebug("collided:");
        QPointF topPos = itemBall->pos() + QPointF(ball_w_c/2, 0);
        QPointF bottomPos = itemBall->pos() + QPointF(ball_w_c/2, ball_h_c);
        QPointF leftPos = itemBall->pos() + QPointF(0, ball_h_c/2);
        QPointF rightPos = itemBall->pos() + QPointF(ball_w_c, ball_h_c/2);
        QPointF topleftPos = itemBall->pos();
        QPointF toprightPos = itemBall->pos() + QPointF(ball_w_c, 0);
        QPointF bottomleftPos = itemBall->pos() + QPointF(0, ball_h_c);
        QPointF bottomrightPos = itemBall->pos() + QPointF(ball_w_c, ball_h_c);
        foreach(QGraphicsItem *item, collideBall) {
            if( item->type() == CUSTOMITEMTYPE_BLOCK ) {
                qDebug("    hit block");
                BlockItem *blockItem = static_cast<BlockItem *>(item);
                bool hit = false;
                if( !this->bonus_fireball || blockItem->getBlockType() == BlockItem::BLOCKTYPE_BRICK ) {
                    bool hitsTop = item->contains(item->mapFromScene(topPos));
                    if( hitsTop ) {
                        qDebug("        top");
                        hit = true;
                        if( ball_sp_y < 0 )
                            ball_sp_y = - ball_sp_y;
                        //itemBall->moveBy(0, ball_h_c);
                        //itemBall->setPos(itemBall->pos().x(), blockItem->pos().y() + block_h_c);
                    }
                    bool hitsBottom = item->contains(item->mapFromScene(bottomPos));
                    if( hitsBottom ) {
                        qDebug("        bottom");
                        hit = true;
                        if( ball_sp_y > 0 )
                            ball_sp_y = - ball_sp_y;
                        //itemBall->moveBy(0, -ball_h_c);
                        //itemBall->setPos(itemBall->pos().x(), blockItem->pos().y());
                    }
                    bool hitsLeft = item->contains(item->mapFromScene(leftPos));
                    if( hitsLeft ) {
                        qDebug("        left");
                        hit = true;
                        if( ball_sp_x < 0 )
                            ball_sp_x = - ball_sp_x;
                        //itemBall->moveBy(ball_w_c, 0);
                        //itemBall->setPos(blockItem->pos().x() + block_w_c, itemBall->pos().y());
                    }
                    bool hitsRight = item->contains(item->mapFromScene(rightPos));
                    if( hitsRight ) {
                        qDebug("        right");
                        hit = true;
                        if( ball_sp_x > 0 )
                            ball_sp_x = - ball_sp_x;
                        //itemBall->moveBy(-ball_w_c, 0);
                        //itemBall->setPos(blockItem->pos().x(), itemBall->pos().y());
                    }
                    /*if( !hit ) {
                        // must have hit a corner
                        hit = true;
                        if( item->contains(item->mapFromScene(topleftPos)) ) {
                            qDebug("        topleft");
                            if( ball_sp_y < 0 )
                                ball_sp_y = - ball_sp_y;
                            if( ball_sp_x < 0 )
                                ball_sp_x = - ball_sp_x;
                            //itemBall->moveBy(ball_w_c, ball_h_c);
                        }
                        else if( item->contains(item->mapFromScene(toprightPos)) ) {
                            qDebug("        topright");
                            if( ball_sp_y < 0 )
                                ball_sp_y = - ball_sp_y;
                            if( ball_sp_x > 0 )
                                ball_sp_x = - ball_sp_x;
                            //itemBall->moveBy(-ball_w_c, ball_h_c);
                        }
                        else if( item->contains(item->mapFromScene(bottomleftPos)) ) {
                            qDebug("        bottomleft");
                            if( ball_sp_y > 0 )
                                ball_sp_y = - ball_sp_y;
                            if( ball_sp_x < 0 )
                                ball_sp_x = - ball_sp_x;
                            //itemBall->moveBy(ball_w_c, -ball_h_c);
                        }
                        else if( item->contains(item->mapFromScene(bottomrightPos)) ) {
                            qDebug("        bottomright");
                            if( ball_sp_y > 0 )
                                ball_sp_y = - ball_sp_y;
                            if( ball_sp_x > 0 )
                                ball_sp_x = - ball_sp_x;
                            //itemBall->moveBy(-ball_w_c, -ball_h_c);
                        }
                    }*/
                }
                else {
                    hit = true;
                }
                if( hit ) {
                    //hitSound->play();
                    if( hitBlock(blockItem) ) {
                        deleted_any_blocks = true;
                    }
                }
            }
        }
    }

    // move bullets
    const int bullet_size_c = 8;
    QList<QGraphicsItem *> killList;
    foreach(QGraphicsItem *bullet, bullets) {
        bullet->moveBy(0, -bullet_sp_c);
        bool kill_bullet = false;
        if( bullet->pos().y() + bullet_size_c < 0 ) {
            kill_bullet = true;
        }
        else {
            // using QSceneGraphics to do collision detection is slow (on Nokia 5800), even with BSP - better to use our own hashmap
            //qDebug("n items: %d", scene->items().size());
            //QList<QGraphicsItem *> collideBullet = scene->collidingItems(bullet);
            //foreach(QGraphicsItem *item, scene->items()) {
            /*foreach(QGraphicsItem *item, this->blocks) {
                bool collide = item->collidesWithItem(bullet);
            }*/

            /*QList<QGraphicsItem *> collideBullet = scene->items(QPointF(bullet->pos().x(), bullet->pos().y()));
            if( collideBullet.size() > 0 ) {
                foreach(QGraphicsItem *item, collideBullet) {
                    if( item->type() == CUSTOMITEMTYPE_BLOCK ) {
                        qDebug("    bullet hit block");
                        kill_bullet = true;
                        BlockItem *blockItem = static_cast<BlockItem *>(item);
                        if( hitBlock(blockItem) ) {
                            deleted_any_blocks = true;
                        }
                    }
                }
            }*/
            /*foreach(BlockItem *blockItem, blocks) {
                if( blockItem->collidesWithItem(bullet) ) {
                    qDebug("    bullet hit block");
                    kill_bullet = true;
                    if( hitBlock(blockItem) ) {
                        deleted_any_blocks = true;
                    }
                }
            }*/
            BlockItem *blockItem = this->blockAt(bullet->pos().x(), bullet->pos().y());
            if( blockItem != NULL ) {
                //bool collide = blockItem->collidesWithItem(bullet);
                qDebug("    bullet hit block");
                kill_bullet = true;
                if( hitBlock(blockItem) ) {
                    deleted_any_blocks = true;
                }
            }
            else {
                blockItem = this->blockAt(bullet->pos().x() + bullet_size_c - 1, bullet->pos().y());
                if( blockItem != NULL ) {
                    //bool collide = blockItem->collidesWithItem(bullet);
                    qDebug("    bullet hit block");
                    kill_bullet = true;
                    if( hitBlock(blockItem) ) {
                        deleted_any_blocks = true;
                    }
                }
            }
        }
        if( kill_bullet ) {
            killList.push_back(bullet);
        }
    }
    foreach(QGraphicsItem *bullet, killList) {
        bullets.removeOne(bullet);
        delete bullet;
    }

    if( this->bonus_bullets ) {
        //if( this->bullet_fire_time.elapsed() >= 500 /*&& this->bullets.size() < 4*/ ) {
        if( gameTime - this->bullets_fire_start_time >= 500 ) {
            // fire new bullet
            QRadialGradient radialGrad(QPointF(0, 0), bullet_size_c);
            radialGrad.setColorAt(0, Qt::white);
            radialGrad.setColorAt(1, Qt::yellow);
            QGraphicsItem *bullet = scene->addEllipse(0, 0, bullet_size_c, bullet_size_c, QPen(Qt::NoPen), QBrush(radialGrad));
            bullet->setPos(itemBat->pos().x() + bat_w_c/2 - bullet_size_c/2, itemBat->pos().y() - bullet_size_c);
            this->bullets.push_back(bullet);
            //this->bullet_fire_time.start();
            this->bullets_fire_start_time = gameTime;
        }
    }

    // input
    /*qDebug("mouse buttons: %d", qApp->mouseButtons());
    if( qApp->mouseButtons() & Qt::LeftButton ) {
        qDebug("mouse is pressed");
    }*/

    // move
    fuckmain();
    if (fuck1==1 && fuck==1){fuck1=0;fuck=0;}
    if( fuck1==1 ) {
        bat_has_target = false;
        itemBat->moveBy(-bat_sp_x_c, 0);
        if( itemBat->pos().x() < 0 ) {
            itemBat->setPos(0, itemBat->pos().y());
        }
    }
    if (fuck==1){
        bat_has_target = false;
        itemBat->moveBy(bat_sp_x_c, 0);
        if( itemBat->pos().x() > scene->width() - bat_w_c ) {
            itemBat->setPos(scene->width() - bat_w_c, itemBat->pos().y());
        }
    }

    if( mainWindow->isKeyDownLeft() ) {
        bat_has_target = false;
        itemBat->moveBy(-bat_sp_x_c, 0);
        if( itemBat->pos().x() < 0 ) {
            itemBat->setPos(0, itemBat->pos().y());
        }
    }
    else if( mainWindow->isKeyDownRight() ) {
        bat_has_target = false;
        itemBat->moveBy(bat_sp_x_c, 0);
        if( itemBat->pos().x() > scene->width() - bat_w_c ) {
            itemBat->setPos(scene->width() - bat_w_c, itemBat->pos().y());
        }
    }
    else if( bat_has_target ) {
        int bat_centre_x = itemBat->pos().x() + bat_w_c/2;
        int dist = abs(bat_centre_x - bat_target_x);
        if( dist <= bat_sp_x_c ) {
            itemBat->setPos(bat_target_x - bat_w_c/2, itemBat->pos().y());
            bat_has_target = false;
        }
        else {
            int dir = bat_target_x > bat_centre_x ? 1 : -1;
            itemBat->moveBy(dir * bat_sp_x_c, 0);
        }
    }

    if( deleted_any_blocks ) {
        // check for level complete
        bool any_blocks = false;
        foreach(QGraphicsItem *item, scene->items()) {
            if( item->type() == CUSTOMITEMTYPE_BLOCK ) {
                BlockItem *blockItem = static_cast<BlockItem *>(item);
                if( blockItem->getBlockType() != BlockItem::BLOCKTYPE_BRICK ) {
                    any_blocks = true;
                    break;
                }
            }
        }
        if( !any_blocks ) {
            level_complete = true;
            this->setMessage("Level Completed!", true);
        }
    }
}

bool PlayingGamestate::userQuit() {
    bool old_paused = paused;
    paused = true;
    if( QMessageBox::question(this->mainWindow, "QBall", "Are you sure you wish to quit?", QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok ) {
        qDebug("quit");
        OptionsGamestate *gamestate = new OptionsGamestate(mainWindow);
        mainWindow->setGamestate(gamestate);
        // don't register score
        return true;
    }
    paused = old_paused;
    return false;
}

void PlayingGamestate::mousePressEvent(QMouseEvent *event) {
    if( view == NULL )
        return;
    int m_x = event->x();
    int m_y = event->y();
    if( m_x >= view->x() && m_x < view->x() + view->width() && m_y >= view->y() && m_y < view->y() + view->height() ) {
        int vm_x = m_x - view->x();
        int vm_y = m_y - view->y();
        QPointF scenePos = view->mapToScene(vm_x , vm_y);
        int sm_x = scenePos.x();
        int sm_y = scenePos.y();
        qDebug("clicked view: %d, %d", vm_x, vm_y);
        qDebug("clicked scene: %d, %d", sm_x, sm_y);
        if( sm_y > itemBat->y() - 2*bat_h_c && !paused ) {
            /*QPointF pos = itemBat->pos();
            const int bat_sp_x_c = 4;
            if( sm_x < itemBat->x() ) {
                pos.rx() -= bat_sp_x_c;
                itemBat->setPos(pos);
            }
            else if( sm_x >= itemBat->x() + bat_w_c ) {
                pos.rx() += bat_sp_x_c;
                itemBat->setPos(pos);
            }*/
            bat_has_target = true;
            bat_target_x = sm_x;
            if( bat_target_x - bat_w_c/2 < 0 )
                bat_target_x = bat_w_c/2;
            else if( bat_target_x - bat_w_c/2 + bat_w_c >= scene->width() )
                bat_target_x = scene->width() - 1 + bat_w_c/2 - bat_w_c;
        }
        else if( itemPause->contains(itemPause->mapFromScene(QPointF(sm_x, sm_y))) ) {
            paused = !paused;
        }
        else if( itemQuit->contains(itemQuit->mapFromScene(QPointF(sm_x, sm_y))) ) {
            if( this->userQuit() ) {
                return;
            }
        }
        //qDebug("rect: %d, %d", itemQuit->boundingRect().x(), itemQuit->boundingRect().y());
    }
}

void PlayingGamestate::resizeEvent(QResizeEvent *event) {
    if( view != NULL ) {
        //qDebug("OLD: %d x %d", view->width(), view->height());
        //view->showMaximized();
        //qDebug("NEW: %d x %d", view->width(), view->height());
        //qDebug("scene: %f x %f", scene->width(), scene->height());
        view->resetTransform();
        //view->scale(((float)view->width())/scene->width(), ((float)view->height())/scene->height());
        float scale_x = ((float)view->width())/((float)scene_w_c);
        float scale_y = ((float)view->height())/((float)scene_h_c);
        float scale = qMin(scale_x, scale_y);
        view->scale(scale, scale);
    }
}

bool PlayingGamestate::hitBlock(BlockItem *blockItem) {
    this->changeScore(blockItem->getScore());
    switch( blockItem->getBlockType() ) {
    case BlockItem::BLOCKTYPE_EXTRALIFE:
        this->setMessage("Extra Life!", false);
        this->changeLives(1);
        break;
    case BlockItem::BLOCKTYPE_FASTBALL:
        this->setMessage("Fastball!", false);
        ball_sp_x = ball_sp_x > 0 ? max_ball_sp_x_c : -max_ball_sp_x_c;
        break;
     case BlockItem::BLOCKTYPE_FIREBALL:
         this->setMessage("Fireball!", false);
         this->bonus_fireball = true;
         //this->bonus_fireball_time.start();
         this->bonus_fireball_start_time = gameTime;
         setBallColor(); // set ball color
         break;
     case BlockItem::BLOCKTYPE_BULLETS:
         this->bonus_bullets = true;
         //this->bonus_bullets_time.start();
         //this->bullet_fire_time.start();
         this->bonus_bullets_start_time = gameTime;
         this->bullets_fire_start_time = gameTime;
         break;
    default:
        break;
    }

    if( blockItem->getBlockType() != BlockItem::BLOCKTYPE_BRICK ) {
        blocks.removeOne(blockItem);
        QMutableHashIterator<int, BlockItem *> iter(blocksHashMap);
        if( iter.findNext(blockItem) ) {
            iter.remove();
        }
        delete blockItem;
        return true;
    }
    return false;
}

void PlayingGamestate::changeScore(int change) {
    const int life_every_c = 1000;
    int m1 = score / life_every_c;
    int m2 = (score+change) / life_every_c;
    score += change;
    qDebug("score is now: %d", score);
    itemScore->setPlainText("Score: " + QString::number(score));
    if( m1 != m2 ) {
        this->setMessage("Bonus Life!", false);
        this->changeLives(1);
    }
}

void PlayingGamestate::changeLives(int change) {
    lives += change;
    qDebug("lives are now: %d", lives);
    itemLives->setPlainText("Lives: " + QString::number(lives));
}

void PlayingGamestate::changeLevel(int change) {
    level += change;
    qDebug("level is now: %d", level);
    itemLevel->setPlainText("Level: " + QString::number(level));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), gamestate(NULL), keydown_left(false), keydown_right(false)
{
    // read hi-scores
    QSettings settings;
    int size = settings.beginReadArray("hiscores");
    for(int i=0;i<size;i++) {
        settings.setArrayIndex(i);
        QString name = settings.value("name").toString();
        int score = settings.value("score").toInt();
        int level = settings.value("level").toInt();
        Hiscore hiscore(name, score, level);
        this->hiscores.push_back(hiscore); // don't call addHiscore(), as this will write the settings!
    }
    settings.endArray();
    qStableSort(this->hiscores); // should already be sorted, but just in case!
    /*hiscores.push_back(Hiscore("this is a really really very long name", 1234567890, 256));
    hiscores.push_back(Hiscore("Mark", 1050, 3));
    hiscores.push_back(Hiscore("Mark 2", 450, 2));*/
    /*this->addHiscore(Hiscore("Mark", 1050, 3));
    this->addHiscore(Hiscore("this is a really really very long name", 1234567890, 256));
    this->addHiscore(Hiscore("Mark 2", 450, 2));
    this->addHiscore(Hiscore("Mark 4", 450, 2));
    this->addHiscore(Hiscore("Mark 3", 450, 3));*/
    /*scene = new QGraphicsScene(this);
    qDebug("size: %d x %d", this->width(), this->height());
    //scene->addText("Hello world!");
    //scene->setSceneRect();
    view = new QGraphicsView(scene, this);
    this->setCentralWidget(view);

    itemBat = scene->addRect(0, 0, bat_w_c, bat_h_c, QPen(Qt::white));*/

    /*scene->setSceneRect(0, 0, this->width(), this->height());
    scene->setSceneRect(0, 0, this->width(), 360);*/
    //view->setMaximumSize(this->width(), this->height());
    //view->setTransform(QTransform());
    /*view->resetTransform();
    qDebug("Is transformed? %d", view->isTransformed());*/
}

MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    //qDebug("keyPressEvent");
    if( event->key() == Qt::Key_Left ) {
        this->keydown_left = true;
        //qDebug("left");
    }
    else if( event->key() == Qt::Key_Right ) {
        this->keydown_right = true;
        //qDebug("right");
    }
    else if( event->key() == Qt::Key_Escape ) {
        gamestate->userQuit();
    }
    else if( event->key() == Qt::Key_P ) {
        gamestate->userPause();
    }
    else if( event->key() == Qt::Key_Return ) {
        QPushButton *button = qobject_cast< QPushButton* >(qApp->focusWidget());
        if (button) {
            button->click();
        }
    }
    else {
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    //qDebug("keyReleaseEvent");
    if( event->key() == Qt::Key_Left ) {
        this->keydown_left = false;
    }
    else if( event->key() == Qt::Key_Right ) {
        this->keydown_right = false;
    }
    else {
        QMainWindow::keyReleaseEvent(event);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    qDebug("mousePressEvent");
    if( gamestate != NULL )
        gamestate->mousePressEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    qDebug("resized: %d x %d", this->width(), this->height());
    if( gamestate != NULL )
        gamestate->resizeEvent(event);
}

void MainWindow::updateScene() {
    //qDebug("update scene");
    if( qApp->activeWindow() == NULL )
        return;
    //qApp->beep();
    gamestate->updateScene();
}

void MainWindow::addHiscore(Hiscore hiscore) {
    qDebug("addHiscore");
    this->hiscores.push_back(hiscore);
    qStableSort(this->hiscores);
    if( this->hiscores.size() > max_hiscore_entries_c ) {
        // delete the lowest score(s)
        this->hiscores.erase(this->hiscores.begin() + max_hiscore_entries_c, this->hiscores.end());
    }

    this->saveHiscores();
}

void MainWindow::clearHiscores() {
    qDebug("clearHiscores");
    this->hiscores.clear();
    this->saveHiscores();
}

void MainWindow::saveHiscores() {
    qDebug("saveHiscores");
    QSettings settings;
    settings.beginWriteArray("hiscores");
    for(int i=0;i<hiscores.size();i++) {
        settings.setArrayIndex(i);
        settings.setValue("name", hiscores.at(i).getName());
        settings.setValue("score", hiscores.at(i).getScore());
        settings.setValue("level", hiscores.at(i).getLevel());
     }
     settings.endArray();
}

#if 0
void MainWindow::init() {
    /*
    //itemBat = scene->addRect(0, 0, bat_w_c, bat_h_c, QPen(Qt::white));
    //itemBat = scene->addRect(0, 0, width()-4, height()-4, QPen(Qt::white));
    itemBat = scene->addRect(0, 0, 0, 100, QPen(Qt::white));
    //itemBat = scene->addRect(width()-4, 0, 0, 100, QPen(Qt::white));
    //itemBat = scene->addRect(200, 0, 0, 100, QPen(Qt::white));
    itemBat = scene->addRect(width()-1, 0, 0, 100, QPen(Qt::white));
    itemBat = scene->addRect(0, 0, 100, 0, QPen(Qt::white));
    itemBat = scene->addRect(0, height()-1, 100, 0, QPen(Qt::white));
    */
    /*itemBat = scene->addRect(2, 0, 0, 100, QPen(Qt::white));
    itemBat = scene->addRect(4, 0, 0, 100, QPen(Qt::white));
    itemBat = scene->addRect(6, 0, 0, 100, QPen(Qt::white));
    itemBat = scene->addRect(8, 0, 0, 100, QPen(Qt::white));*/
    //view->resize(width(), height());

    qDebug("size: %d x %d", this->width(), this->height());
    //qDebug("size: %d x %d", view->width(), view->height());
    //QRectF sceneRect = view->sceneRect();

    /*QPointF topLeft = view->mapToScene(0, 0);
    QPointF bottomRight = view->mapToScene(view->width(), view->height());

    QRectF sceneRect(topLeft, bottomRight);
    qDebug("scene rect: %f, %f x %f, %f", sceneRect.left(), sceneRect.top(), sceneRect.right(), sceneRect.bottom());
    */
}
#endif
