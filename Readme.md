
# GCS architecture proposal

This a proposal for the architecture of the hypotetical future Paparazzi UAV GCS.

Please react on this proposal. Do you think this architecture is flexible enough ?

It is based on Qt C++ and heavily rely on Qt signals.

_This is a proof of concept, a lot of improvements have to be made._


## Layout

The layout is parameterized with the same XML file format as the current GCS.
See layout_builder.cpp for the code building the layout.
_The papgets are not yet supported, but do we need them?_

## How to create a new widget?

To create a new widget, you have to create a new class that inherits from QWidget.

You can either create it from scratch (see the Map2D exemple), or use an *ui file (see Strip exemple). _To use an *ui file, the best is to use the QtCreator wizard : New->Qt->QtDesigner UI class._


## How do my widget communicate with other widgets?

There are two classes that are dedicated to enable communication between the widgets : UiDispatcher and PprzDispatcher. Both are singletons.

To receive a message or other kind of event, a widget have to connect a signal emited by UiDispatcher or PprzDispatcher to a slot.

example: a widget wants to react to the `ac_selected` signal with a method called `changeFocusedAc`:

```
connect(UiDispatcher::get(), SIGNAL(ac_selected(int)), this, SLOT(changeFocusedAc(int)));
```

other example: To react to a pprzLink message:

```
connect(PprzDispatcher::get(), SIGNAL(gps(PprzMessage)), this, SLOT(updatePos(PprzMessage)));
```

To emit a signal, the widget emits it in the name of the dispatcher:

```
emit(UiDispatcher::get()->ac_selected(2));
```

That means that every event that could be relevant to other widgets must a signal of the UiDispatcher.
All pprzLink messages have their corresponding signal in the PprzDispatcher.



