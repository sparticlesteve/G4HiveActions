#ifndef G4HIVEACTIONS_G4TRACKCOUNTER_H
#define G4HIVEACTIONS_G4TRACKCOUNTER_H

// Local includes
#include "G4HiveActions/IBeginEventAction.h"
#include "G4HiveActions/IEndRunAction.h"
#include "G4HiveActions/IPreTrackingAction.h"


namespace g4hive
{

  /// @class G4TrackCounter
  /// @brief A simple action which counts tracks.
  ///
  /// This action currently implements BeginEvent, EndRun, and PreTracking
  /// interfaces. It's not clear if we really want to implement EndRun here.
  /// Presumably we'll need to merge the counter results across threads, so it
  /// might make sense to move some of that functionality in the finalize
  /// method of the corresponding tool.
  ///
  class G4TrackCounter : public IBeginEventAction,
                         public IEndRunAction,
                         public IPreTrackingAction
  {

    public:

      /// @brief Simple struct for holding the counts
      /// Might want to use a larger type for this...
      struct TrackCounts
      {
        TrackCounts();
        /// Event counter. Might want a larger int for this
        unsigned int nEvents;
        /// Total number of tracks
        unsigned int nTotalTracks;
        /// Number of primary tracks
        unsigned int nPrimaryTracks;
        /// Number of secondary tracks
        unsigned int nSecondaryTracks;
        /// Number of tracks with kinetic E > 50 MeV
        unsigned int nEnergeticTracks;
      };

      /// @brief Increments event counter.
      /// I feel like there must be a better way to get this info.
      /// Hmm, the G4Run has a numberOfEvent field...
      virtual void beginOfEvent(const G4Event* event) override;

      /// @brief Summarizes the track counters in stdout.
      /// This will probably need to be moved into the tool in order to merge
      /// results across all threads.
      virtual void endOfRun(const G4Run* run) override;

      /// Increments the track counters
      virtual void preTracking(const G4Track* track) override;

    private:

      /// Track counts for this thread.
      TrackCounts m_counts;

  }; // class G4TrackCounter

} // namespace g4hive

#endif
