#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 1024

struct Address {
	int id;
	int set;
	char *name[];
	char *email[];
};

struct Database {
	struct Address *rows;
};

struct Connection {
	FILE *file;
	struct Database *db;
};

//Task one: change 'die' so it can free memory after conn struct
void die (const char *message, struct Connection *conn) 
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	free(conn);

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Database could not be loaded.", conn);
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error.", conn);

	conn->db = malloc(sizeof(struct Database));
	if (!conn->db)
		die("Memory error.", conn);

	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file) {
			Database_load(conn);
		}
	}

	if (!conn->file) 
		die("Could not open the file", conn);

	return conn;
}

void Database_close(struct Connection *conn)
{
	if(conn) {
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Could not save into the database.", conn);

	rc = fflush(conn->file);
	if (rc == -1)
		die("Could not empty the database.", conn);
}

void Database_create(struct Connection *conn, int max_rows)
{
	int i = 0;
	char rows_no[] = max_rows + '0'
	

	for (i = 0; i < max_rows; i++) {
	       //Creating a prototype
	       struct Address addr  = {.id = i,.set = 0	};
	       //Data to prototype
	       conn->db->rows[i] = addr;
	}

	rewind(conn->file);

	int rc = fwrite(itoa(rows_no), sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Could not save into the database.", conn);

	rc = fflush(conn->file);
	if (rc == -1)
		die("Could not empty the database.", conn);
}

}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if (addr->set)
		die("Data already exists, delete them first.", conn);

	addr->set = 1;
	char *res = strncpy(addr->name, name, MAX_DATA);
	if (!res)
		die("Could not copy the name.", conn);

	res = strncpy(addr->email, email, MAX_DATA);
	if (!res)
		die("Could not copt the email.", conn);
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set) {
		Address_print(addr);
	} else {
		die("Id could not be identified.", conn);
	}
	
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id,.set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn, int max_rows)
{
	int i = 0;
	struct Database *db = conn->db;

	for(i = 0; i < max_rows; i++) {
		struct Address *cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

int main (int argc, char *argv[])
{
	//max_rows = argv[4]
	//max_data = argv[3]


	if (argc < 3)
		die("Usage: ./ex17 <base> <action> [action parameters]", NULL);

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if (argc > 3) id = atoi(argv[3]);
	if (id >= argv[4]) die("Not enough records.", conn);

	switch (action) {
		case 'c':
			Database_create(conn, argv[4]);
			Database_write(conn);
			break;

		case 'g': 
			if(argc != 4)
				die("Provide the id.", conn);

			Database_get(conn, id);
			break;

		case 's':
			if(argc != 6)
				die("You need to provide id, name and email.", conn);

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4)
				die("You neeed to provide ID to delete the record.", conn);

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;

		default:
			die("Available actions are: c = create, g = get, s = set, d = delete, l = list.", conn);
	}

	Database_close(conn);

	return 0;
}






