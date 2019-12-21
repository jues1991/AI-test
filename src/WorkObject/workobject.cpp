#include "workobject.h"


WorkObject::WorkObject(QObject *parent)
    :QObject(parent)
{

}
WorkObject::~WorkObject()
{

}

WorkObject::Data WorkObject::toData()
{
    Data &data = this->m_data;

    // item
    data.pixmap = this->pixmap();
    data.pos = this->pos();


    //
    return data;
}
bool WorkObject::fromData( const Data &data )
{
    // item
    this->setPixmap(data.pixmap);
    this->setPos(data.pos);
    //
    this->m_data = data;
    return true;
}

/* active */
bool WorkObject::active() const
{
    return this->m_data.active;
}
void WorkObject::setActive( const bool &active )
{
    this->m_data.active = active;

    //
    emit this->activeChanged();
}
/* name */
const QString WorkObject::name() const
{
    return this->m_data.name;
}
void WorkObject::setName( const QString &name )
{
    this->m_data.name = name;
    //
    emit this->nameChanged();
}

/* nickName */
const QString WorkObject::nickName() const
{
    return this->m_data.nickName;
}
void WorkObject::setNickName( const QString &nickName )
{
    this->m_data.nickName = nickName;

    //
    emit this->nickNameChanged();
}
