#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class MainWindow;
class BlockItem;

const int time_per_frame_c = 1000/25;

class Gamestate : public QObject {
    Q_OBJECT

protected:
    MainWindow *mainWindow;
public:
    Gamestate(MainWindow *mainWindow) : mainWindow(mainWindow) {
    }
    virtual ~Gamestate() {
    }

    virtual void start()=0;
    virtual void stop()=0;
    virtual void updateScene() {};
    virtual void mousePressEvent(QMouseEvent *event) {}
    virtual void resizeEvent(QResizeEvent *event) {}
    virtual bool userQuit() {
        return false;
    }
    virtual void userPause() {
    }
};

/*class OptionsGamestate : public QObject, public Gamestate {
    Q_OBJECT*/
class OptionsGamestate : public Gamestate {
    Q_OBJECT

private slots:
    void clickedStart();
    void clickedHiscores();
    void clickedAbout();
    void clickedHelp();
    void clickedExit();
public:
    OptionsGamestate(MainWindow *mainWindow);
    virtual ~OptionsGamestate();

    virtual void start();
    virtual void stop();

    void registerScore(int score, int level);
};

class PlayingGamestate : public Gamestate {
    int gameTime;

    QGraphicsScene *scene;
    QGraphicsView  *view;
    bool paused;

    QList<QGraphicsItem *> bullets;
    QList<BlockItem *> blocks;
    QHash<int, BlockItem *> blocksHashMap;

    QGraphicsItem *itemBat;
    QAbstractGraphicsShapeItem *itemBall;

    QGraphicsTextItem *itemScore;
    QGraphicsTextItem *itemLives;
    QGraphicsTextItem *itemLevel;

    QGraphicsTextItem *itemPause;
    QGraphicsTextItem *itemQuit;

    //QSound *hitSound;

    int ball_sp_x, ball_sp_y;
    bool bat_has_target;
    int bat_target_x;

    int score, lives, level;
    bool level_complete;

    bool has_message;
    bool message_pauses;
    int message_start_time;
    //QTime message_time;
    QGraphicsTextItem *itemMessage;

    bool bonus_fireball;
    int bonus_fireball_start_time;
    //QTime bonus_fireball_time;

    bool bonus_bullets;
    int bonus_bullets_start_time;
    int bullets_fire_start_time;
    //QTime bonus_bullets_time;
    //QTime bullet_fire_time;

    void setMessage(const QString &text, bool message_pauses);
    void setBallColor();
    void initBallAndBat(bool lost_life);
    void initLevel();
    bool hitBlock(BlockItem *blockItem);
    int indexHash(qreal x, qreal y);
    BlockItem *blockAt(qreal x, qreal y);
public:
    PlayingGamestate(MainWindow *mainWindow);
    virtual ~PlayingGamestate();

    virtual void start();
    virtual void stop();
    virtual void updateScene();
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual bool userQuit();
    virtual void userPause() {
        this->paused = !paused;
    }

    void changeScore(int change);
    void changeLives(int change);
    void changeLevel(int change);
};

class Hiscore {
    QString name;
    int score;
    int level;
public:
    Hiscore(QString name, int score, int level) : name(name), score(score), level(level) {
    }
    QString getName() const {
        return name;
    }
    int getScore() const {
        return score;
    }
    int getLevel() const {
        return level;
    }
    /*bool operator<(const Hiscore &hiscore1, const Hiscore &hiscore2) {
        if( hiscore1.score < hiscore2.score ) {
            return true;
        }
        else if( hiscore1.level < hiscore2.level ) {
            return true;
        }
        return hiscore1.name < hiscore2.name;
    }*/
    bool operator<(const Hiscore other) const {
        // N.B., we want larest first
        if( score != other.score ) {
            return score > other.score;
        }
        else if( level != other.level ) {
            return level > other.level;
        }
        return name < other.name; // want alphabetical ("smallest" first)
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Gamestate *gamestate;
    QList<Hiscore> hiscores;
    bool keydown_left;
    bool keydown_right;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void saveHiscores();

public slots:
    void updateScene();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //void init();
    void setGamestate(Gamestate *gamestate) {
        if( this->gamestate != NULL ) {
            this->gamestate->stop();
            this->gamestate->deleteLater();
        }
        this->gamestate = gamestate;
        this->gamestate->start();
    }
    QList<Hiscore> &getHiscores() {
        return hiscores;
    }
    void addHiscore(Hiscore hiscore);
    void clearHiscores();
    bool isKeyDownLeft() const {
        return this->keydown_left;
    }
    bool isKeyDownRight() const {
        return this->keydown_right;
    }
};

#endif // MAINWINDOW_H
