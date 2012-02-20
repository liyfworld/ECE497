#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include <QtGui>

const int block_w_c = 64;
const int block_h_c = 32;

enum CustomItemTypes {
    CUSTOMITEMTYPE_BLOCK = QGraphicsItem::UserType + 1
};

class BlockItem : public QGraphicsRectItem {
public:
    enum BlockType {
        BLOCKTYPE_NORMAL = 0,
        BLOCKTYPE_EXTRALIFE = 1,
        BLOCKTYPE_FASTBALL = 2,
        BLOCKTYPE_FIREBALL = 3,
        BLOCKTYPE_BRICK = 4,
        BLOCKTYPE_EXPLOSION = 5,
        BLOCKTYPE_BULLETS = 6
    };

protected:
    //enum { Type = UserType + CUSTOMITEMTYPE_BLOCK };
    enum { Type = CUSTOMITEMTYPE_BLOCK };
    int score;
    BlockType blockType;
public:
    BlockItem(const QBrush &brush) :
            QGraphicsRectItem(0, 0, block_w_c, block_h_c),
            score(5), blockType(BLOCKTYPE_NORMAL)
    {
        this->setPen(Qt::NoPen);
        this->setBrush(brush);
    }
    int type() const {
        return Type;
    }
    void setScore(int score) {
        this->score = score;
    }
    int getScore() const {
        return this->score;
    }
    void setBlockType(BlockType blockType) {
        this->blockType = blockType;
    }
    BlockType getBlockType() const {
        return this->blockType;
    }
};

#endif // BLOCKITEM_H
