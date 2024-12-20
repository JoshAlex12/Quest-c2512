-- Train Reservation System

I have UNF table 
    railway_booking 
        booking_id, booking_number, train_id, train_name, 
        passenger_id, passenger_name, passenger_city, 
        journey_date, from_station, to_station, 
        number_of_tickets, tickets_amount,
        ticket_plus_food_amount, payment_mode, 

        ticket1seat_number, ticket1_seat_price, 
        ticket2seat_number, ticket2_seat_price, 
        ticket3seat_number, ticket3_seat_price,
        
        food1_item_id, food1_item_name, food1_price, food1_qty, food1_amount,
        food2_item_id, food2_item_name, food2_price, food2_qty, food2_amount,
        food3_item_id, food3_item_name, food3_price, food1_qty, food3_amount,
        food4_item_id, food4_item_name, food4_price, food1_qty, food4_amount, 

I formed below NF tables.
        passenger: passenger_id, passenger_name, passenger_age
        train: train_id, train_name, route
        seat: seat_id, seat_number, class, seat_price
        food: item_id, item_name, price

        train_booking: booking_id, booking_number, 
            journey_date, train_id, passenger_id, number_of_tickets, 
            tickets_amount, food_amount, total_amount, payment_mode
            
        train_booking_food: booking_id, item_id, quantity, amount
        train_booking_seat: ticket_id, seat_id, price, booking_id  


--Tables:
    -- 1. Passenger Table
    -- 2. Train Table
    -- 3. Seat Table
    -- 4. Food Table
    -- 5. Booking Table
    -- 6. Booking Food Table
    -- 7. Booking Seat Table

--Creating tables

    -- 1. Passenger Table
    CREATE TABLE passenger (
        passenger_id NUMBER PRIMARY KEY,
        passenger_name VARCHAR2(100) NOT NULL,
        passenger_age NUMBER NOT NULL
    );

    -- 2. Train Table
    CREATE TABLE train (
        train_id NUMBER PRIMARY KEY,
        train_name VARCHAR2(100) NOT NULL,
        route VARCHAR2(255) NOT NULL
    );

    -- 3. Seat Table
    CREATE TABLE train_seat (
        seat_id NUMBER PRIMARY KEY,
        seat_number VARCHAR2(10) NOT NULL,
        class VARCHAR2(50) NOT NULL,
        seat_price NUMBER NOT NULL
    );

    -- 4. Food Table
    CREATE TABLE train_food (
        item_id NUMBER PRIMARY KEY,
        item_name VARCHAR2(100) NOT NULL,
        price NUMBER NOT NULL
    );

    -- 5. Booking Table
    CREATE TABLE train_booking (
        booking_id NUMBER PRIMARY KEY,
        booking_number VARCHAR2(20) NOT NULL,
        journey_date DATE NOT NULL,
        train_id NUMBER NOT NULL,
        passenger_id NUMBER NOT NULL,
        number_of_tickets NUMBER NOT NULL,
        ticket_amount NUMBER NOT NULL,
        food_amount NUMBER NOT NULL,
        total_amount NUMBER NOT NULL,
        payment_mode VARCHAR2(50) NOT NULL,
        FOREIGN KEY (train_id) REFERENCES train(train_id),
        FOREIGN KEY (passenger_id) REFERENCES passenger(passenger_id)
    );

    -- 6. Booking Food Table
    CREATE TABLE train_booking_food (
        booking_id NUMBER NOT NULL,
        item_id NUMBER NOT NULL,
        quantity NUMBER NOT NULL,
        amount NUMBER NOT NULL,
        PRIMARY KEY (booking_id, item_id),
        FOREIGN KEY (booking_id) REFERENCES train_booking(booking_id),
        FOREIGN KEY (item_id) REFERENCES train_food(item_id)
    );

    -- 7. Booking Seat Table
    CREATE TABLE train_booking_seat (
        booking_id NUMBER NOT NULL,
        seat_id NUMBER NOT NULL,
        price NUMBER NOT NULL,
        PRIMARY KEY (booking_id, seat_id),
        FOREIGN KEY (booking_id) REFERENCES train_booking(booking_id),
        FOREIGN KEY (seat_id) REFERENCES train_seat(seat_id)
    );



