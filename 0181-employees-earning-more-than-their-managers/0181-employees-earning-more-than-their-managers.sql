# Write your MySQL query statement below
SELECT a.name AS Employee
from Employee AS a
join Employee AS b on a.managerId = b.Id
where a.salary > b.salary;