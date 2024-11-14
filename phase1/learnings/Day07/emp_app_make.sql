-- Install vsc extensiion: "Oracle Developer Tools for VS Code"
-- $ sqlplus system/4321@localhost:1521/XEPDB1 as sysdba
-- sql> 
create user emp_db identified by josh;

grant connect,resource to emp_db;

alter user emp_db
   quota unlimited on users;

-- -CONNECT emp_db/4321@localhost:1521/XEPDB1;