// Local includes
#include "UserActionSvc.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  UserActionSvc::UserActionSvc(const std::string& name,
                               ISvcLocator* pSvcLocator)
    : AthService(name, pSvcLocator)
  {
    declareProperty("SteppingActionTools", m_steppingActionTools);
  }

  //---------------------------------------------------------------------------
  // Initialize the service
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::initialize()
  {
    ATH_CHECK( m_steppingActionTools.retrieve() );
    return StatusCode::SUCCESS;
  }

  //---------------------------------------------------------------------------
  // Initialize the user actions for the current thread
  // TODO: this prototype needs to be significantly cleaner.
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::initializeActions()
  {
    // Make sure we don't already have an action assigned for this thread.
    G4AtlasSteppingAction* stepAction = m_steppingActions.get();
    if(stepAction) {
      ATH_MSG_ERROR("Stepping action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    stepAction = new G4AtlasSteppingAction;
    m_steppingActions.set(stepAction);

    // Loop over stepping action tools
    for(auto stepTool : m_steppingActionTools){
      // Ask this stepping tool to give us a stepping action plugin.
      ISteppingAction* stepPlugin = stepTool->getSteppingAction();
      // Assign this action to the G4 object
      stepAction->addAction(stepPlugin);
    }

    return StatusCode::SUCCESS;
  }

  //---------------------------------------------------------------------------
  // Gaudi interface query
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::queryInterface(const InterfaceID& riid,
                                           void** ppvInterface)
  {
    if(IUserActionSvc::interfaceID().versionMatch(riid)){
      *ppvInterface = static_cast<IUserActionSvc*>(this);
    }
    else{
      // Interface is not directly available; try out a base class
      return AthService::queryInterface(riid, ppvInterface);
    }
    addRef();
    return StatusCode::SUCCESS;
  }

} // namespace g4hive
