#ifndef G4HIVEACTIONS_EXAMPLEMULTIACTIONTOOL_H
#define G4HIVEACTIONS_EXAMPLEMULTIACTIONTOOL_H

// STL includes
#include <string>

// Local includes
#include "ExampleMultiAction.h"
#include "G4HiveActions/IPreTrackingActionTool.h"
#include "G4HiveActions/IEndEventActionTool.h"
#include "G4HiveActions/ActionToolBase.h"

namespace g4hive
{

  /// @class ExampleMultiActionTool
  /// @brief Example tool which manages the ExampleMultiAction.
  ///
  /// This tool demonstrates how to plug an action into multiple slots in the
  /// UserActionSvc. In this implementation, there is no helper base, so the
  /// boiler plate code to manage the thread-local actions is here.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class ExampleMultiActionTool : public IPreTrackingActionTool,
                                 public IEndEventActionTool,
                                 public ActionToolBase<ExampleMultiAction>
  {

    public:

      /// Standard constructor
      ExampleMultiActionTool(const std::string& type, const std::string& name,
                             const IInterface* parent);

      /// @brief Retrieve the pre-tracking action for the current thread.
      /// Calls the base helper method to trigger creation on demand.
      IPreTrackingAction* getPreTrackingAction() override final
      { return static_cast<IPreTrackingAction*>( getAction() ); }

      /// @brief Retrieve the end-event action for the current thread.
      /// Calls the base helper method to trigger creation on demand.
      IEndEventAction* getEndEventAction() override final
      { return static_cast<IEndEventAction*>( getAction() ); }

      /// @brief finalize the tool
      /// Demonstrates how to loop over and merge results from all actions.
      StatusCode finalize() override final;

    private:

      /// Create an action on demand for this thread.
      std::unique_ptr<ExampleMultiAction> makeAction() override final;

      /// Configuration options
      ExampleMultiAction::Config m_conf;

  }; // class ExampleMultiActionTool

} // namespace g4hive

#endif
