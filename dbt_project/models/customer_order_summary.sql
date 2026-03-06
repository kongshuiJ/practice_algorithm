SELECT
    c.name,
    COUNT(o.order_id) AS total_orders,
    SUM(o.amount) AS total_amount
FROM {{ ref('customers') }} AS c
JOIN {{ ref('orders') }} AS o ON c.customer_id = o.customer_id
WHERE o.status = 'completed'
GROUP BY c.name
ORDER BY total_amount DESC
