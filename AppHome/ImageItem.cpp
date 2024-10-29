#include "ImageItem.h"
#include <QUrl>
#include <QPainterPath>
#include <QDebug>
#include <QDir>


ImageItem::ImageItem(QQuickItem *parent )
    : QQuickPaintedItem{parent}, m_error(false)
{}

void ImageItem::paint(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing);

    QRectF rect = boundingRect();

    QBrush brush(Qt::white);
    painter->setBrush(brush);

    if(!m_error){
        painter->drawRect(rect);
        QPen pen;
        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(rect, Qt::AlignCenter, "Invalid Image");
    }
    else{

        QPainterPath path;
        path.addRoundedRect(rect, m_radius, m_radius);
        painter->setClipPath(path);
        // painter->drawRect(rect);
        QImage scaledImage = m_image.scaled(rect.size().toSize(), Qt::KeepAspectRatioByExpanding,
                                            Qt::SmoothTransformation);
        QRectF targetRect = rect;  // Kích thước vùng vẽ
        QRectF sourceRect = QRectF(0, 0, scaledImage.width(), scaledImage.height());  // Kích thước ảnh ban đầu
        sourceRect = sourceRect.intersected(QRectF(0, 0, rect.width(), rect.height()));  // Cắt phần thừa
        painter->drawImage(targetRect, scaledImage, sourceRect);  // Vẽ ảnh cắt

        // painter->drawImage(rect, scaledImage);
        // painter->drawImage(rect, m_image);
    }


}

int ImageItem::radius() const
{
    return m_radius;
}

void ImageItem::setRadius(int newRadius)
{
    if (m_radius == newRadius)
        return;
    m_radius = newRadius;
    emit radiusChanged();
}

QString ImageItem::source() const
{
    return m_source;
}

void ImageItem::setSource(const QString &newSource)
{
    if(m_source != newSource){
        m_source = newSource;
        bool check = newSource.contains("qrc");
        if(check){
            QString testSource = newSource;
            testSource = testSource.remove(0, 4);
            QDir dir = QDir::currentPath();
            dir.cd("../Resource");
            m_source = "file://" + dir.absolutePath() + testSource;
            // qDebug() << "Test file " << dir.absoluteFilePath("");
        }
        QUrl url(m_source);
        QString path = url.toLocalFile();       // return path that URL formatted as a local file path
        // qDebug() << newSource;

        if(!m_image.load(path)){
            m_error = false;
            qDebug() << "Could not load image from " << path;
        }
        else {
            m_error = true;
        }
        update();
        emit sourceChanged();
    }
}
