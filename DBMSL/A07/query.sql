create table library_table (
    id int primary key not null,
    title varchar(300) not null,
    author varchar(300) not null,
    price int not null
);

create table audit_table (
    id int not null,
    title varchar(300) not null,
    author varchar(300) not null,
    price int not null,
    action varchar(300) not null,
    changed_at timestamp default now()
);

insert into library_table
values (1, 'Babylon', 'Clason', 190),
(2, 'Rich Dad', 'R Kiyo', 230),
(3, '7 Habits', 'Nepo Hill', 400),
(4, 'Room 105', 'C Bhagat', 130),
(5, 'Ice and Fire', 'GR Martin', 800),
(6, 'LOTR', 'Tolkin', 900);

delimiter $$
create trigger delete_trig after delete 
on library_table
for each row
insert into audit_table
values (OLD.id, OLD.title, OLD.author, OLD.price, "deleted", now()); $$
delimiter ;

delimiter $$
create trigger update_trig before update 
on library_table
for each row
insert into audit_table
values (OLD.id, OLD.title, OLD.author, OLD.price, 'updated', now()); $$
delimiter ;

delete from library_table where id=6;
update library_table set price=100 where id=1;