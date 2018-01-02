#ifndef THING_H
#define THING_H

/*  thing.h
 *
 *  Created on: 26.12.2017
 *      Author: manfred morgner
 */

#include <deque>
#include <ostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <set>
#include <functional>

#include "generic.h"
#include "atom.h"


namespace odb {

using namespace std::string_literals;


/**
 * A Thing as they are many of
 */
class CThing : public std::enable_shared_from_this<CThing>,
               public Identifiable<CThing> {
    public:
      static constexpr auto g_csNameUnnamedThing{"unnamedThing"};
    public:
	         CThing();
             CThing(std::string const & crsName);
	         CThing(CThing const &) = default;
	virtual ~CThing();

	friend std::ostream & operator << (std::ostream & ros, CThing const & crThing);

    std::string const & NameGet() const;

    PAtom Append (PAtom poAtom);

    PThing Link(PThing po2Thing, PReason po4Reason);

    PThing RelatingThingAdd(PThing poThing);

    protected:
        std::string                              m_sName{g_csNameUnnamedThing};
        CAtoms                                   m_qpoAtoms;
        std::unordered_multimap<PThing, PReason> m_mLink;

        /// We need a set to get only one backreference from CThings
        /// even if there are multiple incoming links
        struct lessPThing
          {
          bool operator()(PThing const p1, PThing const p2) const
            { return p1->id < p2->id; }
          };
        std::set<PThing, lessPThing>             m_spoThingsRelating;

    }; // class CThing

} // namespace odb

// THING_H
#endif
