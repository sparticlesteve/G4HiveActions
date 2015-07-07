#ifndef G4HIVEACTIONS_USERACTIONSVC_H
#define G4HIVEACTIONS_USERACTIONSVC_H

// System includes
#include <thread>

// Framework includes
#include "AthenaBaseComps/AthService.h"

// Local includes
#include "AtlasSteppingAction.h"
#include "G4HiveActions/IUserActionSvc.h"

// Other includes
#include "tbb/concurrent_unordered_map.h"

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

    private:

      // TODO: consider making a custom thread-local structure from this
      #define CONC_MAP(TYPE) \
        tbb::concurrent_unordered_map \
        < std::thread::id, TYPE*, std::hash<std::thread::id> >

      CONC_MAP(AtlasSteppingAction) m_steppingActions;

  }; // class UserActionSvc

}

#endif
