package com.tencent.map.dataengine.craft.crossarearoadmarker.zebra;

import java.util.*;

public class GraphTransitiveClosure<T> {
    private Map<T, Set<T>> adjacencyList; // 图的adjacent list表示方式
    private List<Set<T>> closures; // 传递闭包

    /**
     * @param edges 图的边
     */
    public GraphTransitiveClosure(List<List<T>> edges) {
        adjacencyList = edges.parallelStream().collect(
                HashMap::new,
                (Map<T, Set<T>> map, List<T> edge) -> {
                    final Set<T> groups1 = map.getOrDefault(edge.get(0), new HashSet<>());
                    groups1.add(edge.get(1));
                    map.put(edge.get(0), groups1);

                    final Set<T> groups2 = map.getOrDefault(edge.get(1), new HashSet<>());
                    groups2.add(edge.get(0));
                    map.put(edge.get(1), groups2);
                },
                (Map<T, Set<T>> map1, Map<T, Set<T>> map2) -> {
                    map2.forEach((index, otherIndexes) -> {
                        if (map1.containsKey(index)) {
                            map1.get(index).addAll(otherIndexes);
                        } else {
                            map1.put(index, otherIndexes);
                        }
                    });
                });
        initClosures();
    }

    private void initClosures() {
        final Set<T> visitedSet = new HashSet<>();
        closures = new ArrayList<>();
        for (T node : adjacencyList.keySet()) {
            if (!visitedSet.contains(node)) {
                closures.add(initClosure(node, visitedSet));
            }
        }
    }

    /**
     * BFS
     * @param node
     * @param visitedSet
     * @return
     */
    private Set<T> initClosure(T node, Set<T> visitedSet) {
        Set<T> closure = new HashSet<>();
        Queue<T> queue = new LinkedList<>();
        queue.add(node);
        visitedSet.add(node);

        while (!queue.isEmpty()) {
            final T curNode = queue.remove();
            closure.add(curNode);
            for (T otherNode : adjacencyList.getOrDefault(curNode, new HashSet<>())) {
                if (!visitedSet.contains(otherNode)) {
                    visitedSet.add(otherNode);
                    queue.add(otherNode);
                }
            }
        }

        return closure;
    }

    public List<Set<T>> getClosures() {
        return closures;
    }
}
