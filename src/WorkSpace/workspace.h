#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "WorkSpace_global.h"
#include <QGraphicsScene>


class WORKSPACE_EXPORT WorkSpace : public QGraphicsScene
{
    Q_OBJECT
public:
    WorkSpace(QObject *parent = nullptr);
    ~WorkSpace();
};

#endif // WORKSPACE_H
