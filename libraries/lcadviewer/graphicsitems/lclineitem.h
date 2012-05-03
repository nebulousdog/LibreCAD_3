#ifndef LCLINEITEM_H
#define LCLINEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "lcgraphicsitem.h"
#include <cad/primitive/line.h>
#include <cad/meta/color.h>
#include <cad/interface/metatype.h>


// http://www.davidwdrell.net/wordpress/?page_id=46
// http://qt-project.org/forums/viewthread/4570

class LCLineItem : public LCGraphicsItem {
    public:
        LCLineItem(lc::LinePtr l);

        QRectF boundingRect() const;

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        virtual const lc::CADEntityPtr entity() const;

    private:
        QPainterPath shape() const;

    private:
        const lc::LinePtr _line;

};

#endif // LCLINEITEM_H