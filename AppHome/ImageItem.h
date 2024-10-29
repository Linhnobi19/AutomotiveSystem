#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QObject>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QString>
#include <QPainter>
#include <QImage>

class ImageItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged FINAL)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged FINAL)
public:
    explicit ImageItem(QQuickItem *parent = nullptr);

    void paint(QPainter *painter);
    // bool contains(const QPointF &point) const;

    int radius() const;
    void setRadius(int newRadius);
    QString source() const;
    void setSource(const QString &newSource);

signals:
    void radiusChanged();
    void sourceChanged();

private:
    int m_radius;
    QString m_source;
    QImage m_image;
    bool m_error;
};

#endif // IMAGEITEM_H
