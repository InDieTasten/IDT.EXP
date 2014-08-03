////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2014 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_MUTEXIMPL_HPP
#define SFML_MUTEXIMPL_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/System/NonCopyable.hpp>
#include <windows.h>


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
/// \brief Windows implementation of mutexes
////////////////////////////////////////////////////////////
class MutexImpl : NonCopyable
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    MutexImpl();

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~MutexImpl();

    ////////////////////////////////////////////////////////////
    /// \brief Lock the mutex
    ///
    ////////////////////////////////////////////////////////////
    void lock();

    ////////////////////////////////////////////////////////////
    /// \brief Unlock the mutex
    ///
    ////////////////////////////////////////////////////////////
    void unlock();

private :

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    CRITICAL_SECTION m_mutex; ///< Win32 handle of the mutex
};

} // namespace priv

} // namespace sf


#endif // SFML_MUTEXIMPL_HPP
