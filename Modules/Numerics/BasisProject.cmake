# ==============================================================================
# Medical Image Registration ToolKit (MIRTK)
#
# Copyright 2013-2015 Imperial College London
# Copyright 2013-2015 Andreas Schuh
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

################################################################################
# @file  BasisProject.cmake
# @brief Sets basic information about the MIRTK module and calls basis_project().
#
# This file defines basic information about a project by calling 
# the basis_project() function. This basic information, also known as metadata, 
# is used by CMake BASIS to setup the project. The dependencies to other modules
# have to be specified here such that the top-level IRTK project can analyze the
# inter-module dependencies, as well as dependencies on third-party libraries.
#
# @sa http://opensource.andreasschuh.com/cmake-basis/standard/modules.html
#
# @ingroup BasisSettings
################################################################################

# Note: The #<*> dependency patterns are required by the basisproject tool and
#       should be kept on a separate line as last commented argument of the
#       corresponding options of the basis_project() command. The TEMPLATE
#       option and set argument are also required by this tool and should not
#       be changed manually. The argument is updated by basisproject --update.

basis_project (

  # ----------------------------------------------------------------------------
  # meta-data
  NAME        "Numerics"
  PACKAGE     "MIRTK"
  AUTHORS     "Andreas Schuh"
  DESCRIPTION "Numerics library of the Medical Image Registration ToolKit."
  COPYRIGHT   "2013-2015 Imperial College London, Andreas Schuh"
  LICENSE     "Apache License Version 2.0"
  CONTACT     "Andreas Schuh <andreas.schuh.84@gmail.com>"
  TEMPLATE    "mirtk-module/1.0"

  # ----------------------------------------------------------------------------
  # dependencies
  DEPENDS
    MIRTK{Common}
    Boost-1.48 # {random} used, headers only
    Eigen3
    #<dependency>
  OPTIONAL_DEPENDS
    ARPACK
    UMFPACK
    LBFGS
    MATLAB{mwmclmcrrt}
    VTK-7|6{vtkCommonCore,vtkCommonDataModel,vtkIOGeometry,vtkIOLegacy,vtkIOPLY,vtkIOXML}
    TBB{tbb} # transitive dependency of MIRTK{Common}
    #<optional-dependency>
  TEST_DEPENDS
    GTest
    #<test-dependency>
  OPTIONAL_TEST_DEPENDS
    #<optional-test-dependency>

)