#ifndef G4HIVEACTIONS_USERACTIONSVC_H
#define G4HIVEACTIONS_USERACTIONSVC_H

// System includes
#include <thread>

// Framework includes
#include "AthenaBaseComps/AthService.h"
#include "GaudiKernel/ToolHandle.h"

// Local includes
#include "AtlasSteppingAction.h"
#include "G4HiveActions/ISteppingActionTool.h"
#include "G4HiveActions/IUserActionSvc.h"
#include "G4HiveActions/ThreadActionHolder.h"


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

      /// @name Handles to ATLAS action tools
      /// @{

      /// Stepping action tools
      ToolHandleArray<ISteppingActionTool> m_steppingActionTools;

      /// @}

      /// @name ATLAS plugin actions
      /// @{

      /// Thread-local stepping action
      ThreadActionHolder<AtlasSteppingAction> m_steppingActions;

      /// @}

  }; // class UserActionSvc

}

#endif
