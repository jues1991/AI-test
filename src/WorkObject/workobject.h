#ifndef WORKOBJECT_H
#define WORKOBJECT_H

#include "WorkObject_global.h"
#include <QObject>
#include <QGraphicsPixmapItem>

class WORKOBJECT_EXPORT WorkObject : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    struct Data{
        // item
        QPixmap pixmap;
        QPointF pos;

        // ext
        bool active;
        QString name;
        QString nickName;
    };
public:
    Q_INVOKABLE explicit WorkObject(QObject *parent=nullptr);
    virtual ~WorkObject();

public:
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString nickName READ nickName WRITE setNickName NOTIFY nickNameChanged)

public:
    Data toData();
    bool fromData( const Data &data );
Q_SIGNALS:
    void activeChanged();
    void nameChanged();
    void nickNameChanged();
public slots:
    /* active */
    bool active() const;
    void setActive( const bool &active );

    /* name */
    const QString name() const;
    void setName( const QString &name );

    /* nickName */
    const QString nickName() const;
    void setNickName( const QString &nickName );

protected:
    Data m_data;
};

#endif // WORKOBJECT_H
