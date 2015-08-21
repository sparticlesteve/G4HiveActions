#ifndef G4HIVEACTIONS_ATLASSTACKINGACTION_H
#define G4HIVEACTIONS_ATLASSTACKINGACTION_H

// Local includes
#include "G4HiveActions/IStackingAction.h"


namespace g4hive
{

  /// @class AtlasStackingAction
  /// @brief Implements general ATLAS custom stacking functionality.
  /// Mostly taken from the AthenaStackingAction in G4AtlasAlg.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class AtlasStackingAction : public IStackingAction
  {

    public:

      /// Configuration option struct for AtlasStackingAction.
      struct Config
      {
        /// Flag to toggle killing neutrinos at tracking stage
        bool killAllNeutrinos;
        /// Photon energy cut
        double photonEnergyCut;
      };

      /// Constructor with configuration
      AtlasStackingAction(const Config& config);

      /// @brief Classify a new track.
      /// Result can be fUrgent, fWaiting, fPostpone, or fKill.
      virtual G4ClassificationOfNewTrack
      classifyNewTrack(const G4Track* track) override;

      /// @brief Called when starting the next priority queue.
      /// The waiting stack gets moved into the urgent stack.
      virtual void newStage() override;

      /// @brief Invoked by stack manager at new event.
      /// This method is possibly redundant so we could maybe remove it.
      virtual void prepareNewEvent() override;

    private:

      /// @brief Identify track as a neutrino.
      /// It might be useful to move this kind of functionality
      /// into some standalong helper function(s).
      bool isNeutrino(const G4Track*) const;
      /// @brief Identify track as a photon.
      bool isGamma(const G4Track*) const;

      /// My configuration options
      Config m_config;

  }; // class AtlasStackingAction

} // namespace g4hive

#endif
