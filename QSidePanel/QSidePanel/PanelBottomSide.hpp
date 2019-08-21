#ifndef Q_SIDE_PANEL__PANEL_BOTTOM_SIDE_HPP
#define Q_SIDE_PANEL__PANEL_BOTTOM_SIDE_HPP

#include "SidePanel.hpp"

class PanelBottomSide : public SidePanel
{
    Q_OBJECT

public:

    explicit PanelBottomSide(QWidget *parent = nullptr);
    virtual ~PanelBottomSide() override;

};

#endif // Q_SIDE_PANEL__PANEL_BOTTOM_SIDE_HPP
