/**
 * @file odb.cpp
 *
 * @author Manfred Morgner
 * @date 26.12.2017
 */

#include "odb.h"

namespace odb {

void COdb::clear()
    {
    for ( auto & a:m_oThings )
        {
        a->clear();
        }
    m_oThings.clear();

    for ( auto & a:m_oAtoms )
        {
        a->clear();
        }
    m_oAtoms.clear();
    m_oProperties.clear();

    m_oReasons.clear();
    m_oStrands.clear();
    }

} // namespace odb
