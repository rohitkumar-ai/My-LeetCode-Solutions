import collections

class Solution:
    def remainingMethods(
        self,
        n: int,
        k: int,
        invocations: list[list[int]]
    ) -> list[int]:

        # Store the final safe (remaining) methods.
        ans = []

        # Create an adjacency list where graph[u] stores all methods called by method u.
        graph = [[] for _ in range(n)]

        # Build the graph from the given method invocation pairs.
        for u, v in invocations:
            graph[u].append(v)

        # Start BFS from the suspicious method k.
        q = collections.deque([k])

        # Keep track of all suspicious methods already discovered.
        seen = {k}

        # Continue BFS until there are no more methods to visit.
        while q:

            # Process all nodes currently present in the queue.
            for _ in range(len(q)):

                # Remove the front method from the queue.
                current = q.popleft()

                # Visit every method called by the current method.
                for v in graph[current]:

                    # If this method has not been visited before.
                    if v not in seen:

                        # Add it to the queue for future processing.
                        q.append(v)

                        # Mark it as suspicious (visited).
                        seen.add(v)

        # Check every method in the program.
        for u in range(n):

            # Skip methods that are already suspicious.
            if u in seen:
                continue

            # Check every method called by this safe method.
            for v in graph[u]:

                # If a safe method calls a suspicious method.
                if v in seen:

                    # We cannot remove suspicious methods, so return all methods.
                    return list(range(n))

            # This method is safe, so keep it.
            ans.append(u)

        # Return all remaining safe methods.
        return ans