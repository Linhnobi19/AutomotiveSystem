#include "VideoModel.h"

VideoModel::VideoModel(QObject *parent)
{
}
VideoModel *VideoModel::getInstance()
{
    static VideoModel* instance = new VideoModel();
    return instance;
}

int VideoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_fileName.size();
}

QVariant VideoModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.row() >= m_fileName.size())
        return QVariant();
    if(role == FILE_NAME)
        return m_fileName.at(index.row());
    else if(role == FILE_PATH)
        return m_filePath.at(index.row());
    return QVariant();
}

QHash<int, QByteArray> VideoModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FILE_NAME]  = "fileName";
    roles[FILE_PATH]  = "filePath";
    return roles;
}

void VideoModel::loadVideoModel(const QString &path)
{
    QDir vidPath(path);
    QFileInfoList videoFile  = vidPath.entryInfoList(QStringList() << "*.mp4", QDir::Files);
    m_fileName.clear();
    m_filePath.clear();
    for(const QFileInfo &temp : videoFile)
    {
        m_fileName.append(temp.fileName());
        m_filePath.append(temp.filePath());
    }
    beginResetModel();
    endResetModel();
    qDebug() << "The last is: " << m_fileName[2];
}

QString VideoModel::getVideoPath(int index)
{
    if(index >= 0 && index < m_filePath.size())
    {
        return m_filePath.at(index);
    }
    else
    {
        return QString();
    }
}

QString VideoModel::getVideoName(int index)
{
    if(index >= 0 && index < m_fileName.size())
    {
        return m_fileName.at(index);
    }
    else
    {
        return QString();
    }
}

int VideoModel::sizeList()
{
    return m_filePath.size();
}

