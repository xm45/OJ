# Write your MySQL query statement below
select Name as Customers
from Customers c
where
not exists (select * from Orders o where c.Id = o.CustomerId)