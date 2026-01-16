//
// Created by dingrui on 1/16/26.
//

#pragma once

class ThreePhaseOutlet {
public:
    void doThreePhaseOutlet();
};

class TwoPhaseOutlet {
public:
    virtual void doPlug() =0;
};

// class adapter
class OutletConverter : public TwoPhaseOutlet, public ThreePhaseOutlet {
public:
    void doPlug() override;

    void doConvert();
};

// object adapter
class OutletObjConvert : public TwoPhaseOutlet {
public:
    OutletObjConvert(ThreePhaseOutlet *p);

    void doPlug() override;

    void doConvert();

private:
    ThreePhaseOutlet *m_outlet;
};
