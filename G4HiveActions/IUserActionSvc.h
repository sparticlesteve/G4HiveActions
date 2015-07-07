#ifndef G4HIVEACTIONS_IUSERACTIONSVC_H
#define G4HIVEACTIONS_IUSERACTIONSVC_H

// Framework includes
#include "GaudiKernel/IService.h"

namespace g4hive
{

  /// @class IUserActionSvc
  /// @brief Abstract interface for the UserActionSvc
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IUserActionSvc : virtual public IService
  {

    public:

      /// @brief Initialize all the user actions for the current thread.
      virtual StatusCode initializeActions() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID()
      {
        static const InterfaceID iid_IUASvc("g4hive::IUserActionSvc", 1, 0);
        return iid_IUASvc;
      }

  }; // class IUserActionSvc

} // namespace g4hive

#endif
