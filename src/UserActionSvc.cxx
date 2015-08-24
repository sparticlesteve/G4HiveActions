// Framework includes
#include "CxxUtils/make_unique.h"

// Geant4 includes
#include "G4RunManager.hh"

// Local includes
#include "UserActionSvc.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  UserActionSvc::UserActionSvc(const std::string& name,
                               ISvcLocator* pSvcLocator)
    : AthService(name, pSvcLocator),
      m_beginRunActionTools(this),
      m_endRunActionTools(this),
      m_beginEventActionTools(this),
      m_endEventActionTools(this),
      m_stackingActionTools(this),
      m_preTrackingActionTools(this),
      m_postTrackingActionTools(this),
      m_steppingActionTools(this)
  {
    declareProperty("BeginRunActionTools", m_beginRunActionTools);
    declareProperty("EndRunActionTools", m_endRunActionTools);
    declareProperty("BeginEventActionTools", m_beginEventActionTools);
    declareProperty("EndEventActionTools", m_endEventActionTools);
    declareProperty("StackingActionTools", m_stackingActionTools);
    declareProperty("PreTrackingActionTools", m_preTrackingActionTools);
    declareProperty("PostTrackingActionTools", m_postTrackingActionTools);
    declareProperty("SteppingActionTools", m_steppingActionTools);
  }

  //---------------------------------------------------------------------------
  // Initialize the service
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::initialize()
  {
    ATH_MSG_INFO("initialize");
    ATH_CHECK( m_beginRunActionTools.retrieve() );
    ATH_CHECK( m_endRunActionTools.retrieve() );
    ATH_CHECK( m_beginEventActionTools.retrieve() );
    ATH_CHECK( m_endEventActionTools.retrieve() );
    ATH_CHECK( m_stackingActionTools.retrieve() );
    ATH_CHECK( m_preTrackingActionTools.retrieve() );
    ATH_CHECK( m_postTrackingActionTools.retrieve() );
    ATH_CHECK( m_steppingActionTools.retrieve() );
    return StatusCode::SUCCESS;
  }

  //---------------------------------------------------------------------------
  // Initialize the user actions for the current thread.
  // In this code, "action" refers to the G4 action classes, and "plugin"
  // refers to the custom action objects that get assigned to the G4 action.
  // TODO: this prototype could be cleaner
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::initializeActions()
  {
    // Should I lock this?

    ATH_MSG_DEBUG("initializeActions");

    // Initialize the ATLAS run action.
    if(m_runActions.get()) {
      ATH_MSG_ERROR("Run action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto runAction = CxxUtils::make_unique<G4AtlasRunAction>();
    // Assign begin-run plugins
    for(auto beginRunTool : m_beginRunActionTools)
      runAction->addBeginRunAction( beginRunTool->getBeginRunAction() );
    // Assign end-run plugins
    for(auto endRunTool : m_endRunActionTools)
      runAction->addEndRunAction( endRunTool->getEndRunAction() );
    G4RunManager::GetRunManager()->SetUserAction( runAction.get() );
    m_runActions.set( std::move(runAction) );

    // Initialize the ATLAS event action.
    if(m_eventActions.get()) {
      ATH_MSG_ERROR("Event action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto eventAction = CxxUtils::make_unique<G4AtlasEventAction>();
    // Assign begin-event plugins
    for(auto beginEventTool : m_beginEventActionTools)
      eventAction->addBeginEventAction( beginEventTool->getBeginEventAction() );
    // Assign end-event plugins
    for(auto endEventTool : m_endEventActionTools)
      eventAction->addEndEventAction( endEventTool->getEndEventAction() );
    G4RunManager::GetRunManager()->SetUserAction( eventAction.get() );
    m_eventActions.set( std::move(eventAction) );

    // Initialize the ATLAS stacking action.
    if(m_stackingActions.get()) {
      ATH_MSG_ERROR("Stacking action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto stackAction = CxxUtils::make_unique<G4AtlasStackingAction>();
    // Assign stacking plugins
    for(auto stackTool : m_stackingActionTools){
      auto stackPlugin = stackTool->getStackingAction();
      ATH_MSG_INFO("stackPlugin " << stackPlugin);
      stackAction->addAction( stackPlugin );
    }
    G4RunManager::GetRunManager()->SetUserAction( stackAction.get() );
    m_stackingActions.set( std::move(stackAction) );

    // Initialize the ATLAS tracking action.
    if(m_trackingActions.get()) {
      ATH_MSG_ERROR("Tracking action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto trackAction = CxxUtils::make_unique<G4AtlasTrackingAction>();
    // Assign pre-tracking plugins
    for(auto preTrackTool : m_preTrackingActionTools)
      trackAction->addPreTrackAction( preTrackTool->getPreTrackingAction() );
    // Assign post-tracking plugins
    for(auto postTrackTool : m_postTrackingActionTools)
      trackAction->addPostTrackAction( postTrackTool->getPostTrackingAction() );
    G4RunManager::GetRunManager()->SetUserAction( trackAction.get() );
    m_trackingActions.set( std::move(trackAction) );

    // Initialize the ATLAS stepping action.
    if(m_steppingActions.get()) {
      ATH_MSG_ERROR("Stepping action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto stepAction = CxxUtils::make_unique<G4AtlasSteppingAction>();
    // Assign stepping plugins
    for(auto stepTool : m_steppingActionTools)
      stepAction->addAction( stepTool->getSteppingAction() );
    G4RunManager::GetRunManager()->SetUserAction( stepAction.get() );
    m_steppingActions.set( std::move(stepAction) );

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
