def bfs(graph, start_node):
    visited, need_visit = list(), list()
    need_visit.append(start_node)
    
    while need_visit:
        node = need_visit.pop(0) #queue
        if node not in visited:
            visited.append(node)
            need_visit.extend(graph[node])
    return visited