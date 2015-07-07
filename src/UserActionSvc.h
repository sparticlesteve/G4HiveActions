#ifndef G4HIVEACTIONS_USERACTIONSVC_H
#define G4HIVEACTIONS_USERACTIONSVC_H

// Local includes
#include "G4HiveActions/IUserActionSvc.h"

namespace g4hive
{

  /// @class UserActionSvc
  /// @brief A service which manages the user actions for G4 simulation
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class UserActionSvc : public AthService,
                        public virtual IUserActionSvc
  {

    public:

      /// Standard constructor
      UserActionSvc(const std::string& name, ISvcLocator* pSvcLocator);

      /// Initialize the service
      StatusCode initialize() override;

      /// Gaudi interface query
      virtual StatusCode queryInterface(const InterfaceID& riid,
                                        void** ppvInterface);

      /// Initialize the user actions for the current thread
      StatusCode initializeActions() override final;

  }; // class UserActionSvc

}

#endif
