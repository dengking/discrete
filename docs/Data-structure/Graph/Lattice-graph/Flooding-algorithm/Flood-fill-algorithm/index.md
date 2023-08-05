# Flood fill 泛洪算法

一、在 labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw) 中，发现了这个算法，第一感觉就是 "探针"、"试探"。



## wikipedia [Flood fill](https://en.wikipedia.org/wiki/Flood_fill)

**Flood fill**, also called **seed fill**, is a [flooding algorithm](https://en.wikipedia.org/wiki/Flooding_algorithm) that determines and alters the area [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given node in a multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure) with some matching attribute. It is used in the "bucket" fill tool of [paint programs](https://en.wikipedia.org/wiki/Paint_program) to fill connected, similarly-colored areas with a different color, and in games such as [Go](https://en.wikipedia.org/wiki/Go_(game)) and [Minesweeper](https://en.wikipedia.org/wiki/Minesweeper_(video_game)) for determining which pieces are cleared. A variant called **boundary fill** uses the same algorithms but is defined as the area [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given node that does not have a particular attribute.[[1\]](https://en.wikipedia.org/wiki/Flood_fill#cite_note-79Smith-1)

