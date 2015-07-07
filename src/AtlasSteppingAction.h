#ifndef G4HIVEACTIONS_ATLASSTEPPINGACTION_H
#define G4HIVEACTIONS_ATLASSTEPPINGACTION_H

// System includes
#include <vector>

// Geant4 includes
#include "G4UserSteppingAction.hh"

// Local includes
//#include "G4HiveActions/ISteppingAction.h"

namespace g4hive
{

  // Forward declarations
  class ISteppingAction;


  /// @class AtlasSteppingAction
  /// @brief Atlas subclass of the G4 stepping action.
  ///
  /// This object maintains a list of custom actions and when invoked by
  /// Geant4 will forward the call to each of them in turn.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class AtlasSteppingAction : public G4UserSteppingAction
  {

    public:

      /// Constructor
      AtlasSteppingAction();

      /// @brief Geant4 method for processing one step.
      /// This method will forward the call onto each of the actions
      /// in its private list.
      void UserSteppingAction(const G4Step* step) override final;

    private:

      std::vector<ISteppingAction*> m_actions;

  }; // class AtlasSteppingAction

} // namespace g4hive

#endif
