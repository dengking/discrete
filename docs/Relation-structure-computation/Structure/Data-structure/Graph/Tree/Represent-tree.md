# Represent tree

## [Visually  Representing Trees ](https://en.wikipedia.org/wiki/Tree_structure#Representing_trees)

There are many ways of visually representing tree structures. Almost always, these boil down to variations, or combinations, of a few basic styles:

### Classical node-link diagrams

Classical node-link diagrams, that connect nodes together with line segments:

```
	encyclopedia
	/			\
culture			science	
/		\
art		craft	

```

### Nested sets

[Nested sets](https://en.wikipedia.org/wiki/Nested_set_model) that use enclosure/containment to show parenthood, examples include [TreeMaps](https://en.wikipedia.org/wiki/Treemapping) and [fractal maps](https://en.wikipedia.org/w/index.php?title=Fractal_space_map&action=edit&redlink=1):

```

```

### Layered "icicle" diagrams

Layered "icicle" diagrams that use alignment/adjacency.

### Outlines and tree views

Lists or diagrams that use indentation, sometimes called "[outlines](https://en.wikipedia.org/wiki/Outline_(hierarchical))" or "[tree views](https://en.wikipedia.org/wiki/Tree_view)".



A tree view:

- encyclopedia
  - culture
    - **art**
    - **craft**
  - **science**



### Nested parentheses

*See also:* [Newick format](https://en.wikipedia.org/wiki/Newick_format) *and* [Dyck language](https://en.wikipedia.org/wiki/Dyck_language)

A correspondence to nested parentheses was first noticed by Sir [Arthur Cayley](https://en.wikipedia.org/wiki/Arthur_Cayley):

```
((art,craft)culture,science)encyclopedia
or
encyclopedia(culture(art,craft),science)
```

### Radial trees

*See also:* [Radial tree](https://en.wikipedia.org/wiki/Radial_tree)

Trees can also be [represented radially](https://en.wikipedia.org/wiki/Radial_tree):

```
art craft
\	/ 
culture
    |
encyclopedia
    |
science
```



> Note: The following content comes from the [the dragon book](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 6.2 Three-Address Code:
>
> Three-address code is a **linearized representation** of a syntax tree or a DAG in which explicit names correspond to the interior nodes of the graph. 

### [Three-address code](https://en.wikipedia.org/wiki/Three-address_code)





### [Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)







## [Representing Tree in Memory/Implementation](https://en.wikipedia.org/wiki/Tree_(data_structure)#Representations)

The following is a partial enumeration:

- represent the nodes as [dynamically allocated](https://en.wikipedia.org/wiki/Dynamic_memory_allocation) records with pointers to their children, their parents, or both
- represent the nodes as items in an [array](https://en.wikipedia.org/wiki/Array_data_structure), with relationships between them determined by their positions in the array (e.g., [binary heap](https://en.wikipedia.org/wiki/Binary_heap)).

For a more complete enumeration, click the link above.