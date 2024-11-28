create user train_db identified by josh;
grant connect,resource to train_db;
alter user train_db quota unlimited on users;