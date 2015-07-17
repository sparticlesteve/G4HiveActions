#ifndef G4HIVEACTIONS_THREADACTIONHOLDER_H
#define G4HIVEACTIONS_THREADACTIONHOLDER_H

#include <thread>
#include "tbb/concurrent_unordered_map.h"

namespace g4hive
{

  /// @brief A thread-local storage wrapper for the user actions.
  ///
  /// This container is implemented as a wrapper for a concurrent map
  /// keyed by std thread ID. It is thus fully thread-safe (I hope).
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  template<class ActionType>
  class ThreadActionHolder
  {

    public:

      /// @brief Get the object of the current thread.
      ActionType* get() {
        auto mapPair = m_threadMap.find( std::this_thread::get_id() );
        if(mapPair == m_threadMap.end()) return nullptr;
        return mapPair->second;
      }

      /// @brief Assign the object of the current thread.
      void set(ActionType* action) {
        const auto tid = std::this_thread::get_id();
        m_threadMap.insert( std::make_pair(tid, action) );
      }

    private:

      typedef std::thread::id ThreadMapKey_t;
      typedef ActionType* ThreadMapVal_t;
      typedef std::hash<ThreadMapKey_t> ThreadMapHash_t;
      typedef tbb::concurrent_unordered_map 
      < ThreadMapKey_t, ThreadMapVal_t, ThreadMapHash_t > ThreadMap_t;
      
      /// The wrapped thread-local storage container
      ThreadMap_t m_threadMap;

  }; // class ThreadActionHolder

}

#endif
