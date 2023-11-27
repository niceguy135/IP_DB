INSERT INTO users(user_id, name, surname, balance) VALUES (1, 'Roman', 'Efitov', 500);
INSERT INTO users(user_id, name, surname, balance) VALUES (2, 'Sam', 'Akimov', 2400);
INSERT INTO users(user_id, name, surname, balance, role) VALUES (3, 'Smith', 'Juggle', 900, 'Администратор');
INSERT INTO users(user_id, name, surname, balance) VALUES (4, 'Yuolter', 'Filatov', 3400);
INSERT INTO users(user_id, name, surname, balance) VALUES (5, 'Danil', 'Uraganov', 2950);
INSERT INTO users(user_id, name, surname, balance) VALUES (6, 'Sergey', 'Ezhov', 6785);

INSERT INTO stores(store_id, name, address) VALUES (1, 'Винлаб', 'Moscow, Zelenograd');
INSERT INTO stores(store_id, name, address) VALUES (2, 'Красное&Белое', 'Moscow, Zelenograd');
INSERT INTO stores(store_id, name, address) VALUES (3, 'Пятерочка', 'Moscow, Zelenograd');
INSERT INTO stores(store_id, name, address) VALUES (4, 'Ашан', 'Moscow, Zelenograd');

INSERT INTO products(product_id, name, type, strength) VALUES (1, 'Barton', 'Wine', 12);
INSERT INTO products(product_id, name, type, strength) VALUES (2, 'Piccini', 'Wine', 14);
INSERT INTO products(product_id, name, type, strength) VALUES (3, 'Edelweisshof', 'Wine', 12);
INSERT INTO products(product_id, name, type, strength) VALUES (4, 'Pata negra', 'Wine', 13);
INSERT INTO products(product_id, name, type, strength) VALUES (5, 'Chateau', 'Wine', 13);
INSERT INTO products(product_id, name, type, strength) VALUES (6, 'Faustion', 'Wine', 14);
INSERT INTO products(product_id, name, type, strength) VALUES (7, 'Sauvion', 'Wine', 11);
INSERT INTO products(product_id, name, type, strength) VALUES (8, 'Deffour', 'Wine', 13);
INSERT INTO products(product_id, name, type, strength) VALUES (9, 'Gaggion', 'Wine', 11);
INSERT INTO products(product_id, name, type, strength) VALUES (10, 'Concillo', 'Wine', 13);
INSERT INTO products(product_id, name, type, strength) VALUES (11, 'Noble', 'Wine', 13);
INSERT INTO products(product_id, name, type, strength) VALUES (12, 'Pasqua', 'Wine', 13);
INSERT INTO products(product_id, name, type, strength) VALUES (13, 'Tiflisa', 'Wine', 12);
INSERT INTO products(product_id, name, type, strength) VALUES (14, 'Scanavion', 'Wine', 11);

INSERT INTO inventory(store_id, product_id, price) VALUES (1, 1, 1444.43); 
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 2, 1333.32);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 3, 1111.10);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 4, 833.92);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 5, 1665.56);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 6, 1444.43);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 7, 1100.00);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 8, 843.33);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 9, 1123.50);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 10, 576.66);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 11, 632.22);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 12, 1100.00);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 13, 810.00);
INSERT INTO inventory(store_id, product_id, price) VALUES (1, 14, 1221.11);

INSERT INTO inventory(store_id, product_id, price) VALUES (4, 2, 1200.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (4, 4, 990.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (4, 5, 482.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (4, 9, 1899.99);

INSERT INTO products(product_id, name, type, strength) VALUES (15, 'Цица', 'Wine', 12);
INSERT INTO products(product_id, name, type, strength) VALUES (16, 'Фанагория', 'Wine', 13);
INSERT INTO products(product_id, name, type, strength) VALUES (17, 'Янтарная гроздь', 'Wine', 11);
INSERT INTO products(product_id, name, type, strength) VALUES (18, 'Шушук', 'Wine', 11);
INSERT INTO products(product_id, name, type, strength) VALUES (19, 'Четук', 'Wine', 12);
INSERT INTO products(product_id, name, type, strength) VALUES (20, 'Саперави', 'Wine', 11);
INSERT INTO products(product_id, name, type, strength) VALUES (21, 'Массандра', 'Wine', 16);
INSERT INTO products(product_id, name, type, strength) VALUES (22, 'Плодовая гранат', 'Wine', 12);
INSERT INTO products(product_id, name, type, strength) VALUES (23, 'Кагор', 'Wine', 16);
INSERT INTO products(product_id, name, type, strength) VALUES (24, 'Массандра Херес', 'Wine', 19);

INSERT INTO inventory(store_id, product_id, price) VALUES (2, 15, 229.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 16, 248.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 17, 168.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 18, 229.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 19, 229.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 20, 229.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 21, 446.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 22, 224.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 23, 334.99);
INSERT INTO inventory(store_id, product_id, price) VALUES (2, 24, 499.99);

INSERT INTO suppliers(supplier_id, name) VALUES (1, 'Кубань вино');
INSERT INTO suppliers(supplier_id, name) VALUES (2, 'Херес Массандра');
INSERT INTO suppliers(supplier_id, name) VALUES (3, 'Вагрус, ООО');
INSERT INTO suppliers(supplier_id, name) VALUES (4, 'Bodegas Faustion');
INSERT INTO suppliers(supplier_id, name) VALUES (5, 'Cantina sociale');
INSERT INTO suppliers(supplier_id, name) VALUES (6, 'Pasqua');
INSERT INTO suppliers(supplier_id, name) VALUES (7, 'Piccini');
INSERT INTO suppliers(supplier_id, name) VALUES (8, 'Les grands');
INSERT INTO suppliers(supplier_id, name) VALUES (9, 'Domaine');

INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 1);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 2);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 3);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 4);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 5);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 6);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 7);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 8);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(2, 9);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(1, 4);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(1, 5);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(1, 6);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(1, 7);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(1, 8);
INSERT INTO store_suppliers_relation(store_id, supplier_id) VALUES(1, 9);



