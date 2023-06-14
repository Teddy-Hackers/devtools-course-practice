// Copyright 2023 Sudomoykin Andrey

#include "include/QueueApplication.h"

#include <stdexcept>

#include <sstream>

std::string QueueApplication::executeCommand(int argc, char ** argv) {
  if (argc == 1)
    return getHelpMessage();
  if (argc <= 2) {
    std::stringstream ss;
    ss << "Error: No elements provided.\n" <<
      getHelpMessage();
    return ss.str();
  }

  std::string command = argv[1];
  if (command == "push") {
    try {
      Queue < int > queue;
      if (argc > 3) {
        for (int i = 3; i < argc; i++) {
          int element = std::stoi(argv[i]);
          queue.push(element);
        }
      }
      int element = std::stoi(argv[2]);
      queue.push(element);
      return queueToString( & queue);
    } catch (std::invalid_argument & ) {
        std::stringstream ss;
        ss << "Error: Invalid element."
           << " Only integers are allowed. Command push.\n";
        return ss.str();
    }
  } else if (command == "pop") {
    try {
      Queue < int > queue;
      if (argc >= 3) {
        for (int i = 2; i < argc; i++) {
          int element = std::stoi(argv[i]);
          queue.push(element);
        }
      }
      queue.pop();
      return queueToString( & queue);
    } catch (std::invalid_argument & ) {
        std::stringstream ss;
        ss << "Error: Invalid element."
           << " Only integers are allowed. Command pop.\n";
        return ss.str();
    }
  } else if (command == "length") {
    Queue < int > queue;
    if (argc >= 3) {
      for (int i = 2; i < argc; i++) {
        int element = std::stoi(argv[i]);
        queue.push(element);
      }
    }
    return "Queue length: " + std::to_string(queue.lenght()) + "\n";
  } else {
    std::stringstream ss;
    ss << "Error: Invalid command.\n" <<
      getHelpMessage();
    return ss.str();
  }
}

std::string QueueApplication::queueToString(Queue < int > * queue) {
  if (queue -> lenght() == 0)
    return "The queue is empty.\n";
  std::stringstream ss;
  ss << "The queue is: { ";
  while (queue -> lenght() != 0)
    ss << queue -> pop() << " ";
  ss << "}";
  return ss.str();
}

std::string QueueApplication::getHelpMessage() {
  std::stringstream ss;
  ss << "Available commands:\n" <<
      "  push <element> : Push an element to the queue." <<
      " example: push 5 1 2 3 4\n" <<
      "  pop : Pop an element from the queue. example: pop 1 2 3 4\n" <<
      "  length : Get the length of the queue. example: length 1 2 3 4\n";
  return ss.str();
}
