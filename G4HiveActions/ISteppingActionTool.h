#ifndef G4HIVEACTIONS_ISTEPPINGACTIONTOOL_H
#define G4HIVEACTIONS_ISTEPPINGACTIONTOOL_H

// System includes
#include <memory>

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
      /// I'm not 100% sure about this, as it starts to differ
      /// from how I did the SDs. Let's see how it looks.
      virtual ISteppingAction* getAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IStepTool("g4hive::ISteppingActionTool", 1, 0);
        return iid_IStepTool;
      }

    protected:

      /// Create an action for this thread. Must be implemented by tool.
      virtual ISteppingAction* makeSteppingAction() = 0;

  }; // class ISteppingActionTool

} // namespace g4hive

#endif
