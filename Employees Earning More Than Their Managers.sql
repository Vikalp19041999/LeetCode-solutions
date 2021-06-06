# Write your MySQL query statement below
SELECT e.Name AS Employee
FROM Employee e, Employee m
WHERE e.ManagerId IS NOT NULL AND e.ManagerId = m.ID and e.Salary > m.Salary