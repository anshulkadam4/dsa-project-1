# Log Analytics Engine (C++)

## Overview
A C++-based log analytics system that processes user activity events (login/logout) and supports efficient time-based queries.

The system is designed to handle large-scale event streams with optimized query performance using data structures and algorithmic techniques.

---

## Features

- Add user activity events (login/logout)
- Query active users at any given time (O(log n))
- Compute maximum active users in a time window (O(n))
- Query user activity within a time range (O(log k))

---

## Key Concepts Used

- Prefix computation (active user tracking)
- Binary search (time-based queries)
- Sliding window (window-based maximum)
- Hash maps (user state management)

---

## Data Structures

- `vector<int> timestamps` → stores event times
- `vector<int> active_prefix` → active users after each event
- `unordered_map<int, bool> is_active` → current user state
- `unordered_map<int, vector<int>> user_timestamps` → per-user activity

---

## Time Complexity

| Operation | Complexity |
|----------|-----------|
| addEvent | O(1) |
| countActiveAt | O(log n) |
| userRangeQuery | O(log k) |
| slidingWindowMax | O(n) |

---

## Assumptions

- Events are added in chronological order
- If timestamps are equal, logout is processed before login
- Invalid transitions (double login/logout) are ignored

---

## Example

Input:
  - 1 101 login
  - 2 102 login
  - 3 101 logout
  - 4 103 login

Output:
  -countActiveAt(2) → 2
  -countActiveAt(3) → 1
  -countActiveAt(4) → 2
