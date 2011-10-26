##############################################################################
# @file  SubversionTools.cmake
# @brief CMake functions and macros related to Subversion.
#
# Copyright (c) 2011 University of Pennsylvania. All rights reserved.
# See https://www.rad.upenn.edu/sbia/software/license.html or COPYING file.
#
# Contact: SBIA Group <sbia-software at uphs.upenn.edu>
#
# @ingroup CMakeTools
##############################################################################

if (__BASIS_SUBVERSIONTOOLS_INCLUDED)
  return ()
else ()
  set (__BASIS_SUBVERSIONTOOLS_INCLUDED TRUE)
endif ()


# ============================================================================
# required commands
# ============================================================================

find_package (Subversion)

## @brief The Subversion command (svn).
if (Subversion_FOUND)
  set (BASIS_CMD_SVN "${SVNCOMMAND}")
else ()
  find_program (BASIS_CMD_SVN NAMES svn DOC "Subversion command line client (svn).")
  mark_as_advanced (BASIS_CMD_SVN)
endif ()

## @addtogroup CMakeUtilities
#  @{

# ============================================================================
# retrieve SVN information
# ============================================================================

##############################################################################
# @brief Get current revision of file or directory.
#
# @param [in]  URL  Absolute path of directory or file. May also be a URL to the
#                   directory or file in the repository. A leading "file://" is
#                   automatically removed such that the svn command treats it as a
#                   local path.
# @param [out] REV  The revision number of URL. If URL is not under revision
#                   control or BASIS_CMD_SVN is invalid, "0" is returned.
#
# @returns Sets @p REV to the revision of the working copy/repository
#          at URL @p URL.

function (basis_svn_get_revision URL REV)
  set (OUT "0")

  if (BASIS_CMD_SVN)
    # remove "file://" from URL
    string (REGEX REPLACE "file://" "" TMP "${URL}")

    # retrieve SVN info
    execute_process (
      COMMAND         "${BASIS_CMD_SVN}" info "${TMP}"
      OUTPUT_VARIABLE OUT
      ERROR_QUIET
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # extract revision
    string (REGEX REPLACE "^(.*\n)?Revision: ([^\n]+).*" "\\2" OUT "${OUT}")

    if (OUT STREQUAL "")
      set (OUT "0")
    endif ()
  endif ()

  # return
  set ("${REV}" "${OUT}" PARENT_SCOPE)
endfunction ()

##############################################################################
# @brief Get revision number when directory or file was last changed.
#
# @param [in]  URL  Absolute path of directory or file. May also be a URL to the
#                   directory or file in the repository. A leading "file://" is
#                   automatically removed such that the svn command treats it as a
#                   local path.
# @param [out] REV  Revision number when URL was last modified. If URL is not
#                   under Subversion control or BASIS_CMD_SVN is invalid,
#                   "0" is returned.
#
# @returns Sets @p REV to revision number at which the working copy/repository
#          specified by the URL @p URL was last modified.

function (basis_svn_get_last_changed_revision URL REV)
  set (OUT "0")

  if (BASIS_CMD_SVN)
    # remove "file://" from URL
    string (REGEX REPLACE "file://" "" TMP "${URL}")

    # retrieve SVN info
    execute_process (
      COMMAND         "${BASIS_CMD_SVN}" info "${TMP}"
      OUTPUT_VARIABLE OUT
      ERROR_QUIET
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # extract last changed revision
    string (REGEX REPLACE "^(.*\n)?Last Changed Rev: ([^\n]+).*" "\\2" OUT "${OUT}")

    if (OUT STREQUAL "")
      set (OUT "0")
    endif ()
  endif ()

  # return
  set ("${REV}" "${OUT}" PARENT_SCOPE)
endfunction ()

##############################################################################
# @brief Get status of revision controlled file.
#
# @param [in]  URL    Absolute path of directory or file. May also be a URL to
#                     the directory or file in the repository.
#                     A leading "file://" will be removed such that the svn
#                     command treats it as a local path.
# @param [out] STATUS The status of URL as returned by 'svn status'.
#                     If the local directory or file is unmodified, an
#                     empty string is returned. An empty string is also
#                     returned when BASIS_CMD_SVN is invalid.
#
# @returns Sets @p STATUS to the output of the <tt>svn info</tt> command.

function (basis_svn_status URL STATUS)
  if (BASIS_CMD_SVN)
    # remove "file://" from URL
    string (REGEX REPLACE "file://" "" TMP "${URL}")

    # retrieve SVN status of URL
    execute_process (
      COMMAND         "${BASIS_CMD_SVN}" status "${TMP}"
      OUTPUT_VARIABLE OUT
      ERROR_QUIET
    )

    # return
    set ("${STATUS}" "${OUT}" PARENT_SCOPE)
  else ()
    set ("${STATUS}" "" PARENT_SCOPE)
  endif ()
endfunction ()

## @}