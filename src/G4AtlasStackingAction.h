#ifndef G4HIVEACTIONS_G4ATLASSTACKINGACTION_H
#define G4HIVEACTIONS_G4ATLASSTACKINGACTION_H

// System includes
#include <vector>

// Geant4 includes
#include "G4UserStackingAction.hh"

namespace g4hive
{

  // Forward declarations
  class IStackingAction;


  /// @class G4AtlasStackingAction
  /// @brief Atlas subclass of the G4 stacking action.
  ///
  /// This object maintains a list of custom actions and when invoked by
  /// Geant4 will forward the call to each of them in turn.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class G4AtlasStackingAction : public G4UserStackingAction
  {

    public:

      /// Constructor
      G4AtlasStackingAction();

      /// @brief Geant4 method for classifying a new track.
      /// This method will forward the call onto each of the actions
      /// in its private list.
      G4ClassificationOfNewTrack
      ClassifyNewTrack(const G4Track* track) override final;

      /// @brief Geant4 method for starting a new stack.
      /// Forwards the call onto each custom action.
      void NewStage() override final;

      /// @brief Geant4 method for stack preparation at new event.
      /// This method is possibly redundant so we may remove it.
      void PrepareNewEvent() override final;

      /// @brief Add one action to the list
      void addAction(IStackingAction* action);

    private:

      /// List of ATLAS stacking actions
      std::vector<IStackingAction*> m_actions;

  }; // class G4AtlasStackingAction

} // namespace g4hive

#endif
