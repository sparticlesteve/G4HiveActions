#ifndef G4HIVEACTIONS_USERACTIONSVC_H
#define G4HIVEACTIONS_USERACTIONSVC_H

// System includes
#include <thread>

// Framework includes
#include "AthenaBaseComps/AthService.h"
#include "GaudiKernel/ToolHandle.h"

// Local includes
#include "G4AtlasSteppingAction.h"
#include "G4AtlasTrackingAction.h"
#include "G4AtlasEventAction.h"
#include "G4HiveActions/ISteppingActionTool.h"
#include "G4HiveActions/IPreTrackingActionTool.h"
#include "G4HiveActions/IPostTrackingActionTool.h"
#include "G4HiveActions/IBeginEventActionTool.h"
#include "G4HiveActions/IEndEventActionTool.h"
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

      /// Initialize the user actions for the current thread
      StatusCode initializeActions() override final;

      /// Gaudi interface query
      virtual StatusCode queryInterface(const InterfaceID& riid,
                                        void** ppvInterface);

    private:

      /// @name Handles to ATLAS action tools
      /// @{

      /// Stepping action tools
      ToolHandleArray<ISteppingActionTool> m_steppingActionTools;
      /// Pre-tracking action tools
      ToolHandleArray<IPreTrackingActionTool> m_preTrackingActionTools;
      /// Post-tracking action tools
      ToolHandleArray<IPostTrackingActionTool> m_postTrackingActionTools;
      /// Begin-event action tools
      ToolHandleArray<IBeginEventActionTool> m_beginEventActionTools;
      /// End-event action tools
      ToolHandleArray<IEndEventActionTool> m_endEventActionTools;

      /// @}

      /// @name ATLAS plugin actions
      /// @{

      /// Thread-local stepping action
      ThreadActionHolder<G4AtlasSteppingAction> m_steppingActions;
      /// Thread-local tracking action
      ThreadActionHolder<G4AtlasTrackingAction> m_trackingActions;
      /// Thread-local event action
      ThreadActionHolder<G4AtlasEventAction> m_eventActions;

      /// @}

  }; // class UserActionSvc

}

#endif
