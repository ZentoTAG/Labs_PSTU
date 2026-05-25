#include "treewidget.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QDebug>

TreeWidget::TreeWidget(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setBackgroundBrush(QBrush(Qt::white));
    tree = nullptr;
}

void TreeWidget::setTree(BinarySearchTree *bst) {
    tree = bst;
    drawTree();
}

void TreeWidget::drawNode(TreeNode *node, QPointF pos, double xOffset, double yOffset, int level) {
    if (!node) {
        return;
    }

    if (level > 100) {
        return;
    }

    QGraphicsEllipseItem *ellipse = scene->addEllipse(pos.x() - 20, pos.y() - 20, 40, 40,
                                                       QPen(Qt::black), QBrush(Qt::lightGray));
    Q_UNUSED(ellipse);

    QGraphicsTextItem *text = scene->addText(QString::number(node->key));
    text->setPos(pos.x() - text->boundingRect().width() / 2,
                 pos.y() - text->boundingRect().height() / 2);

    if (node->left) {
        QPointF leftPos(pos.x() - xOffset, pos.y() + yOffset);
        scene->addLine(pos.x(), pos.y(), leftPos.x(), leftPos.y(), QPen(Qt::black));
        drawNode(node->left, leftPos, xOffset / 2, yOffset, level + 1);
    }

    if (node->right) {
        QPointF rightPos(pos.x() + xOffset, pos.y() + yOffset);
        scene->addLine(pos.x(), pos.y(), rightPos.x(), rightPos.y(), QPen(Qt::black));
        drawNode(node->right, rightPos, xOffset / 2, yOffset, level + 1);
    }
}

void TreeWidget::drawTree() {
    scene->clear();

    if (!tree || !tree->getRoot()) {
        return;
    }

    if (width() <= 10 || height() <= 10) {
        return;
    }
    double startX = width() / 2.0;
    double startY = 50.0;
    double xOffset = std::max(30.0, width() / 4.0);
    double yOffset = 80.0;
    drawNode(tree->getRoot(), QPointF(startX, startY), xOffset, yOffset, 0);
}

void TreeWidget::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    drawTree();
}
