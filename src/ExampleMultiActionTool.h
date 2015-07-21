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
#include "G4HiveActions/ActionToolBase.h"

namespace g4hive
{

  typedef ActionToolBase<ExampleMultiAction> ExampleMultiToolBase;


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
                                 public AthAlgTool,
                                 public ExampleMultiToolBase
  {

    public:

      /// Standard constructor
      ExampleMultiActionTool(const std::string& type, const std::string& name,
                             const IInterface* parent);

      /// @brief Retrieve the pre-tracking action for the current thread.
      /// Down-call to the template utility base
      IPreTrackingAction* getPreTrackingAction() override final
      { return ExampleMultiToolBase::getAction<IPreTrackingAction>(); }

      /// @brief Retrieve the end-event action for the current thread.
      /// Down-call to the template utility base
      IEndEventAction* getEndEventAction() override final
      { return ExampleMultiToolBase::getAction<IEndEventAction>(); }

    private:

      /// Create an action on demand for this thread.
      ExampleMultiAction* makeAction() override final;

  }; // class ExampleMultiActionTool

} // namespace g4hive

#endif
