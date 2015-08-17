// Local includes
#include "G4AtlasStackingAction.h"
#include "G4HiveActions/IStackingAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  G4AtlasStackingAction::G4AtlasStackingAction()
  {
  }

  //---------------------------------------------------------------------------
  // Classify a new track
  //---------------------------------------------------------------------------
  G4ClassificationOfNewTrack
  G4AtlasStackingAction::ClassifyNewTrack(const G4Track* track)
  {
    // Loop over my actions and apply each one in turn
    for(IStackingAction* action : m_actions){
      action->classifyNewTrack(track);
    }
    return fUrgent;
  }

  //---------------------------------------------------------------------------
  // Start a new stack stage
  //---------------------------------------------------------------------------
  void G4AtlasStackingAction::NewStage()
  {
    // Loop over my actions and apply each one in turn
    for(IStackingAction* action : m_actions){
      action->newStage();
    }
  }

  //---------------------------------------------------------------------------
  // Start a new event
  //---------------------------------------------------------------------------
  void G4AtlasStackingAction::PrepareNewEvent()
  {
    // Loop over my actions and apply each one in turn
    for(IStackingAction* action : m_actions){
      action->prepareNewEvent();
    }
  }

  //---------------------------------------------------------------------------
  // Add one action to the action list
  //---------------------------------------------------------------------------
  void G4AtlasStackingAction::addAction(IStackingAction* action)
  {
    m_actions.push_back(action);
  }

} // namespace g4hive
