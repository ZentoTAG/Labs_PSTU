#include "graphwidget.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <QtMath>

static const int RADIUS = 30;
static const QColor NODE_COLOR = Qt::lightGray;
static const QColor EDGE_COLOR = Qt::black;

NodeItem::NodeItem(int id, QGraphicsItem* parent) : QGraphicsEllipseItem(-RADIUS, -RADIUS, 2*RADIUS, 2*RADIUS, parent), vertexId(id) {
    setBrush(QBrush(NODE_COLOR));
    setPen(QPen(Qt::black, 2));
    QGraphicsTextItem* label = new QGraphicsTextItem(QString::number(id), this);
    label->setPos(-10, -10);
}

EdgeItem::EdgeItem(int from, int to, int weight, QGraphicsItem* parent) : QGraphicsLineItem(parent), from(from), to(to) {
    setPen(QPen(EDGE_COLOR, 2));
    weightText = new QGraphicsTextItem(QString::number(weight), this);
}

void EdgeItem::updatePosition(const QPointF& p1, const QPointF& p2) {
    QLineF line(p1, p2);
    setLine(line);
    QPointF mid = line.pointAt(0.5);
    weightText->setPos(mid.x() - 10, mid.y() - 10);
}

void EdgeItem::setWeight(int w) {
    weightText->setPlainText(QString::number(w));
}

GraphWidget::GraphWidget(Graph* graph, QWidget* parent) : QGraphicsView(parent), graph(graph), scene(new QGraphicsScene(this)) {
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    updateVisualization();
}

void GraphWidget::updateVisualization() {
    scene->clear();
    nodeItems.clear();
    edgeItems.clear();
    assignNodePositions();

    for (int v : graph->getVertices()) {
        for (int nb : graph->getNeighbors(v)) {
            if (v < nb) {
                drawEdge(v, nb);
            }
        }
    }
    for (int v : graph->getVertices()) {
        drawNode(v);
    }
}

void GraphWidget::drawNode(int id) {
    QPointF pos = nodePositions.value(id);
    NodeItem* node = new NodeItem(id);
    node->setPos(pos);
    scene->addItem(node);
    nodeItems[id] = node;
}

void GraphWidget::drawEdge(int from, int to) {
    int weight = graph->getWeight(from, to);

    if (weight == -1) {
        weight = graph->getWeight(to, from);
    }

    if (weight == -1) {
        return;
    }
    EdgeItem* edge = new EdgeItem(from, to, weight);
    QPointF p1 = nodePositions.value(from);
    QPointF p2 = nodePositions.value(to);
    edge->updatePosition(p1, p2);
    scene->addItem(edge);
    edgeItems[{from, to}] = edge;
    edgeItems[{to, from}] = edge;
}

void GraphWidget::assignNodePositions() {
    nodePositions.clear();
    QList<int> verts = graph->getVertices().values();
    int n = verts.size();

    if (n == 0) {
        return;
    }
    double angleStep = 2 * M_PI / n;
    double radius = 250;

    for (int i = 0; i < n; ++i) {
        double angle = i * angleStep;
        double x = width()/2 + radius * qCos(angle);
        double y = height()/2 + radius * qSin(angle);
        nodePositions[verts[i]] = QPointF(x, y);
    }
}
