#ifndef G4HIVEACTIONS_STEPPINGACTIONBASETOOL_H
#define G4HIVEACTIONS_STEPPINGACTIONBASETOOL_H

// Framework includes
#include "AthenaBaseComps/AthAlgTool.h"

// Local includes
#include "G4HiveActions/ISteppingActionTool.h"
#include "G4HiveActions/ThreadActionHolder.h"

namespace g4hive
{

  /// @class SteppingActionBaseTool
  /// @brief Base class for stepping action tools.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class SteppingActionBaseTool : public AthAlgTool,
                                 public virtual ISteppingActionTool
  {

    public:

      /// Constructor
      SteppingActionBaseTool(const std::string& type, const std::string& name,
                             const IInterface* parent);

      /// @brief Return the action for the current thread.
      /// This method will trigger creation of the action when first
      /// called in a new thread.
      ISteppingAction* getSteppingAction() override final;

    protected:

      /// Create an action for this thread on demand.
      virtual ISteppingAction* makeSteppingAction() = 0;

    private:

      /// Thread-local storage of my actions
      ThreadActionHolder<ISteppingAction> m_action;

  }; // class SteppingActionBaseTool

} // namespace g4hive

#endif
