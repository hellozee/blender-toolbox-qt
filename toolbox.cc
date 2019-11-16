#include "toolbox.h"

#include <QPainter>
#include <QPaintEvent>
#include <QTextItem>

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent), m_activated(-1), m_padding(10), m_subToolActivated(-1),
    m_buttonSize(40, 40), m_longPressed(false)
{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    m_timer.setInterval(1000);
    m_timer.setSingleShot(true);

    connect(&m_timer, &QTimer::timeout, this, &ToolBox::longPressEvent);
}

void ToolBox::paintEvent(QPaintEvent *event)
{
    QPainter gc(this);
    gc.setRenderHint(QPainter::Antialiasing);

    QPoint topLeft = event->rect().topLeft();
    QColor highlightedBack(86, 128, 194);
    QColor back(49, 49, 49);
    m_toolRects.clear();

    for(int i=0; i<m_breaks.count(); i++){
        int count = m_breaks[i] + 1;
        if(i>0){
            count = count - m_breaks[i-1] - 1;
        }
        int h = m_buttonSize.height() * (count);
        QRect backRect(topLeft, QSize(m_buttonSize.width(), h));
        QPainterPath p;
        p.addRoundedRect(backRect, 3, 3);
        gc.fillPath(p, back);
        topLeft += QPoint(0, 2+h);
    }

    int breakCount = 0;
    topLeft = event->rect().topLeft();

    for(int i=0;i<m_tools.count();i++){
        QRect toolRect(topLeft, m_buttonSize);
        QPainterPath path;
        path.addRoundedRect(toolRect, 3, 3);

        if(i == m_activated){
            gc.fillPath(path, highlightedBack);
        }

        if(!m_tools[i].subTools().isEmpty()){
            QPainterPath p;
            p.moveTo(toolRect.bottomRight());
            p.lineTo(toolRect.bottomRight() + QPoint(0, -5));
            p.lineTo(toolRect.bottomRight() + QPoint(-5, 0));
            gc.fillPath(p, Qt::black);
        }

        QRect iconRect = toolRect.adjusted(m_padding, m_padding, -m_padding, -m_padding);
        m_tools[i].icon().paint(&gc, iconRect);
        m_toolRects.push_back(toolRect);
        topLeft += QPoint(0, m_buttonSize.height());

        if(breakCount < m_breaks.count() && m_breaks[breakCount] == i){
            topLeft += QPoint(0, 2);
            breakCount++;
        }

    }

    QPoint subTopLeft(0,0);
    if(m_longPressed){
        QVector<Tool> tools = m_tools[m_activated].subTools();
        m_secondaryTools.clear();

        if(!tools.isEmpty()){
            subTopLeft = QPoint(m_toolRects[m_activated].topRight());
            for(int i=0; i<tools.count(); i++){
                QRect toolRect(subTopLeft, m_buttonSize + QSize(130, 0));
                if(m_subToolActivated == i){
                    gc.fillRect(toolRect, highlightedBack);
                }else{
                    gc.fillRect(toolRect, back);
                }
                QRect iconRect = toolRect.adjusted(m_padding, m_padding, -m_padding-130, -m_padding);
                tools[i].icon().paint(&gc, iconRect);
                gc.setPen(Qt::white);
                gc.drawText(iconRect.bottomRight() + QPoint(10, -5), tools[i].name());
                subTopLeft += QPoint(0, m_buttonSize.height());
                m_secondaryTools.push_back(toolRect);
            }
        }
    }

    int w = m_buttonSize.width();
    int h = topLeft.y() + m_buttonSize.height() + 2;

    if(m_longPressed){
        w = w*2 + 130;
        if(subTopLeft.y() > topLeft.y()){
            h = subTopLeft.y() + m_buttonSize.height() + 2;
        }
    }

    resize(w, h);
}

void ToolBox::addTool(Tool t)
{
    m_tools.push_back(t);
}

void ToolBox::addBreak()
{
    m_breaks.push_back(m_tools.count()-1);
}

void ToolBox::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();

    for(int i=0; i<m_tools.count(); i++){
        if(m_toolRects[i].contains(pos)){
            m_activated = i;
            m_timer.start();
            update();
            return;
        }
    }
}

void ToolBox::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();

    if(m_longPressed){
        for(int i=0; i<m_secondaryTools.count(); i++){
            if(m_secondaryTools[i].contains(pos)){
                m_subToolActivated = i;
                update();
                return;
            }
        }
        m_subToolActivated = -1;
    }
}

void ToolBox::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    m_longPressed = false;
    if(m_subToolActivated >= 0){
        m_tools[m_activated].swap(m_subToolActivated);
    }
    m_subToolActivated = -1;
    update();
}

void ToolBox::longPressEvent()
{
    m_longPressed = true;
    update();
}
