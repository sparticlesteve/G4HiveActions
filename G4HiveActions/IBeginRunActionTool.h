#ifndef G4HIVEACTIONS_IBEGINRUNACTIONTOOL_H
#define G4HIVEACTIONS_IBEGINRUNACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/IBeginRunAction.h"

namespace g4hive
{

  /// @class IBeginRunActionTool
  /// @brief Abstract interface for tools that manage ATLAS begin-of-run
  /// custom actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IBeginRunActionTool : virtual public IAlgTool
  {

    public:

      /// Return the action for current thread.
      virtual IBeginRunAction* getBeginRunAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IBeginRunTool("g4hive::IBeginRunActionTool", 1, 0);
        return iid_IBeginRunTool;
      }

  }; // class IBeginRunActionTool

} // namespace g4hive

#endif
