.. Auto-generated by help-rst from "mirtk project-onto-surface -h" output

.. |project-onto-surface-brief-description| replace::

   Assign scalars or labels to either the vertices or the cells of a surface mesh.
   When the input is a real-valued image, the values are linearly interpolated.
   When the input is a segmentation image, the value assigned to a vertex/cell is the
   label of the nearest voxel in the given segmentation image. For the projection of
   cortical labels onto the WM/GM or GM/CSF boundary, use :option:`project-onto-surface -white` or :option:`project-onto-surface -pial`.
