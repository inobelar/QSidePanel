#include "SidePanelState.hpp"

const char* to_str(const SidePanelState state)
{
    switch (state) {
    case SidePanelState::Opening: return "Opening";
    case SidePanelState::Opened:  return "Opened";
    case SidePanelState::Closing: return "Closing";
    case SidePanelState::Closed:  return "Closed";
    default: return "???";
    }
}
