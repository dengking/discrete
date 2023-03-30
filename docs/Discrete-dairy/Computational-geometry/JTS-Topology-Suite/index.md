# JTS Topology Suite



## wikipedia [JTS Topology Suite](https://en.wikipedia.org/wiki/JTS_Topology_Suite)





## JTS Topology Suite Technical Specifications

### 2、OTHER RESOURCES

OpenGIS Simple Features Specification For SQL Revision 1.1 (referred to as SFS in this document). This document provides the master specification for the **spatial data model** and the definitions of the **spatial predicates** and functions implemented by JTS.

### 3、DESIGN GOALS

JTS functions will support a **user-defined precision model**. JTS algorithms will be robust under that precision model.





## JTS Topology Suite Developer’s Guide



### \5. COMPUTING BUFFERS 

In GIS, buffering is an operation which in GIS is used to compute the area containing all points within a given distance of a Geometry. In mathematical terms, this is called computing the Minkowski sum of the Geometry with a disc of radius equal to the buffer distance. Finding positive and negative buffers is sometimes referred to as the operations of erosion and dilation. 

> NOTE:
>
> 在地理信息系统中，缓冲是一种操作，在地理信息系统中用于计算包含给定几何距离内所有点的面积。



### MultiPolygon

https://locationtech.github.io/jts/javadoc/org/locationtech/jts/geom/MultiPolygon.html

> Models a collection of [`Polygon`](https://locationtech.github.io/jts/javadoc/org/locationtech/jts/geom/Polygon.html)s.
>
> As per the OGC SFS specification, the Polygons in a MultiPolygon may not overlap, and may only touch at single points. This allows the topological point-set semantics to be well-defined.