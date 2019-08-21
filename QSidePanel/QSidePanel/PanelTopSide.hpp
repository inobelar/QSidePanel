#ifndef Q_SIDE_PANEL__PANEL_TOP_SIDE_HPP
#define Q_SIDE_PANEL__PANEL_TOP_SIDE_HPP

#include "SidePanel.hpp"

class PanelTopSide : public SidePanel
{
    Q_OBJECT

public:

    explicit PanelTopSide(QWidget *parent = nullptr);
    virtual ~PanelTopSide() override;

};

#endif // Q_SIDE_PANEL__PANEL_TOP_SIDE_HPP
