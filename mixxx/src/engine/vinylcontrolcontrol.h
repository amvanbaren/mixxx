#ifndef VINYLCONTROLCONTROL_H
#define VINYLCONTROLCONTROL_H

#include "engine/enginecontrol.h"
#include "trackinfoobject.h"
#include "configobject.h"
#include "controlobject.h"
#include "controlpushbutton.h"

class VinylControlControl : public EngineControl {
    Q_OBJECT
  public:
    VinylControlControl(const char* pGroup, ConfigObject<ConfigValue>* pConfig);
    virtual ~VinylControlControl();

    void trackLoaded(TrackPointer pTrack);
    void trackUnloaded(TrackPointer pTrack);

  private slots:
    void slotControlVinylSeek(double value);

  private:
    ControlObject* m_pControlVinylSeek;
    ControlObject* m_pControlVinylStatus;
    ControlPushButton* m_pControlVinylMode;
    ControlPushButton* m_pControlVinylEnabled;
    ControlPushButton* m_pControlVinylCueing;
    TrackPointer m_pCurrentTrack;
};

#endif /* VINYLCONTROLCONTROL_H */
