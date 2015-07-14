#ifndef G4HIVEACTIONS_IBEGINEVENTACTION_H
#define G4HIVEACTIONS_IBEGINEVENTACTION_H

// Forward declarations
class G4Event;

namespace g4hive
{

  /// Simple interface for an ATLAS begin-of-event action
  class IBeginEventAction
  {
    public:
      /// Method called before simulating a G4 event
      virtual void beginOfEvent(const G4Event*) = 0;
  };

} // namespace g4hive

#endif
