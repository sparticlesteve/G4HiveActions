#ifndef G4HIVEACTIONS_IPRETRACKINGACTION_H
#define G4HIVEACTIONS_IPRETRACKINGACTION_H

// Forward declarations
class G4Track;

namespace g4hive
{

  /// Simple interface for an ATLAS pre-tracking action
  class IPreTrackingAction
  {
    public:
      /// Method called before tracking a particle
      virtual void preTracking(const G4Track*) = 0;
  };

} // namespace g4hive

#endif
