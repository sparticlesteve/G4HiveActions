#ifndef G4HIVEACTIONS_ISTACKINGACTIONTOOL_H
#define G4HIVEACTIONS_ISTACKINGACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/IStackingAction.h"

namespace g4hive
{

  /// @class IStackingActionTool
  /// @brief Abstract interface for tools that manage ATLAS stacking actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IStackingActionTool : virtual public IAlgTool
  {
    
    public:

      /// @brief Return the action for current thread.
      virtual IStackingAction* getStackingAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IStepTool("g4hive::IStackingActionTool", 1, 0);
        return iid_IStepTool;
      }

  }; // class IStackingActionTool

} // namespace g4hive

#endif
