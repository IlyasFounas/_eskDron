

**The _eskDron database documentation**

This is the official documentation on how to use the database from the terminal.
The very first feature of the eskDron database is the shell parser.
So let's explore how the shell parser works.
Stay tuned, because I'm currently writing this documentation while I'm coding the database.
Some features will therefore be updated.

**Database in the terminal:**
Basically, at the beginning I was handling script files, because I come from the C programming language and I wanted to use `#define` and `void function()`.
But now it's even simpler to use.

So the first thing you can do is select the database you want to use.
Let's say you want to create a `user` table in the `my_project` database. You'll write something like this:

```
USE my_project
```

And then, to create the database, you can do this:

```
CREATE DATABASE
```

Or, if you prefer, you can simply write:

```
CREATE DATABASE my_project
```

But note that if you don't select a database name, you need to write this to create the table:

```
CREATE TABLE my_project/user
```

So for now, let's assume you're using a database name.

To create a table, you can write this:

```
CREATE TABLE user
```

Then, to add some columns:

```
_eskDron > ADD COLUMNS TO user
< give the name of the columns >
ID (pk int), NAME (string), PASSWORD (encoded64 string), EMAIL (unique string)
eskdron_query_engine: <table user_space/my_project/user successfully updated>
```
