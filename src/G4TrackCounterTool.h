#ifndef G4HIVEACTIONS_G4TRACKCOUNTERTOOL_H
#define G4HIVEACTIONS_G4TRACKCOUNTERTOOL_H

// STL includes
#include <string>

// Local includes
#include "G4HiveActions/IBeginEventActionTool.h"
#include "G4HiveActions/IEndRunActionTool.h"
#include "G4HiveActions/IPreTrackingActionTool.h"
#include "G4HiveActions/ActionToolBase.h"
#include "G4TrackCounter.h"


namespace g4hive
{

  /// @class G4TrackCounterTool
  /// @brief Tool which manages the G4TrackCounter action.
  /// This tool creates the G4TrackCounter for each thread and merges the track
  /// counts from all threads in finalization.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  class G4TrackCounterTool : public ActionToolBase<G4TrackCounter>,
                             public IBeginEventActionTool,
                             public IEndRunActionTool,
                             public IPreTrackingActionTool
  {

    public:

      /// Standard constructor
      G4TrackCounterTool(const std::string& type, const std::string& name,
                         const IInterface* parent);

      /// Initialize tool - temporarily just for debugging
      virtual StatusCode initialize() override;

      /// Finalize and merge results from all threads
      virtual StatusCode finalize() override;

      /// Retrieve the begin-event action interface
      virtual IBeginEventAction* getBeginEventAction() override final
      { return static_cast<IBeginEventAction*>( getAction() ); }

      /// Retrieve the begin-event action interface
      virtual IEndRunAction* getEndRunAction() override final
      { return static_cast<IEndRunAction*>( getAction() ); }

      /// Retrieve the begin-event action interface
      virtual IPreTrackingAction* getPreTrackingAction() override final
      { return static_cast<IPreTrackingAction*>( getAction() ); }

      /// Query interface for gaudi
      virtual StatusCode queryInterface(const InterfaceID& riid, void** ppvInterface);

    protected:

      /// Create action for this thread
      virtual std::unique_ptr<G4TrackCounter> makeAction() override final;

  }; // class G4TrackCounterTool

} // namespace g4hive

#endif
