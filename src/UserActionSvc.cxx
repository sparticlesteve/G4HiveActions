#include "CxxUtils/make_unique.h"
#include "UserActionSvc.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  UserActionSvc::UserActionSvc(const std::string& name,
                               ISvcLocator* pSvcLocator)
    : AthService(name, pSvcLocator),
      m_stackingActionTools(this),
      m_steppingActionTools(this),
      m_preTrackingActionTools(this),
      m_postTrackingActionTools(this),
      m_beginEventActionTools(this),
      m_endEventActionTools(this)
  {
    declareProperty("StackingActionTools", m_stackingActionTools);
    declareProperty("SteppingActionTools", m_steppingActionTools);
    declareProperty("PreTrackingActionTools", m_preTrackingActionTools);
    declareProperty("PostTrackingActionTools", m_postTrackingActionTools);
    declareProperty("BeginEventActionTools", m_beginEventActionTools);
    declareProperty("EndEventActionTools", m_endEventActionTools);
  }

  //---------------------------------------------------------------------------
  // Initialize the service
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::initialize()
  {
    ATH_MSG_INFO("initialize");
    ATH_CHECK( m_stackingActionTools.retrieve() );
    ATH_CHECK( m_steppingActionTools.retrieve() );
    ATH_CHECK( m_preTrackingActionTools.retrieve() );
    ATH_CHECK( m_postTrackingActionTools.retrieve() );
    ATH_CHECK( m_beginEventActionTools.retrieve() );
    ATH_CHECK( m_endEventActionTools.retrieve() );
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

    // Initialize the ATLAS stacking action.
    if(m_stackingActions.get()) {
      ATH_MSG_ERROR("Stacking action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto stackAction = CxxUtils::make_unique<G4AtlasStackingAction>();

    // Assign stacking plugins
    for(auto stackTool : m_stackingActionTools){
      IStackingAction* stackPlugin = stackTool->getStackingAction();
      stackAction->addAction(stackPlugin);
    }
    m_stackingActions.set( std::move(stackAction) );

    // Initialize the ATLAS stepping action.
    if(m_steppingActions.get()) {
      ATH_MSG_ERROR("Stepping action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto stepAction = CxxUtils::make_unique<G4AtlasSteppingAction>();

    // Assign stepping plugins
    for(auto stepTool : m_steppingActionTools){
      ISteppingAction* stepPlugin = stepTool->getSteppingAction();
      stepAction->addAction(stepPlugin);
    }
    m_steppingActions.set( std::move(stepAction) );

    // Initialize the ATLAS tracking action.
    if(m_trackingActions.get()) {
      ATH_MSG_ERROR("Tracking action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto trackAction = CxxUtils::make_unique<G4AtlasTrackingAction>();

    // Assign pre-tracking plugins
    for(auto preTrackTool : m_preTrackingActionTools){
      IPreTrackingAction* preTrackPlugin = preTrackTool->getPreTrackingAction();
      trackAction->addPreTrackAction(preTrackPlugin);
    }
    // Assign post-tracking plugins
    for(auto postTrackTool : m_postTrackingActionTools){
      IPostTrackingAction* postTrackPlugin = postTrackTool->getPostTrackingAction();
      trackAction->addPostTrackAction(postTrackPlugin);
    }
    m_trackingActions.set( std::move(trackAction) );

    // Initialize the ATLAS event action.
    if(m_eventActions.get()) {
      ATH_MSG_ERROR("Event action already exists for current thread!");
      return StatusCode::FAILURE;
    }
    auto eventAction = CxxUtils::make_unique<G4AtlasEventAction>();

    // Assign begin-event plugins
    for(auto beginEventTool : m_beginEventActionTools){
      IBeginEventAction* beginEventPlugin = beginEventTool->getBeginEventAction();
      eventAction->addBeginEventAction(beginEventPlugin);
    }
    // Assign end-event plugins
    for(auto endEventTool : m_endEventActionTools){
      IEndEventAction* endEventPlugin = endEventTool->getEndEventAction();
      eventAction->addEndEventAction(endEventPlugin);
    }
    m_eventActions.set( std::move(eventAction) );

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
