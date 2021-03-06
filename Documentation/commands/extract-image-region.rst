:orphan:

.. Auto-generated by help-rst from "mirtk extract-image-region -h" output

extract-image-region
====================

.. program:: extract-image-region


Synopsis
--------

::

    extract-image-region <input> <output> [options]


Description
-----------

.. include:: _descriptions/extract-image-region.rst



Arguments
---------

.. option:: input

   Input image file path.

.. option:: output

   Output file path.


Command options
---------------

.. option:: -Rx1 <int>

   Leftmost input voxel index along x axis.

.. option:: -Rx2 <int>

   Rightmost input voxel index along x axis.

.. option:: -Ry1 <int>

   Leftmost input voxel index along y axis.

.. option:: -Ry2 <int>

   Rightmost input voxel index along y axis.

.. option:: -Rz1 <int>

   Leftmost input voxel index along z axis.

.. option:: -Rz2 <int>

   Rightmost input voxel index along z axis.

.. option:: -Rt1 <int>

   Leftmost input voxel index along t axis.

.. option:: -Rt2 <int>

   Rightmost input voxel index along t axis.

.. option:: -patch <i> <j> <k> <nx> [<ny> [<nz>]]

   Extract image patch of given size centered at the specified voxel.

.. option:: -closest-patch <x> <y> <z> <nx> [<ny> [<nz>]]

   Extract image patch of given size centered at nearest voxel to specified point [mm].

.. option:: -landmarks <file>...

   Extract minimum bounding box containing the landmark points.

.. option:: -ref <file>

   Extract region specified by discrete reference image domain.

.. option:: -margin <int>

   Add fixed-width margin to union of image regions. (default: 0)

.. option:: -scale <float>

   Scale resulting region by specified factor. (default: 1)

.. option:: -crop [value]

   Crop background with intensity below or equal specified value. (default: 0)

.. option:: -pad [value]

   Pad output image by the specified value. (default: 0)

.. option:: -split <dim>|x|y|z|t

   Split extracted region along specified dimension into separate images.
   For example, use '-split z' to save individual slices of a 3D volume.
   The <output> file path is appended with a format string '_%03d' before
   the file name extension to create unique output file paths, unless such
   format specification is part of the given file path already.

.. option:: -swap [on|off]

   When :option:`-split` is used, first swap the dimension along which the
   extracted region is split with the last dimension such that when splitting
   a volume along the first dimension, the output image files have z=1. (default: off)

.. option:: -noswap

   Set :option:`-swap` to off.


Standard options
----------------

.. option:: -v, -verbose [n]

   Increase/Set verbosity of output messages. (default: 0)

.. option:: -debug [level]

   Increase/Set debug level for output of intermediate results. (default: 0)

.. option:: -version [major.minor]

   Print version and exit or set version to emulate.

.. option:: -revision

   Print revision (or version) number only and exit.

.. option:: -h, -help

   Print help and exit.
