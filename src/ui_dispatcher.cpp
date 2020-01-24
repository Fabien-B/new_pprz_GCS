#include "ui_dispatcher.h"

UiDispatcher* UiDispatcher::singleton = nullptr;

UiDispatcher::UiDispatcher(QObject *parent) : QObject(parent)
{

}
