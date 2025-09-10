# Write your MySQL query statement below

SELECT c.name AS Customers
FROM Customers As c
LEFT JOIN Orders as o
ON c.id = o.customerId
where o.id IS NULL;