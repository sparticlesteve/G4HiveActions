// Local includes
#include "ExampleMultiActionTool.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  ExampleMultiActionTool::
  ExampleMultiActionTool(const std::string& type, const std::string& name,
                         const IInterface* parent)
    : AthAlgTool(type, name, parent)
  {
  }

  //---------------------------------------------------------------------------
  // Retrieve pre-tracking interface
  //---------------------------------------------------------------------------
  IPreTrackingAction* ExampleMultiActionTool::getPreTrackingAction()
  {
    return static_cast<IPreTrackingAction*>( getMyAction() );
  }

  //---------------------------------------------------------------------------
  // Retrieve end-of-event interface
  //---------------------------------------------------------------------------
  IEndEventAction* ExampleMultiActionTool::getEndEventAction()
  {
    return static_cast<IEndEventAction*>( getMyAction() );
  }

  //---------------------------------------------------------------------------
  // Get the concrete action for current thread
  //---------------------------------------------------------------------------
  ExampleMultiAction* ExampleMultiActionTool::getMyAction()
  {
    ExampleMultiAction* action = m_actions.get();
    if(!action){
      action = new ExampleMultiAction();
      m_actions.set(action);
    }
    return action;
  }

} // namespace g4hive
