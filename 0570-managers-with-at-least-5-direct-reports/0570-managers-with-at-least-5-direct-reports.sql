# Write your MySQL query statement below
select e.name
from employee e
inner join employee b on e.id=b.managerId
group by b.managerId 
having count(b.managerId)>=5
