#pragma once

#include <QObject>
#include <consts.h>


class Door : public QObject {
  Q_OBJECT

public:
  explicit Door(QObject *parent = nullptr);

signals:
  void closed_doors();
  void opened_doors();

public slots:
  void start_openning();
  void start_closing();

private slots:
  void open();
  void close();

private:
  enum doors_state { OPENNING, OPENED, CLOSING, CLOSED };
  doors_state current_state;
  QTimer doors_open_timer;
  QTimer doors_close_timer;
  QTimer doors_stay_open_timer;
};
