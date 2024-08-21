# Write your MySQL query statement below
select p.product_id, 
ifnull(round(sum(units*price)/sum(units),2),0)
as average_price

from prices as p 
left join unitsSold as s on p.product_id=s.product_id and purchase_date between start_date AND end_date
group by product_id