--Inserting Data to tables:
    -- 1. Passenger Table
        INSERT INTO passenger VALUES (1, 'Maheswaran', 40);
        INSERT INTO passenger VALUES (2, 'Josh', 60);
        INSERT INTO passenger VALUES (3, 'Dhaheen', 80);
        INSERT INTO passenger VALUES (4, 'Pitchumani', 55);
        INSERT INTO passenger VALUES (5, 'Bhagya', 95);
        INSERT INTO passenger VALUES (6, 'Nayana', 82);

        commit;

    -- 2. Train Table
        INSERT INTO train VALUES (1, 'Rockfort Exp', 'Chennai-Trichy');
        INSERT INTO train VALUES (2, 'Pandian Exp', 'Chennai-Madurai');
        INSERT INTO train VALUES (3, 'Mangalore Exp', 'Chennai-Mangalore');

        commit;

    -- 3. Seat Table
        INSERT INTO train_seat VALUES (1, 'S1-01', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (2, 'S1-02', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (3, 'S1-03', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (4, 'A1-01', 'AC', 1000);
        INSERT INTO train_seat VALUES (5, 'A1-02', 'AC', 1000);
        INSERT INTO train_seat VALUES (6, 'A1-03', 'AC', 1000);
        INSERT INTO train_seat VALUES (7, 'S2-01', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (8, 'S2-02', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (9, 'S2-03', 'Sleeper', 500);

        commit;

    -- 4. Food Table
        INSERT INTO train_food VALUES (1, 'Samosa', 60);
        INSERT INTO train_food VALUES (2, 'Coffee', 40);
        INSERT INTO train_food VALUES (3, 'Popcorn', 100);
        INSERT INTO train_food VALUES (4, 'Veg Meal', 150);
        INSERT INTO train_food VALUES (5, 'Non-Veg Meal', 200);

    -- 5. Booking Table
        INSERT INTO train_booking VALUES (1, 'B001', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 1, 1, 3, 1500, 300, 1800, 'UPI');
        INSERT INTO train_booking VALUES (2, 'B002', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 2, 2, 2, 2000, 300, 2300, 'Card');
        INSERT INTO train_booking VALUES (3, 'B003', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 3, 3, 1, 1000, 200, 1200, 'Cash');
        INSERT INTO train_booking VALUES (4, 'B004', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 1, 4, 1, 500, 100, 600, 'UPI');
        INSERT INTO train_booking VALUES (5, 'B005', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 2, 5, 2, 2000, 400, 2400, 'UPI');
        INSERT INTO train_booking VALUES (6, 'B006', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 3, 6, 1, 1000, 200, 1200, 'Card');

    -- 6. Booking Food Table
        INSERT INTO train_booking_seat VALUES (1, 1, 500);
        INSERT INTO train_booking_seat VALUES (1, 2, 500);
        INSERT INTO train_booking_seat VALUES (1, 3, 500);
        INSERT INTO train_booking_seat VALUES (2, 4, 1000);
        INSERT INTO train_booking_seat VALUES (2, 5, 1000);
        INSERT INTO train_booking_seat VALUES (3, 6, 1000);

    -- 7. Booking Seat Table
        INSERT INTO train_booking_food VALUES (1, 1, 2, 120);
        INSERT INTO train_booking_food VALUES (1, 2, 2, 80);
        INSERT INTO train_booking_food VALUES (2, 4, 2, 300);
        INSERT INTO train_booking_food VALUES (3, 3, 2, 200);

        commit;


Passenger Table:
passenger_id | passenger_name | passenger_age
1            | Maheswaran     | 40
2            | Josh           | 60
3            | Dhaheen        | 80
4            | Pitchumani     | 55
5            | Bhagya         | 95
6            | Nayana         | 82

Train Table:
train_id | train_name        | route
1        | Rockfort Exp      | Chennai-Trichy
2        | Pandian Exp       | Chennai-Madurai
3        | Mangalore Exp     | Chennai-Mangalore

Train_Seat Table:
seat_id | seat_number | class      | seat_price
1       | S1-01       | Sleeper    | 500
2       | S1-02       | Sleeper    | 500
3       | S1-03       | Sleeper    | 500
4       | A1-01       | AC         | 1000
5       | A1-02       | AC         | 1000
6       | A1-03       | AC         | 1000
7       | S2-01       | Sleeper    | 500
8       | S2-02       | Sleeper    | 500
9       | S2-03       | Sleeper    | 500

Train_Food Table:
item_id | item_name      | price
1       | Samosa         | 60
2       | Coffee         | 40
3       | Popcorn        | 100
4       | Veg Meal       | 150
5       | Non-Veg Meal   | 200


Train_Booking Table:
booking_id | booking_number | journey_date | train_id | passenger_id | number_of_tickets | ticket_amount | food_amount | total_amount | payment_mode
1          | B001           | 2024-11-18   | 1        | 1            | 3                 | 1500          | 300         | 1800         | UPI
2          | B002           | 2024-11-18   | 2        | 2            | 2                 | 2000          | 300         | 2300         | Card
3          | B003           | 2024-11-18   | 3        | 3            | 1                 | 1000          | 200         | 1200         | Cash
4          | B004           | 2024-11-19   | 1        | 4            | 1                 | 500           | 100         | 600          | UPI
5          | B005           | 2024-11-19   | 2        | 5            | 2                 | 2000          | 400         | 2400         | UPI
6          | B006           | 2024-11-19   | 3        | 6            | 1                 | 1000          | 200         | 1200         | Card

Train_Booking_Food Table:
booking_id | item_id | quantity | amount
1          | 1       | 2        | 120
1          | 2       | 2        | 80
2          | 4       | 2        | 300
3          | 3       | 2        | 200

Train_Booking_Seat Table:
booking_id | seat_id | price
1          | 1       | 500
1          | 2       | 500
1          | 3       | 500
2          | 4       | 1000
2          | 5       | 1000
3          | 6       | 1000


--Queries
    -- Update query
        -- 1. Increase the price of all AC seats by 20%.
        UPDATE train_seat
        SET seat_price = seat_price * 1.2
        WHERE class = 'AC';

        -- 2. Update the total amount for all bookings to reflect a 5% discount.
        UPDATE train_booking
        SET total_amount = total_amount * 0.95;

        -- 3. Change the name of the train "Rockfort Exp" to "Rockfort Express".
        UPDATE train
        SET train_name = 'Rockfort Express'
        WHERE train_name = 'Rockfort Exp';

        -- 4. Assign a NULL payment mode to all bookings where the amount exceeds ₹2000.
        UPDATE train_booking
        SET payment_mode = NULL
        WHERE total_amount > 2000;

        -- 5. Add ₹50 to the price of every food item costing less than ₹100.
        UPDATE train_food
        SET price = price + 50
        WHERE price < 100;

    -- Sub query
        -- 1. Find the names of passengers who booked more than 2 tickets.
        SELECT passenger_name
        FROM passenger
        WHERE passenger_id IN (
            SELECT passenger_id
            FROM train_booking
            WHERE number_of_tickets > 2
        );

        -- 2. List all trains that have bookings with total amounts exceeding ₹2000.
        SELECT train_name
        FROM train
        WHERE train_id IN (
            SELECT train_id
            FROM train_booking
            WHERE total_amount > 2000
        );

        -- 3. Find the booking IDs where at least one AC seat was booked.
        SELECT booking_id
        FROM train_booking_seat
        WHERE seat_id IN (
            SELECT seat_id
            FROM train_seat
            WHERE class = 'AC'
        );

        -- 4. Identify the food items ordered in bookings for the train "Pandian Exp".
        SELECT item_name
        FROM train_food
        WHERE item_id IN (
            SELECT item_id
            FROM train_booking_food
            WHERE booking_id IN (
                SELECT booking_id
                FROM train_booking
                WHERE train_id = (SELECT train_id FROM train WHERE train_name = 'Pandian Exp')
            )
        );

        -- 5. Retrieve the passenger names who booked tickets for the "Sleeper" class.
        SELECT passenger_name
        FROM passenger
        WHERE passenger_id IN (
            SELECT passenger_id
            FROM train_booking
            WHERE booking_id IN (
                SELECT booking_id
                FROM train_booking_seat
                WHERE seat_id IN (
                    SELECT seat_id
                    FROM train_seat
                    WHERE class = 'Sleeper'
                )
            )
        );


    -- Correlated query 
        -- 1. Find the bookings where the ticket amount exceeds the combined price of the seats booked.
        SELECT b.booking_id, b.ticket_amount
        FROM train_booking b
        WHERE b.ticket_amount > (
            SELECT SUM(ts.seat_price)
            FROM train_booking_seat tbs
            JOIN train_seat ts ON tbs.seat_id = ts.seat_id
            WHERE tbs.booking_id = b.booking_id
        );

        -- 2. Retrieve the names of passengers who ordered food costing more than ₹500 in total
        SELECT passenger_name
        FROM passenger p
        WHERE (
            SELECT SUM(amount)
            FROM train_booking_food
            WHERE booking_id IN (
                SELECT booking_id
                FROM train_booking
                WHERE passenger_id = p.passenger_id
            )
        ) > 500;


        -- 3. Identify bookings where the number of tickets is greater than the number of seats booked.
        SELECT b.booking_id, b.number_of_tickets
        FROM train_booking b
        WHERE b.number_of_tickets > (
            SELECT COUNT(*)
            FROM train_booking_seat
            WHERE booking_id = b.booking_id
        );

        -- 4. Retrieve all trains where the average seat price is greater than ₹800.
        SELECT t.train_name
        FROM train t
        WHERE (
            SELECT AVG(ts.seat_price)
            FROM train_seat ts
            WHERE ts.seat_id IN (
                SELECT seat_id
                FROM train_booking_seat
                WHERE booking_id IN (
                    SELECT booking_id
                    FROM train_booking
                    WHERE train_id = t.train_id
                )
            )
        ) > 800;

        -- 5. Find passengers who booked more than 2 tickets
        SELECT passenger_name
        FROM passenger p
        WHERE (
            SELECT SUM(number_of_tickets)
            FROM train_booking
            WHERE passenger_id = p.passenger_id
        ) > 2;

    -- Join query
        -- 1. List all passengers, their train names, and the total amounts they paid.
        SELECT p.passenger_name, t.train_name, b.total_amount
        FROM train_booking b
        JOIN passenger p ON b.passenger_id = p.passenger_id
        JOIN train t ON b.train_id = t.train_id;

        -- 2. Find the seat numbers booked by "Maheswaran".
        SELECT ts.seat_number
        FROM passenger p
        JOIN train_booking b ON p.passenger_id = b.passenger_id
        JOIN train_booking_seat tbs ON b.booking_id = tbs.booking_id
        JOIN train_seat ts ON tbs.seat_id = ts.seat_id
        WHERE p.passenger_name = 'Maheswaran';

        -- 3. Retrieve all food items ordered for the train "Mangalore Exp".
        SELECT tf.item_name, bf.quantity, bf.amount
        FROM train_food tf
        JOIN train_booking_food bf ON tf.item_id = bf.item_id
        JOIN train_booking b ON bf.booking_id = b.booking_id
        JOIN train t ON b.train_id = t.train_id
        WHERE t.train_name = 'Mangalore Exp';

        -- 4. Get the total ticket amount collected for each train.
        SELECT t.train_name, SUM(b.ticket_amount) AS total_ticket_amount
        FROM train t
        JOIN train_booking b ON t.train_id = b.train_id
        GROUP BY t.train_name;

        -- 5. List passengers who booked tickets in the AC class.
        SELECT DISTINCT p.passenger_name
        FROM passenger p
        JOIN train_booking b ON p.passenger_id = b.passenger_id
        JOIN train_booking_seat tbs ON b.booking_id = tbs.booking_id
        JOIN train_seat ts ON tbs.seat_id = ts.seat_id
        WHERE ts.class = 'AC';


    -- Delete query

        -- 1. Delete all bookings made for the train "Pandian Exp".
        DELETE FROM train_booking
        WHERE train_id = (SELECT train_id FROM train WHERE train_name = 'Pandian Exp');

        -- 2. Remove all food orders where the item name is "Popcorn".
        DELETE FROM train_booking_food
        WHERE item_id = (SELECT item_id FROM train_food WHERE item_name = 'Popcorn');

        -- 3. Delete all seat records where the price is less than ₹500.
        DELETE FROM train_seat
        WHERE seat_price < 500;

        -- 4. Remove all bookings where no food was ordered.
        DELETE FROM train_booking
        WHERE booking_id NOT IN (
            SELECT DISTINCT booking_id
            FROM train_booking_food
        );

        -- 5. Delete all train records where no bookings have been made.
        DELETE FROM train
        WHERE train_id NOT IN (
            SELECT DISTINCT train_id
            FROM train_booking
        );
