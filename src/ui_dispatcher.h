#ifndef UI_DISPATCHER_H
#define UI_DISPATCHER_H

#include <QObject>

class Waypoint {};  // dummy class just for test

class UiDispatcher : public QObject
{
    Q_OBJECT

    static UiDispatcher* singleton;
    explicit UiDispatcher(QObject *parent = nullptr);

public:
    static UiDispatcher* get(QObject *parent = nullptr) {
        if(!singleton) {
            singleton = new UiDispatcher(parent);
        }
        return singleton;
    }

signals:
    void ac_selected(int);
    void create_waypoint(Waypoint*);

public slots:

};

#endif // UI_DISPATCHER_H
