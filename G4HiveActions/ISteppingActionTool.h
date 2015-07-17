#ifndef G4HIVEACTIONS_ISTEPPINGACTIONTOOL_H
#define G4HIVEACTIONS_ISTEPPINGACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/ISteppingAction.h"

namespace g4hive
{

  /// @class ISteppingActionTool
  /// @brief Abstract interface for tools that manage ATLAS stepping actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class ISteppingActionTool : virtual public IAlgTool
  {
    
    public:

      /// @brief Return the action for current thread.
      virtual ISteppingAction* getSteppingAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IStepTool("g4hive::ISteppingActionTool", 1, 0);
        return iid_IStepTool;
      }

  }; // class ISteppingActionTool

} // namespace g4hive

#endif
