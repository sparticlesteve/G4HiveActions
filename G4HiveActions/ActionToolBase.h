#ifndef G4HIVEACTIONS_ACTIONTOOLBASE_H
#define G4HIVEACTIONS_ACTIONTOOLBASE_H

// System includes
#include <memory>

// Framework includes
#include "AthenaBaseComps/AthAlgTool.h"

// Local includes
#include "G4HiveActions/ThreadActionHolder.h"

namespace g4hive
{

  /// @class ActionToolBase
  /// @brief abstract template utility base-class for G4 user-action tools.
  ///
  /// Concrete action tools should inherit from the correct specialization
  /// of this type and implement the required abstract method to create a
  /// corresponding custom action on demand. All the thread-local machinery
  /// is captured in this class so the concrete class doesn't need to worry
  /// about it.
  ///
  /// The template parameter of this class should be the concrete action type.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  template <class ActionType>
  class ActionToolBase : public AthAlgTool
  {

    public:

      /// Standard constructor
      ActionToolBase(const std::string& type, const std::string& name,
                     const IInterface* parent)
        : AthAlgTool(type, name, parent)
      {}

      /// @brief Helper method for retrieving an action interface.
      /// The concrete action tool should down-call this method to do the
      /// retrieval and then cast it to the desired interface.
      ActionType* getAction()
      {
        ActionType* action = m_actions.get();
        if(!action){
          auto uniqueAction = makeAction();
          action = uniqueAction.get();
          m_actions.set( std::move(uniqueAction) );
        }
        return action;
      }

    protected:

      /// @brief Abstract method to create a custom action on demand.
      /// This method must be implemented by the concrete action tool.
      virtual std::unique_ptr<ActionType> makeAction() = 0;

      /// @brief Retrieve const-ref to the action holder
      const ThreadActionHolder<ActionType>& actions()
      { return m_actions; }

    private:

      /// Thread-local storage of my user actions.
      ThreadActionHolder<ActionType> m_actions;

  }; // class ActionToolBase

} // namespace g4hive

#endif
