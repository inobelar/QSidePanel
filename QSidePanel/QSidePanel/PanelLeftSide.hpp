#ifndef Q_SIDE_PANEL__PANEL_LEFT_SIDE_HPP
#define Q_SIDE_PANEL__PANEL_LEFT_SIDE_HPP

#include "SidePanel.hpp"

class PanelLeftSide : public SidePanel
{
    Q_OBJECT

public:

    explicit PanelLeftSide(QWidget *parent = nullptr);
    virtual ~PanelLeftSide() override;

};

#endif // Q_SIDE_PANEL__PANEL_LEFT_SIDE_HPP
