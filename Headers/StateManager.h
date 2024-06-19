#pragma once

#include "State.h"
#include <memory>
#include <stack>

namespace Engine
{
  class StateManager
  {
  public:
    StateManager();
    virtual ~StateManager();

    void Add(std::unique_ptr<State> toAdd, bool replace = false);
    void PopCurrent();
    void PopAll();
    void ProcessStateChange();
    std::unique_ptr<State> &GetCurrent();
    bool isEmpty() const;

  private:
    std::stack<std::unique_ptr<State>> m_stackSTate;
    std::unique_ptr<State> m_newState;

    bool m_add;
    bool m_remove;
    bool m_removeAll;
    bool m_replace;
  };
}