#ifndef G4HIVEACTIONS_IENDEVENTACTION_H
#define G4HIVEACTIONS_IENDEVENTACTION_H

// Forward declarations
class G4Event;

namespace g4hive
{

  /// Simple interface for an ATLAS end-of-event action
  class IEndEventAction
  {
    public:
      /// Virtual destructor
      virtual ~IEndEventAction(){};
      /// Method called after simulating a G4 event
      virtual void endOfEvent(const G4Event*) = 0;
  };

} // namespace g4hive

#endif
