#ifndef Q_SIDE_PANEL__SIDE_PANEL_STATE_HPP
#define Q_SIDE_PANEL__SIDE_PANEL_STATE_HPP

enum class SidePanelState {
    Opening = 0,
    Opened,
    Closing,
    Closed
};

const char* to_str(const SidePanelState state);

#endif // Q_SIDE_PANEL__SIDE_PANEL_STATE_HPP
