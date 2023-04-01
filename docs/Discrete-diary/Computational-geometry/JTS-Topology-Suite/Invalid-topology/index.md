# Invalid polygon、invalid topology

[JTS Frequently Asked Questions # 2. Why does JTS allow geometries to be constructed with invalid topology?](https://locationtech.github.io/jts/jts-faq.html#B2)

[JTS Frequently Asked Questions # 1. How can I correct the topology of a Polygon that JTS is reporting as invalid?](https://locationtech.github.io/jts/jts-faq.html#G1)

- Compute [polygon.buffer(0)](https://locationtech.github.io/jts/javadoc/org/locationtech/jts/geom/Geometry.html#buffer-double-). The buffer operation is fairly insensitive to topological invalidity, and the act of computing the buffer can often resolve minor issues such as self-intersecting rings. However, in some situations the computed result may not be what is desired.
- If holes are overlapping the shell or other holes, create individual polygons from the shell and all the holes, and then subtract the holes from the shell.



[locationtech](https://github.com/locationtech)/**[jts](https://github.com/locationtech/jts)** # [Is there some kind of makeValid function for converting invalid polygons into multipolygons? #87](https://github.com/locationtech/jts/issues/87)



stackoverflow [Is there a way to convert a self intersecting polygon to a multipolygon in JTS?](https://stackoverflow.com/questions/31473553/is-there-a-way-to-convert-a-self-intersecting-polygon-to-a-multipolygon-in-jts)

> NOTE:
>
> 这是 [locationtech](https://github.com/locationtech)/**[jts](https://github.com/locationtech/jts)** # [Is there some kind of makeValid function for converting invalid polygons into multipolygons? #87](https://github.com/locationtech/jts/issues/87) 中提及的
>
> 

gis.stackexchange [Fix/Repair invalid Geometry](https://gis.stackexchange.com/questions/376260/fix-repair-invalid-geometry) 



[Fixing Invalid Geometry with JTS](http://lin-ear-th-inking.blogspot.com/2021/05/fixing-invalid-geometry-with-jts.html)



## [**GeometryFixer.java**](https://github.com/locationtech/jts/blob/master/modules/core/src/main/java/org/locationtech/jts/geom/util/GeometryFixer.java) 