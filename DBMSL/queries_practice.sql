delimiter //

create procedure getAllProducts(
    in param1 int,
    out param2 int,
    inout param2 int
)
begin
    declare costs, val, tot int default 0;
    set val = 100;

    select count(*)
    into tot
    from products;

    select * from products;
    select tot;

end //

delimiter ;

call getAllProducts();

drop procedure if exists getAllProducts;

show procedure status;