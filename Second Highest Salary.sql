SELECT IFNULL(
    Null, 
    (SELECT DISTINCT Salary FROM Employee 
     ORDER BY Salary DESC LIMIT 1 OFFSET 1)
 )
as SecondHighestSalary