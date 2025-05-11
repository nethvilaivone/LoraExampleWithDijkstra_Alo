     int absWeight = abs(weight);
        if (absWeight > 0) {
            adjMatrix[u][v] = absWeight;
            adjMatrix[v][u] = absWeight; // Undirected graph
        }
        else {
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0; // No edge
        }