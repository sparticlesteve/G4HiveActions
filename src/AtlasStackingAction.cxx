// Local includes
#include "AtlasStackingAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  AtlasStackingAction::AtlasStackingAction(const Config& config)
    : m_config(config)
  {}

  //---------------------------------------------------------------------------
  // Classify a new track
  //---------------------------------------------------------------------------
  G4ClassificationOfNewTrack
  AtlasStackingAction::classifyNewTrack(const G4Track* /*track*/)
  {
    // TODO: implement me
    return fUrgent;
  }

  //---------------------------------------------------------------------------
  // New tracking stack
  //---------------------------------------------------------------------------
  void AtlasStackingAction::newStage()
  {
  }

  //---------------------------------------------------------------------------
  // Prepare stacking for new event
  //---------------------------------------------------------------------------
  void AtlasStackingAction::prepareNewEvent()
  {
  }

} // namespace g4hive
