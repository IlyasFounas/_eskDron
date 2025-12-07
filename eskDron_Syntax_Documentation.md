# 📘 **eskDron Database – Syntax Documentation**

## 🧠 Overview
The main function of the **esk syntax/script** is to provide a language that feels familiar and close to **C syntax**.  
It allows you to define variables, create databases and tables, and perform CRUD operations in a C-like manner.

---

## ⚙️ **Variable Definition**
You can define variables using the `#define` directive:

```c
#define DB test
#define TABLE user_test
```

To use a defined variable, prefix it with a `$` symbol.  
This helps the **esk_engine** recognize it as a variable.

⚠️ **Important:**  
You must define the variable *before* using it, otherwise a syntax error will occur.

Example:
```c
ESK_CREATE_DATABASE $DB;
```

---

## 🏗️ **Database and Table Creation**
Creating a database:
```c
ESK_CREATE_DATABASE $DB;
```

Creating a table:
```c
ESK_CREATE_TABLE $TABLE;
```

Yes, the prefix `ESK_` before every instruction can seem redundant,  
but it’s part of the **language’s identity and style**.

---

## 🔍 **CRUD Operations**
Like in C, esk syntax uses a structured, function-like approach.  
Here’s an example of a **SELECT** statement:

```c
ESK_SELECT fields($DB.$TABLE.password)
{
    from $DB.$TABLE
    filters $DB.$TABLE.column = 14,
            $DB.$TABLE.column.find("@hotmail.fr");
}
```

### Explanation:
- **`fields()`** → defines the columns you want to retrieve.  
- **`from`** → specifies the table to query.  
- **`filters`** → defines the conditions (similar to SQL’s `WHERE` clause).  
- You can chain filters with commas for multiple conditions.

---

## 🧩 Example Summary
Full example:

```c
#define DB test
#define TABLE user_test

ESK_CREATE_DATABASE $DB;
ESK_CREATE_TABLE $TABLE;

ESK_SELECT fields($DB.$TABLE.password)
{
    from $DB.$TABLE
    filters $DB.$TABLE.column = 14,
            $DB.$TABLE.column.find("@hotmail.fr");
}
```
