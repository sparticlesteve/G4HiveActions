#ifndef G4HIVEACTIONS_IENDRUNACTIONTOOL_H
#define G4HIVEACTIONS_IENDRUNACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/IEndRunAction.h"

namespace g4hive
{

  /// @class IEndRunActionTool
  /// @brief Abstract interface for tools that manage ATLAS end-of-run
  /// custom actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IEndRunActionTool : virtual public IAlgTool
  {

    public:

      /// Return the action for current thread.
      virtual IEndRunAction* getEndRunAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IEndRunTool("g4hive::IEndRunActionTool", 1, 0);
        return iid_IEndRunTool;
      }

  }; // class IEndRunActionTool

} // namespace g4hive

#endif
