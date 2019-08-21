#ifndef Q_SIDE_PANEL__PANEL_RIGHT_SIDE_HPP
#define Q_SIDE_PANEL__PANEL_RIGHT_SIDE_HPP

#include "SidePanel.hpp"

class PanelRightSide : public SidePanel
{
    Q_OBJECT

public:

    explicit PanelRightSide(QWidget* parent = nullptr);
    virtual ~PanelRightSide() override;

};

#endif // Q_SIDE_PANEL__PANEL_RIGHT_SIDE_HPP
