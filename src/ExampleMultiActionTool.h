#ifndef G4HIVEACTIONS_EXAMPLEMULTIACTIONTOOL_H
#define G4HIVEACTIONS_EXAMPLEMULTIACTIONTOOL_H

// STL includes
#include <string>

// Framework includes
#include "AthenaBaseComps/AthAlgTool.h"

// Local includes
#include "ExampleMultiAction.h"
#include "G4HiveActions/IPreTrackingActionTool.h"
#include "G4HiveActions/IEndEventActionTool.h"
#include "G4HiveActions/ThreadActionHolder.h"

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
                                 public AthAlgTool
  {

    public:

      /// Standard constructor
      ExampleMultiActionTool(const std::string& type, const std::string& name,
                             const IInterface* parent);

      /// @brief Retrieve the pre-tracking action for the current thread.
      /// The action will be created if it doesn't already exist.
      IPreTrackingAction* getPreTrackingAction() override final;

      /// @brief Retrieve the end-event action for the current thread.
      /// The action will be created if it doesn't already exist.
      IEndEventAction* getEndEventAction() override final;

    private:

      /// @brief Get the concrete action for the current thread.
      /// This method actually does the creation of the action.
      ExampleMultiAction* getMyAction();

      /// Thread-local storage of actions
      ThreadActionHolder<ExampleMultiAction> m_actions;

  }; // class ExampleMultiActionTool

} // namespace g4hive

#endif
