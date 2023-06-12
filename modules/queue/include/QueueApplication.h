// Copyright 2023 Sudomoykin Andrey

#ifndef MODULES_QUEUE_INCLUDE_QUEUEAPPLICATION_H_
#define MODULES_QUEUE_INCLUDE_QUEUEAPPLICATION_H_

#include <string>
#include "include/queue.h"

class QueueApplication {
 public:
  std::string executeCommand(int argc, char** argv);
 private:
  std::string queueToString(Queue<int>* queue);
  std::string getHelpMessage();
};

#endif  //  MODULES_QUEUE_INCLUDE_QUEUEAPPLICATION_H_
