DROP TABLE IF EXISTS users CASCADE;
DROP TABLE IF EXISTS stores CASCADE;
DROP TABLE IF EXISTS suppliers CASCADE;
DROP TABLE IF EXISTS store_suppliers_relation CASCADE;
DROP TABLE IF EXISTS products CASCADE;
DROP TABLE IF EXISTS inventory CASCADE;
DROP TABLE IF EXISTS orders CASCADE;
DROP TABLE IF EXISTS orders_history CASCADE;

DROP INDEX IF EXISTS inventory_on_product;
DROP INDEX IF EXISTS inventory_on_store;
DROP INDEX IF EXISTS order_on_user;

DROP FUNCTION IF EXISTS add_order_history();
DROP TRIGGER IF EXISTS add_order_history_before_delete_order ON orders;


CREATE TABLE users (
	user_id SERIAL PRIMARY KEY,

	name VARCHAR(30) NOT NULL, 
	surname VARCHAR(30),
	balance MONEY,
	role VARCHAR(30) DEFAULT 'Пользователь'
);

CREATE TABLE stores(
	store_id SERIAL PRIMARY KEY,

	name VARCHAR(30) NOT  NULL,
	address VARCHAR(255) NOT NULL
);

CREATE TABLE suppliers(
	supplier_id SERIAL PRIMARY KEY,

	name VARCHAR(30) NOT NULL
);

CREATE TABLE products(
	product_id SERIAL PRIMARY KEY,

	name VARCHAR(30) NOT NULL,
	type VARCHAR(16) NOT NULL,
	strength INTEGER CHECK (strength >= 0 AND strength <= 100) NOT NULL 
);

CREATE TABLE inventory(
	store_id INTEGER REFERENCES stores(store_id),
	product_id INTEGER REFERENCES products(product_id),

	price MONEY NOT NULL,
	
	PRIMARY KEY(store_id , product_id)
);

CREATE TABLE orders(
	order_id SERIAL PRIMARY KEY,
	user_id INTEGER REFERENCES users(user_id),
        store_id INTEGER REFERENCES stores(store_id),
	product_id INTEGER REFERENCES products(product_id),
	
	price MONEY NOT NULL,
	name VARCHAR(30) DEFAULT 'Мой заказ',
   	address VARCHAR(120) NOT NULL,
	date TIMESTAMP DEFAULT CURRENT_DATE,
	state VARCHAR DEFAULT 'В обработке'
);

CREATE TABLE orders_history(
	order_history_id SERIAL PRIMARY KEY,

	user_id INTEGER REFERENCES users(user_id),
	price MONEY NOT NULL,
	date TIMESTAMP NOT NULL
);

CREATE TABLE store_suppliers_relation (
	store_id INTEGER REFERENCES stores(store_id),
	supplier_id INTEGER REFERENCES suppliers(supplier_id),
	
	PRIMARY KEY(store_id, supplier_id)
);

CREATE INDEX inventory_on_product ON inventory(product_id);
CREATE INDEX inventory_on_store ON inventory(store_id);
CREATE INDEX order_on_user ON orders(user_id);

CREATE OR REPLACE FUNCTION add_order_history()
RETURNS TRIGGER AS $$
BEGIN
	INSERT INTO orders_history(user_id, price, date) VALUES (OLD.user_id, OLD.price, OLD.date);
	
	RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER add_order_history_before_delete_order
BEFORE DELETE ON orders
FOR EACH ROW
EXECUTE FUNCTION add_order_history()


