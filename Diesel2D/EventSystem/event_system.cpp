#include "event_system.h"
#include <any>

using std::vector;
using std::unique_ptr;


int EventHandler::counter;


void EventHandler::operator()(std::any object) {
    this->_func(object);
}

void EventHandler::operator=(const EventHandler &func) {
    if(this->_func == nullptr) {
        this->_func = func;
        this->id = ++EventHandler::counter;
    } else {
        // Throw as exception or just log it out.
        std::cerr << "Nope!" << std::endl;
    }
}

bool EventHandler::operator==(const EventHandler &del) {
    return this->id == del.id;
}
bool EventHandler::operator!=(nullptr_t) {
    return this->_func != nullptr;
}


void Event::notifyHandlers(std::any object) {
    vector<unique_ptr<EventHandler>>::iterator func = this->handlers.begin();
    for(; func != this->handlers.end(); ++func) {
        if(*func != nullptr && (*func)->id != 0) {      
            (*(*func))(object);
        }
    }
}

void Event::addHandler(const EventHandler &handler) {
    this->handlers.push_back(unique_ptr<EventHandler>(new EventHandler{handler}));
}

void Event::removeHandler(const EventHandler &handler) {
    vector<unique_ptr<EventHandler>>::iterator to_remove = this->handlers.begin();
    for(; to_remove != this->handlers.end(); ++to_remove) {
        if(*(*to_remove) == handler) {
            this->handlers.erase(to_remove);
            break;
        }
    }
}

void Event::operator()(std::any object) {
    this->notifyHandlers(object);
}

Event &Event::operator+=(const EventHandler &handler) {
    this->addHandler(handler);

    return *this;
}

Event &Event::operator+=(const EventHandler::Func &handler) {
    this->addHandler(EventHandler{handler});

    return *this;
}

Event &Event::operator-=(const EventHandler &handler) {
    this->removeHandler(handler);

    return *this;
}
