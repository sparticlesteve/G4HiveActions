// Local includes
#include "G4TrackCounter.h"

// Geant4 includes
#include "G4Event.hh"
#include "G4Run.hh"
#include "G4Track.hh"
#include "G4ios.hh"

// Other includes
#include "MCTruth/TrackHelper.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor for the count struct
  //---------------------------------------------------------------------------
  G4TrackCounter::TrackCounts::TrackCounts()
    : nEvents(0),
      nTotalTracks(0),
      nPrimaryTracks(0),
      nSecondaryTracks(0),
      n50MeVTracks(0)
  {}

  //---------------------------------------------------------------------------
  // Increment event counter
  //---------------------------------------------------------------------------
  void G4TrackCounter::beginOfEvent(const G4Event* /*event*/)
  {
    //G4cout << "G4TrackCounter@" << this << "::beginOfEvent" << G4endl;
    m_counts.nEvents++;
  }

  //---------------------------------------------------------------------------
  // Increment track counters
  //---------------------------------------------------------------------------
  void G4TrackCounter::preTracking(const G4Track* track)
  {
    //G4cout << "G4TrackCounter@" << this << "::preTracking" << G4endl;
    m_counts.nTotalTracks++;
    TrackHelper helper(track);

    // Primary tracks
    if(helper.IsPrimary() || helper.IsRegeneratedPrimary())
      m_counts.nPrimaryTracks++;

    // Secondary tracks
    if(helper.IsRegisteredSecondary())
      m_counts.nSecondaryTracks++;

    // 50 MeV tracks
    const double minE = 50.;
    if(track->GetKineticEnergy() > minE)
      m_counts.n50MeVTracks++;
  }

} // namespace g4hive
