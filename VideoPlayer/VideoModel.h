#ifndef VIDEOMODEL_H
#define VIDEOMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QStringList>
#include <QDir>
#include <QFileInfoList>
#include <QDebug>


class VideoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    static VideoModel *getInstance();
    enum videoRoles{
        FILE_NAME = Qt::UserRole + 1,
        FILE_PATH
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    void loadVideoModel(const QString &path);
    QString getVideoPath(int index);
    QString getVideoName(int index);
    int sizeList();
signals:
private:
    explicit VideoModel(QObject *parent = nullptr);
    QStringList m_fileName, m_filePath;
};

#endif // VIDEOMODEL_H
